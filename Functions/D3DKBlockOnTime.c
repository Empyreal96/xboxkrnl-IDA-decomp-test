// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::BlockOnTime(unsigned int Time, int MakeSpace)
{
  volatile unsigned int *v2; // eax
  unsigned int v3; // ecx
  D3DK::CDevice *v4; // ebx
  unsigned int *v5; // esi
  D3DK::CDevice *v6; // eax
  int *v7; // eax
  int v8; // edx
  int *v10; // esi
  int v11; // ecx
  unsigned __int64 v16; // rax
  unsigned int v17; // edi
  unsigned int v18; // edx
  int *v19; // edi
  unsigned __int64 v20; // [esp+8h] [ebp-1Ch]
  _LARGE_INTEGER timeOut; // [esp+10h] [ebp-14h]
  unsigned int dwDbgTimeCheck; // [esp+18h] [ebp-Ch]
  unsigned int newGap; // [esp+1Ch] [ebp-8h]
  unsigned int gap; // [esp+20h] [ebp-4h]

  v2 = D3DK::g_pDevice->m_pGpuTime;
  v3 = D3DK::g_pDevice->m_CpuTime;
  if ( *v2 == v3 || !*v2 || !v3 )
    D3DK::DXGRIP(
      (int *)D3DK::g_pDevice,
      "Assertion failure: %s",
      "(pDevice->GpuTime() != pDevice->m_CpuTime) && (pDevice->GpuTime() != 0) && (pDevice->m_CpuTime != 0)");
  if ( Time && D3DK::g_pDevice->m_CpuTime - Time < D3DK::g_pDevice->m_CpuTime - *D3DK::g_pDevice->m_pGpuTime )
  {
    if ( Time == D3DK::g_pDevice->m_CpuTime )
      D3DK::SetFence(0);
    if ( D3DK::g_PushState == 1 )
    {
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "Pusher - Attempting to block while pushing data to the push buffer, possibly because you are calling blocking/dr"
        "awing methods from multiple threads or a DPC.");
    }
    else if ( D3DK::g_PushState == 3 )
    {
      D3DK::DXGRIP(
        (int *)D3DK::g_pDevice,
        "Pusher - Attempting to block on a fence while a thread is already blocked, possibly because you are calling bloc"
        "king methods from multiple threads or a DPC.");
    }
    D3DK::g_PushState = 3;
    timeOut.QuadPart = -10000i64 * D3D__DeadlockTimeOutVal;
    newGap = Time;
    v4 = (D3DK::CDevice *)D3DK::FindFence((int *)D3DK::g_pDevice, Time);
    gap = (unsigned int)D3DK::ComputeGap(v4, (D3DK::Fence *)D3DK::g_pDevice, (int *)v4);
    if ( gap >= 0x8000 )
    {
      if ( *v4->m_Pusher.m_pThreshold != 269680 )
        D3DK::DXGRIP(
          (int *)D3DK::g_pDevice,
          "Assertion failure: %s",
          "targetFence->pEncoding->m_SemaphoreCommand == EncodeMethod(SUBCH_3D, NV097_BACK_END_WRITE_SEMAPHORE_RELEASE)");
      if ( v4->m_Pusher.m_pPut != (unsigned int *)v4->m_Pusher.m_pThreshold[1] )
        D3DK::DXGRIP(
          (int *)D3DK::g_pDevice,
          "Assertion failure: %s",
          "targetFence->Time == targetFence->pEncoding->m_Time");
      v5 = v4->m_Pusher.m_pThreshold;
      D3DK::g_pDevice->m_Miniport.m_BusyBlockEvent.Header.SignalState = 0;
      if ( !MakeSpace )
      {
        v5[2] = 262416;
        v5[3] = 0;
      }
      v5[4] = 262400;
      v5[5] = 784;
      D3DK::FlushWCCache();
      v7 = D3DK::ComputeGap(v6, (D3DK::Fence *)D3DK::g_pDevice, (int *)v4);
      newGap = (unsigned int)v7;
      if ( (unsigned int)v7 > gap )
      {
        D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "newGap <= gap");
        v7 = (int *)newGap;
      }
      if ( (unsigned int)v7 >= 0x8000 )
      {
        if ( KeWaitForSingleObject(
               (int)&timeOut,
               v8,
               &D3DK::g_pDevice->m_Miniport.m_BusyBlockEvent,
               UserRequest,
               1,
               0,
               &timeOut) )
        {
          do
            D3DK::DXGRIP((int *)D3DK::g_pDevice, "Possible deadlock");
          while ( KeWaitForSingleObject(
                    v11,
                    (int)&timeOut,
                    &D3DK::g_pDevice->m_Miniport.m_BusyBlockEvent,
                    UserRequest,
                    1,
                    0,
                    &timeOut) );
        }
        goto LABEL_43;
      }
      v5[2] = 262400;
      v5[3] = 0;
      v5[4] = 262400;
      v5[5] = 0;
      D3DK::FlushWCCache();
      newGap = (unsigned int)v4->m_Pusher.m_pPut;
    }
    ++D3DK::g_PerfCounters.m_PerformanceCounters[12].Count;
    if ( D3DK::g_PerfCounters.m_Breakperfctr == 12
      && D3DK::g_PerfCounters.m_PerformanceCounters[12].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
    {
      __debugbreak();
    }
    v20 = __rdtsc();
    dwDbgTimeCheck = KeTickCount;
    while ( 1 )
    {
      if ( !newGap )
        D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "Time != 0");
      _EAX = (D3DK::CDevice *)(D3DK::g_pDevice->m_CpuTime - newGap);
      if ( (unsigned int)_EAX >= D3DK::g_pDevice->m_CpuTime - *D3DK::g_pDevice->m_pGpuTime )
        break;
      v10 = D3DK::ComputeGap(_EAX, (D3DK::Fence *)D3DK::g_pDevice, (int *)v4);
      if ( (unsigned int)v10 > gap )
        D3DK::DXGRIP((int *)D3DK::g_pDevice, "Assertion failure: %s", "newerGap <= gap");
      gap = (unsigned int)v10;
      if ( KeTickCount - dwDbgTimeCheck > D3D__DeadlockTimeOutVal )
        RtlRip(0, 0, "Possible deadlock, blocked for more than 2 seconds.");
      if ( D3DK::g_DpcRIPFired )
      {
        RtlRip(0, 0, "Graphics processor error.");
        D3DK::g_DpcRIPFired = 0;
      }
    }
    __asm { cpuid }
    v16 = __rdtsc() - v20;
    D3DK::g_PerfCounters.m_PerformanceCounters[12].Cycles += v16;
    if ( D3DK::g_PerfCounters.m_pfnCycleThresholdHandler
      && D3DK::g_PerfCounters.m_DumpWaitCycleTimesThreshold < (unsigned int)v16 )
    {
      D3DK::g_PerfCounters.m_pfnCycleThresholdHandler(PERF_CPUSPINDURINGWAIT_TIME, v16);
    }
LABEL_43:
    if ( !MakeSpace )
    {
      v17 = D3DK::g_pDevice->m_CpuTime;
      v18 = v17 - *D3DK::g_pDevice->m_pGpuTime;
      v19 = (int *)(v17 - Time);
      if ( (unsigned int)v19 < v18 )
        D3DK::DXGRIP(v19, "Assertion failure: %s", "MakeSpace || !pDevice->IsTimePending(Time)");
    }
    D3DK::g_PushState = 0;
  }
}