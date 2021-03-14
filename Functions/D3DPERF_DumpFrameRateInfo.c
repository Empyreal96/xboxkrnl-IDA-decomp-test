int __usercall D3DPERF_DumpFrameRateInfo@<eax>(int *a1@<edi>)
{
  unsigned int v1; // ebx
  int v2; // esi
  int v3; // edi
  unsigned __int64 v4; // rax
  int v5; // ST20_4
  unsigned int v6; // ebx
  int *v7; // edi
  unsigned int v8; // ecx
  int v9; // eax
  unsigned int v10; // esi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  int result; // eax
  int *v14; // [esp-Ch] [ebp-4Ch]
  _MM_STATISTICS mmStatistics; // [esp+0h] [ebp-40h]
  D3DK::PERFFIXEDPOINT WaitTimePerWait; // [esp+24h] [ebp-1Ch]
  D3DK::PERFFIXEDPOINT WaitTime; // [esp+2Ch] [ebp-14h]
  unsigned int v18; // [esp+34h] [ebp-Ch]
  unsigned int v19; // [esp+38h] [ebp-8h]
  unsigned int frames; // [esp+3Ch] [ebp-4h]

  if ( unk_8004C824 )
    (*(void (__stdcall **)(signed int, _DWORD))(unk_8004C824 + 20))(5, 0);
  v14 = a1;
  v1 = (__rdtsc() - D3DK::g_PerfCounters.m_TSCLastResetVal) / D3DK::g_CpuCyclesPerMsec;
  frames = D3DK::g_PerfCounters.m_APICounters[107];
  WaitTime.IntPart = (unsigned __int64)(10000i64 * D3DK::g_PerfCounters.m_APICounters[107] / v1) / 0xA;
  v2 = (unsigned __int64)(10000i64 * D3DK::g_PerfCounters.m_APICounters[107] / v1) % 0xA;
  v3 = 10i64 * v1 / D3DK::g_PerfCounters.m_APICounters[107];
  v4 = (unsigned __int64)(10i64 * v1 / D3DK::g_PerfCounters.m_APICounters[107]) / 0xA;
  v5 = v1;
  v6 = D3DK::g_PerfCounters.m_APICounters[107];
  DbgPrint(
    (int *)(v3 - 10 * v4),
    "fps: %Lu.%Lu (%Lu.%Lu ms/frame)  frames: %Lu  time: %Lums\n",
    WaitTime.IntPart,
    v2,
    (_DWORD)v4,
    v3 - 10 * (_DWORD)v4,
    D3DK::g_PerfCounters.m_APICounters[107],
    v5);
  v7 = 0;
  DbgPrint(
    0,
    "Min/max frame times:  frame #%Lu=%Lums  frame #%Lu=%Lums\n",
    D3DK::g_PerfCounters.m_FrameTimeMin.Count,
    (unsigned int)(D3DK::g_PerfCounters.m_FrameTimeMin.Cycles / D3DK::g_CpuCyclesPerMsec),
    D3DK::g_PerfCounters.m_FrameTimeMax.Count,
    (unsigned int)(D3DK::g_PerfCounters.m_FrameTimeMax.Cycles / D3DK::g_CpuCyclesPerMsec));
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 8 )
  {
    v8 = 0;
    v19 = 0;
    do
    {
      v9 = *(D3DK::_D3DPERF_PerformanceCounters *)((char *)EventList + v8);
      v18 = D3DK::g_PerfCounters.m_PerformanceCounters[v9].Count;
      v7 = (int *)v18;
      if ( v18 )
      {
        v10 = 10
            * __PAIR__(
                HIDWORD(D3DK::g_PerfCounters.m_PerformanceCounters[v9].Cycles),
                D3DK::g_PerfCounters.m_PerformanceCounters[v9].Cycles)
            / D3DK::g_CpuCyclesPerMsec;
        WaitTime.IntPart = v10 / 0xA;
        WaitTime.DecPart = v10 % 0xA;
        v11 = v10 / (unsigned __int64)v18;
        WaitTimePerWait.IntPart = v11 / 0xA;
        v7 = (int *)(v11 % 0xA);
        DbgPrint(
          v7,
          "%s (%Lu): %Lu.%Lums (%Lu.%Lums/wait %Lu.%Lums/frame)\n",
          *(_DWORD *)(4 * *(D3DK::_D3DPERF_PerformanceCounters *)((char *)EventList + v19) - 2146939624),
          v18,
          v10 / 0xA,
          v10 % 0xA,
          WaitTimePerWait.IntPart,
          v7,
          (unsigned int)(v10 / (unsigned __int64)frames / 0xA),
          (unsigned int)(v10 / (unsigned __int64)frames % 0xA));
        v8 = v19;
        v6 = frames;
      }
      v8 += 4;
      v19 = v8;
    }
    while ( v8 < 0x1C );
  }
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 0x20 )
  {
    DbgPrint(
      v7,
      "Vertices processed: %Lu verts (%Lu verts/frame)\n",
      D3DK::g_PerfCounters.m_PerformanceCounters[0].Count,
      D3DK::g_PerfCounters.m_PerformanceCounters[0].Count / v6);
    if ( D3DK::g_PerfCounters.m_PerformanceCounters[15].Count )
      DbgPrint(v7, " --> Doesn't include vertices processed via RunPushBuffer!\n");
  }
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 4 )
  {
    v12 = D3DPERF_GetPushBufferBytesWritten(v7);
    v7 = (int *)HIDWORD(v12);
    DbgPrint(v7, "PushBuffer writes: %I64u bytes (%I64u bytes/frame)\n", (_DWORD)v12, v7, v12 / v6);
    if ( D3DK::g_PerfCounters.m_PerformanceCounters[15].Count )
      DbgPrint(
        v7,
        "RunPushBuffer bytes traversed: %Lu bytes (%Lu bytes/frame)\n",
        D3DK::g_PerfCounters.m_PerformanceCounters[15].Count,
        D3DK::g_PerfCounters.m_PerformanceCounters[15].Count / v6);
  }
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 2 )
  {
    mmStatistics.Length = 36;
    memset(&mmStatistics.TotalPhysicalPages, 0, 0x20u);
    v7 = (int *)&WaitTimePerWait;
    MmQueryStatistics(&mmStatistics);
    DbgPrint((int *)&WaitTimePerWait, "Available RAM: %Lu kbytes\n", 4 * mmStatistics.AvailablePages);
  }
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 1 )
    DbgPrint(
      v7,
      "Interrupts: %Lu\nContext Switches: %Lu\n",
      unk_8004C5E4 - D3DK::g_rcbAtReset.InterruptCount,
      unk_8004C5F4 - D3DK::g_rcbAtReset.KeContextSwitches);
  if ( D3DK::g_PerfCounters.m_dwDumpFPSInfoMask & 0x10 )
    D3DPERF_DumpPerfProfCounts(v14);
  DbgPrint(v14, "\n");
  result = unk_8004C824;
  if ( unk_8004C824 )
    result = (*(int (__stdcall **)(signed int, D3DK::_D3DPERF *))(unk_8004C824 + 20))(5, &D3DK::g_PerfCounters);
  return result;
}