// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_BlockUntilIdle()
{
  unsigned __int64 v0; // rax
  unsigned int v1; // edi
  unsigned int v2; // esi
  unsigned __int64 v8; // rax

  ++D3DK::g_PerfCounters.m_APICounters[17];
  ++D3DK::g_PerfCounters.m_PerformanceCounters[9].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 9
    && D3DK::g_PerfCounters.m_PerformanceCounters[9].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v0 = __rdtsc();
  v1 = HIDWORD(v0);
  v2 = v0;
  D3DK::KickOffAndWaitForIdle((int *)HIDWORD(v0));
  __asm { cpuid }
  v8 = __rdtsc() - __PAIR__(v1, v2);
  D3DK::g_PerfCounters.m_PerformanceCounters[9].Cycles += v8;
  if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler )
  {
    if ( D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v8 )
      D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_D3DDEVICE_BLOCKUNTILIDLE_WAITS, v8);
  }
}