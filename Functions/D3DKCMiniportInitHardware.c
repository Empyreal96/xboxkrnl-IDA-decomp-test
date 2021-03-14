// write access to const memory has been detected, the output may be wrong!
int __usercall D3DK::CMiniport::InitHardware@<eax>(D3DK::CMiniport *this@<ecx>, int *a2@<edi>)
{
  D3DK::CMiniport *v2; // esi
  unsigned int v4; // eax
  int *v5; // edi
  int v6; // edx
  int v7; // ecx
  unsigned int v8; // eax
  char *v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // ecx
  float v13; // eax
  unsigned int v14; // eax
  unsigned int MPLLCoeff; // [esp+8h] [ebp-10h]
  int InterruptIrql; // [esp+Ch] [ebp-Ch]
  float XTAL; // [esp+10h] [ebp-8h]
  char *v18; // [esp+14h] [ebp-4h]

  v2 = this;
  KeInitializeDpc(&this->m_Dpc, (void (__stdcall *)(_KDPC *, void *, void *, void *))D3DK::CMiniport::Dpc, this);
  v2->m_BusyBlockEvent.Header.Type = 0;
  v2->m_VerticalBlankEvent.Header.Type = 0;
  v2->m_BusyBlockEvent.Header.WaitListHead.Blink = &v2->m_BusyBlockEvent.Header.WaitListHead;
  v2->m_BusyBlockEvent.Header.WaitListHead.Flink = &v2->m_BusyBlockEvent.Header.WaitListHead;
  v2->m_BusyBlockEvent.Header.Size = 4;
  v2->m_BusyBlockEvent.Header.SignalState = 1;
  v2->m_VerticalBlankEvent.Header.Size = 4;
  v2->m_VerticalBlankEvent.Header.SignalState = 1;
  v2->m_VerticalBlankEvent.Header.WaitListHead.Blink = &v2->m_VerticalBlankEvent.Header.WaitListHead;
  v2->m_VerticalBlankEvent.Header.WaitListHead.Flink = &v2->m_VerticalBlankEvent.Header.WaitListHead;
  if ( !D3DK::CMiniport::MapRegisters(v2) )
  {
    D3DK::DXGRIP(a2, "MP: Failed to map NV registers");
    return 0;
  }
  if ( !D3DK::CMiniport::GetGeneralInfo(v2) )
  {
    D3DK::DXGRIP(a2, "MP: Unable to get chip info");
    return 0;
  }
  v4 = HalGetInterruptVector(3u, (char *)&InterruptIrql);
  v5 = (int *)&v2->m_InterruptObject;
  KeInitializeInterrupt(
    v6,
    v7,
    (int *)&v2->m_InterruptObject,
    &v2->m_InterruptObject,
    (char (__stdcall *)(_KINTERRUPT *, void *))D3DK::CMiniport::Isr,
    v2,
    v4,
    InterruptIrql,
    0,
    1);
  if ( !KeConnectInterrupt(&v2->m_InterruptObject) )
  {
    D3DK::DXGRIP(v5, "MP: Unable to connect interrupt");
    return 0;
  }
  v2->m_ShutdownRegistration.Priority = 0;
  v2->m_ShutdownRegistration.NotificationRoutine = D3DK::CMiniport::ShutdownNotification;
  HalRegisterShutdownNotification(&v2->m_ShutdownRegistration, 1);
  if ( !D3DK::CMiniport::InitEngines(v2) )
  {
    D3DK::DXGRIP(v5, "MP: InitEngines failed");
    return 0;
  }
  v18 = v2->m_GammaRamp[0].green;
  LODWORD(XTAL) = 2;
  do
  {
    v8 = 0;
    do
    {
      v9 = &v18[v8];
      *(v9 - 256) = v8;
      *v9 = v8;
      v9[256] = v8++;
    }
    while ( v8 < 0x100 );
    v18 += 768;
    --LODWORD(XTAL);
  }
  while ( XTAL != 0.0 );
  __outbyte(0x80C0u, 1u);
  v2->m_InterruptsEnabled = 1;
  if ( !D3DK::CMiniport::LoadEngines(v2) )
  {
    D3DK::DXGRIP((int *)0x100, "MP: LoadEngines failed");
    return 0;
  }
  D3DK::CMiniport::DumpClocks(v2, v10);
  v13 = F_XTAL_166;
  if ( v2->m_GenInfo.CrystalFreq != 16666666 )
    v13 = F_XTAL_135;
  XTAL = v13;
  HalReadWritePCISpace(v12, v11, 0, 0x60u, 0x6Cu, &MPLLCoeff, 4u, 0);
  v14 = (unsigned __int8)MPLLCoeff;
  if ( (_BYTE)MPLLCoeff )
  {
    MPLLCoeff = (unsigned __int16)MPLLCoeff >> 8;
    D3DK::g_CpuCyclesPerMsec = 1000 * (unsigned __int64)(XTAL / (double)v14 * (double)MPLLCoeff * 5.5);
  }
  return 1;
}