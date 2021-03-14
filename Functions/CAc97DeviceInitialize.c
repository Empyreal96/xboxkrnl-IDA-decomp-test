int __userpurge CAc97Device::Initialize@<eax>(CAc97Device *this@<ecx>, int *a2@<edi>, unsigned int dwFlags)
{
  int v3; // ecx
  CAc97Device *thisa; // [esp+0h] [ebp-14h]
  signed int hr; // [esp+4h] [ebp-10h]
  char Irql; // [esp+Bh] [ebp-9h]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int ulInterruptVector; // [esp+10h] [ebp-4h]

  thisa = this;
  hr = 0;
  this->m_dwFlags = dwFlags;
  if ( !CAc97Device::CodecReady() )
    hr = -2005401480;
  if ( hr >= 0 )
    hr = CAc97Device::PowerUp();
  if ( hr >= 0 )
  {
    for ( i = 0; i < 2; ++i )
      CAc97Device::PokeAciRegister8(*(_DWORD *)(4 * i - 2146508060) + 11, 2);
  }
  if ( hr >= 0 && !(thisa->m_dwFlags & 1) )
    KeInitializeDpc(&thisa->m_dpc, CAc97Device::AciInterruptDpcHandler, thisa);
  if ( hr >= 0 )
  {
    ulInterruptVector = HalGetInterruptVector(6u, &Irql);
    LOBYTE(v3) = Irql;
    KeInitializeInterrupt(
      ulInterruptVector,
      v3,
      a2,
      &CAc97Device::m_Interrupt,
      (char (__stdcall *)(_KINTERRUPT *, void *))CAc97Device::AciInterruptServiceRoutine,
      thisa,
      ulInterruptVector,
      Irql,
      0,
      1);
    if ( !KeConnectInterrupt(&CAc97Device::m_Interrupt) )
      hr = -2147467259;
  }
  if ( hr >= 0 && !CAc97Device::PokeAc97Register(AC97REG_FRONT_VOLUME, 0) )
    hr = -2147467259;
  if ( hr >= 0 && !CAc97Device::PokeAc97Register(AC97REG_PCM_OUT_VOLUME, 0x808u) )
    hr = -2147467259;
  if ( hr >= 0 )
  {
    thisa->m_HalShutdownData.NotificationRoutine = (void (__stdcall *)(_HAL_SHUTDOWN_REGISTRATION *))CAc97Device::AciShutdownNotifier;
    HalRegisterShutdownNotification(&thisa->m_HalShutdownData, 1);
  }
  return hr;
}