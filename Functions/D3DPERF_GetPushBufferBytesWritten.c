unsigned __int64 __usercall D3DPERF_GetPushBufferBytesWritten@<edx:eax>(int *a1@<edi>)
{
  D3DK::CDevice *v1; // ecx

  v1 = D3DK::g_pDevice;
  if ( D3DK::g_pDevice->m_StateFlags & 4 )
  {
    D3DK::DXGRIP(a1, "Assertion failure: %s", "!(g_pDevice->m_StateFlags & STATE_RECORDPUSHBUFFER)");
    v1 = D3DK::g_pDevice;
  }
  if ( D3DK::g_PerfCounters.m_PerformanceCounters[14].Count )
    return D3DK::CDevice::m_PushBufferSize * (D3DK::g_PerfCounters.m_PerformanceCounters[14].Count - 1)
         + (signed __int64)(unsigned int *)((char *)g_pPushBuffer->m_pPut
                                          + (char *)v1->m_pPushLimit
                                          - (char *)v1->m_pPushBase
                                          - (unsigned int)D3DK::g_PerfCounters.m_pPutLocationAtReset)
         - 4 * D3DK::g_PerfCounters.m_PushBufferEndDwordsSkipped;
  if ( D3DK::g_PerfCounters.m_PushBufferEndDwordsSkipped )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "!g_PerfCounters.m_PushBufferEndDwordsSkipped");
  return (char *)g_pPushBuffer->m_pPut - (char *)D3DK::g_PerfCounters.m_pPutLocationAtReset;
}