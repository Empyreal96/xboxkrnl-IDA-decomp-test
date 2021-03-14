// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::BlockOnResource(D3DResource *pResource)
{
  D3DResource *v1; // eax
  D3DResource *v2; // esi
  unsigned __int64 v3; // rax
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned __int64 v11; // rax
  unsigned int v12; // ebx
  BOOL v13; // eax
  unsigned __int64 v14; // rax
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rax
  unsigned __int64 v29; // rax

  if ( !D3DK::g_pDevice )
    return;
  v1 = pResource;
  if ( (pResource->Common & 0x70000) == 327680 )
  {
    v2 = (D3DResource *)pResource[1].Lock;
    if ( v2 )
    {
      if ( D3DK::IsResourceSetInDevice(pResource) )
      {
        ++D3DK::g_PerfCounters.m_PerformanceCounters[7].Count;
        if ( D3DK::g_PerfCounters.m_Breakperfctr == 7
          && D3DK::g_PerfCounters.m_PerformanceCounters[7].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
        {
          __debugbreak();
        }
        v3 = __rdtsc();
        v4 = HIDWORD(v3);
        v5 = v3;
        D3DK::KickOffAndWaitForIdle((int *)HIDWORD(v3));
        __asm { cpuid }
        v11 = __rdtsc() - __PAIR__(v4, v5);
        D3DK::g_PerfCounters.m_PerformanceCounters[7].Cycles += v11;
        if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler )
        {
          if ( D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v11 )
            D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_OBJECTLOCK_WAITS, v11);
        }
        return;
      }
      pResource = v2;
      v1 = v2;
    }
  }
  v12 = v1->Lock;
  v13 = D3DK::IsResourceSetInDevice(v1);
  ++D3DK::g_PerfCounters.m_PerformanceCounters[7].Count;
  if ( v13 )
  {
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 7
      && D3DK::g_PerfCounters.m_PerformanceCounters[7].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
    v14 = __rdtsc();
    v15 = HIDWORD(v14);
    v16 = v14;
    D3DK::KickOffAndWaitForIdle((int *)HIDWORD(v14));
    __asm { cpuid }
    v22 = __rdtsc();
  }
  else
  {
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 7
      && D3DK::g_PerfCounters.m_PerformanceCounters[7].Count == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
    v23 = __rdtsc();
    v15 = HIDWORD(v23);
    v16 = v23;
    D3DK::BlockOnTime(v12, 0);
    __asm { cpuid }
    v22 = __rdtsc();
  }
  v29 = v22 - __PAIR__(v15, v16);
  D3DK::g_PerfCounters.m_PerformanceCounters[7].Cycles += v29;
  if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler
    && D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v29 )
  {
    D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_OBJECTLOCK_WAITS, v29);
  }
  pResource->Lock = 0;
}