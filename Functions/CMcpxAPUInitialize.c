int __userpurge CMcpxAPU::Initialize@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundSettings *pSettings)
{
  unsigned int ulInterruptVector; // ST28_4
  int v5; // ecx
  CMcpxAPU *thisa; // [esp+0h] [ebp-14h]
  int hr; // [esp+4h] [ebp-10h]
  char irql; // [esp+13h] [ebp-1h]

  thisa = this;
  hr = CMcpxCore::Initialize((CMcpxCore *)&this->vfptr, a2, a3, pSettings, 1);
  if ( hr >= 0 )
    hr = thisa->m_SgeHeap.vfptr->Initialize((CHeap<_SGEHEAPRUNMARKER> *)&thisa->m_SgeHeap.vfptr, 2047u);
  if ( hr >= 0 )
  {
    KeInitializeDpc(&thisa->m_dpcInterrupt, CMcpxAPU::ApuInterruptDpcRoutine, thisa);
    KeInitializeTimerEx(&thisa->m_tmrDeferredCommandsHigh, 0);
    KeInitializeDpc(&thisa->m_dpcDeferredCommandsHigh, CMcpxAPU::DeferredCommandDpcRoutine, thisa);
  }
  if ( hr >= 0 )
  {
    ulInterruptVector = HalGetInterruptVector(5u, &irql);
    LOBYTE(v5) = irql;
    KeInitializeInterrupt(
      ulInterruptVector,
      v5,
      a2,
      &CMcpxAPU::m_Interrupt,
      (char (__stdcall *)(_KINTERRUPT *, void *))CMcpxAPU::ApuInterruptServiceRoutine,
      thisa,
      ulInterruptVector,
      irql,
      0,
      1);
    if ( !KeConnectInterrupt(&CMcpxAPU::m_Interrupt) )
      hr = -2147467259;
  }
  if ( hr >= 0 )
    MEMORY[0xFE801000] = -1;
  if ( hr >= 0 )
    CMcpxCore::SetInterruptState(1);
  if ( hr >= 0 )
  {
    thisa->m_HalShutdownData.NotificationRoutine = (void (__stdcall *)(_HAL_SHUTDOWN_REGISTRATION *))CMcpxAPU::ApuShutdownNotifier;
    HalRegisterShutdownNotification(&thisa->m_HalShutdownData, 1);
  }
  if ( hr >= 0 )
    hr = CMcpxAPU::SetHRTFHeadroom(0);
  if ( hr >= 0 )
    hr = CMcpxAPU::SetMixBinHeadroom(0x7FFFFFFFu, 1u);
  if ( hr >= 0 )
    hr = CMcpxAPU::SetMixBinHeadroom(0x80000000, 0);
  return hr;
}