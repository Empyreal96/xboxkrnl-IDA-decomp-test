void __stdcall D3DPERF_DumpCounterCycleInfo(D3DK::_D3DPERF_PerformanceCounters perfctr, unsigned __int64 Cycles)
{
  if ( perfctr == 7 )
    DbgPrint(
      (int *)Cycles,
      "#%Lu) %s %I64u cycles (%Lums)\n",
      D3DK::g_PerfCounters.m_PerformanceCounters[7].Count,
      g_PerfNames.m_PerformanceCounterNames[7],
      Cycles,
      (unsigned int)(Cycles / D3DK::g_CpuCyclesPerMsec));
}