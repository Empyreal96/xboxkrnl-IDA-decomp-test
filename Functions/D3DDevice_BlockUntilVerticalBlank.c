// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_BlockUntilVerticalBlank()
{
  unsigned __int64 v0; // rax
  int *v1; // edi
  int v3; // edx
  unsigned __int64 v8; // rax
  unsigned int v9; // [esp+4h] [ebp-Ch]
  _LARGE_INTEGER TimeOut; // [esp+8h] [ebp-8h]

  ++D3DK::g_PerfCounters.m_APICounters[18];
  ++D3DK::g_PerfCounters.m_PerformanceCounters[10].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 10
    && D3DK::g_PerfCounters.m_PerformanceCounters[10].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  v0 = __rdtsc();
  D3DK::g_pDevice->m_Miniport.m_VerticalBlankEvent.Header.SignalState = 0;
  v9 = HIDWORD(v0);
  v1 = (int *)v0;
  TimeOut.QuadPart = -10000i64 * D3D__DeadlockTimeOutVal;
  for ( _EAX = KeWaitForSingleObject(
                 D3D__DeadlockTimeOutVal,
                 (int)&TimeOut,
                 &D3DK::g_pDevice->m_Miniport.m_VerticalBlankEvent,
                 UserRequest,
                 1,
                 0,
                 &TimeOut);
        _EAX == (int *)258;
        _EAX = KeWaitForSingleObject(
                 (int)&TimeOut,
                 v3,
                 &D3DK::g_pDevice->m_Miniport.m_VerticalBlankEvent,
                 UserRequest,
                 1,
                 0,
                 &TimeOut) )
  {
    D3DK::DXGRIP(v1, "Possible deadlock, blocked for more than %d ms.", D3D__DeadlockTimeOutVal);
  }
  __asm { cpuid }
  v8 = __rdtsc() - __PAIR__(v9, (unsigned int)v1);
  D3DK::g_PerfCounters.m_PerformanceCounters[10].Cycles += v8;
  if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler )
  {
    if ( D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v8 )
      D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_D3DDEVICE_BLOCKUNTILVERTICALBLANK_WAITS, v8);
  }
}