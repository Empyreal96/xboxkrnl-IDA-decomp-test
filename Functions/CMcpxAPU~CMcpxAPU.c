// write access to const memory has been detected, the output may be wrong!
void __usercall CMcpxAPU::~CMcpxAPU(CMcpxAPU *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // ecx
  CMcpxAPU *thisa; // [esp+4h] [ebp-4h]

  thisa = this;
  this->vfptr = (CRefCountVtbl *)&CMcpxAPU::`vftable'{for `CRefCount'};
  this->vfptr = (CMcpxCoreVtbl *)&CMcpxAPU::`vftable'{for `CMcpxCore'};
  CMcpxAPU::Terminate(this, a2);
  if ( CMcpxAPU::m_Interrupt.ServiceRoutine )
  {
    KeDisconnectInterrupt(&CMcpxAPU::m_Interrupt);
    CMcpxAPU::m_Interrupt.ServiceRoutine = 0;
  }
  KeCancelTimer(v3, (int)&thisa->m_tmrDeferredCommandsHigh, &thisa->m_tmrDeferredCommandsHigh);
  if ( thisa->m_dpcInterrupt.Type == 19 )
  {
    KeRemoveQueueDpc((int)&thisa->m_dpcInterrupt, 19, a2, &thisa->m_dpcInterrupt);
    thisa->m_dpcInterrupt.Type = ~thisa->m_dpcInterrupt.Type;
  }
  if ( thisa->m_dpcDeferredCommandsHigh.Type == 19 )
  {
    KeRemoveQueueDpc((int)&thisa->m_dpcDeferredCommandsHigh, 19, a2, &thisa->m_dpcDeferredCommandsHigh);
    thisa->m_dpcDeferredCommandsHigh.Type = ~thisa->m_dpcInterrupt.Type;
  }
  if ( thisa->m_HalShutdownData.NotificationRoutine )
  {
    HalRegisterShutdownNotification(&thisa->m_HalShutdownData, 0);
    thisa->m_HalShutdownData.NotificationRoutine = 0;
  }
  CMcpxBufferSgeHeap::~CMcpxBufferSgeHeap(&thisa->m_SgeHeap, a2);
  if ( thisa )
    CMcpxCore::~CMcpxCore((CMcpxCore *)&thisa->vfptr, a2, a3);
  else
    CMcpxCore::~CMcpxCore(0, a2, a3);
  CRefCount::~CRefCount((CRefCount *)&thisa->vfptr);
}