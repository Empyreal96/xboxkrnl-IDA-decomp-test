// write access to const memory has been detected, the output may be wrong!
int __usercall D3DPERF_HandlePresent@<eax>(int *a1@<edi>)
{
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // rax

  LODWORD(v1) = D3DK::g_PerfCounters.m_FrameRateIntervalTime;
  if ( D3DK::g_PerfCounters.m_FrameRateIntervalTime )
  {
    v2 = __rdtsc();
    if ( D3DK::g_PerfCounters.m_TSCLastPresentVal )
    {
      if ( v2 - D3DK::g_PerfCounters.m_TSCLastPresentVal < D3DK::g_PerfCounters.m_FrameTimeMin.Cycles )
      {
        D3DK::g_PerfCounters.m_FrameTimeMin.Cycles = v2 - D3DK::g_PerfCounters.m_TSCLastPresentVal;
        D3DK::g_PerfCounters.m_FrameTimeMin.Count = D3DK::g_PerfCounters.m_APICounters[107];
      }
      if ( v2 - D3DK::g_PerfCounters.m_TSCLastPresentVal > D3DK::g_PerfCounters.m_FrameTimeMax.Cycles )
      {
        D3DK::g_PerfCounters.m_FrameTimeMax.Cycles = v2 - D3DK::g_PerfCounters.m_TSCLastPresentVal;
        D3DK::g_PerfCounters.m_FrameTimeMax.Count = D3DK::g_PerfCounters.m_APICounters[107];
      }
    }
    D3DK::g_PerfCounters.m_TSCLastPresentVal = v2;
    v1 = (v2 - D3DK::g_PerfCounters.m_TSCLastResetVal) / D3DK::g_CpuCyclesPerMsec;
    if ( (unsigned int)v1 > D3DK::g_PerfCounters.m_FrameRateIntervalTime )
    {
      if ( D3DK::g_PerfCounters.m_pfnDumpFrameRateInfoHandler )
        D3DK::g_PerfCounters.m_pfnDumpFrameRateInfoHandler();
      LODWORD(v1) = D3DPERF_Reset(a1);
    }
  }
  return v1;
}