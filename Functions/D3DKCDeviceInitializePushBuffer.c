// write access to const memory has been detected, the output may be wrong!
void __usercall D3DK::CDevice::InitializePushBuffer(D3DK::CDevice *this@<ecx>, int *a2@<edi>)
{
  unsigned int *v2; // eax
  volatile unsigned int *v3; // edx

  D3DK::CDevice::m_PushSegmentSize = D3DK::CDevice::m_PushBufferSize >> 4;
  v2 = this->m_pPushBase;
  this->m_Pusher.m_pPut = v2;
  v3 = this->m_pGpuTime;
  this->m_Pusher.m_pThreshold = &v2[(D3DK::CDevice::m_PushSegmentSize >> 2) - 129];
  this->m_CpuTime = 5;
  *v3 = 3;
  this->m_LastRunPushBufferTime = 3;
  if ( D3DK::CDevice::m_PushBufferSize / 0x18 >= 0x80000000 )
    D3DK::DXGRIP(
      a2,
      "Assertion failure: %s",
      "m_PushBufferSize / sizeof(FenceEncoding) < (1 << (32 - PUSHER_TIME_SHIFT))");
}