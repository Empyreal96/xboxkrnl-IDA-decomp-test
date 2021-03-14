// write access to const memory has been detected, the output may be wrong!
void __usercall CAc97Device::Terminate(CAc97Device *this@<ecx>, int *a2@<edi>)
{
  CAc97Device *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( CAc97Device::m_Interrupt.ServiceRoutine )
  {
    KeDisconnectInterrupt(&CAc97Device::m_Interrupt);
    CAc97Device::m_Interrupt.ServiceRoutine = 0;
  }
  if ( thisa->m_dpc.Type == 19 )
  {
    KeRemoveQueueDpc((int)&thisa->m_dpc, 19, a2, &thisa->m_dpc);
    thisa->m_dpc.Type = ~thisa->m_dpc.Type;
  }
  if ( thisa->m_HalShutdownData.NotificationRoutine )
  {
    HalRegisterShutdownNotification(&thisa->m_HalShutdownData, 0);
    thisa->m_HalShutdownData.NotificationRoutine = 0;
  }
  for ( i = 0; i < 2; ++i )
    CAc97Device::ReleaseChannel(thisa, a2, (AC97CHANNELTYPE)i);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}