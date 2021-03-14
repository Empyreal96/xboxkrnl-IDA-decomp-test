// write access to const memory has been detected, the output may be wrong!
unsigned __int64 __usercall D3DPERF_Reset@<edx:eax>(int *a1@<edi>)
{
  unsigned int *v1; // edx
  _D3DRENDERSTATETYPE v2; // esi
  _DWORD *v3; // esi
  unsigned __int64 result; // rax

  if ( D3DK::g_pDevice->m_StateFlags & 4 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "!(g_pDevice->m_StateFlags & STATE_RECORDPUSHBUFFER)");
  memset(D3DK::g_PerfCounters.m_PerformanceCounters, 0, sizeof(D3DK::g_PerfCounters.m_PerformanceCounters));
  memset(D3DK::g_PerfCounters.m_APICounters, 0, sizeof(D3DK::g_PerfCounters.m_APICounters));
  memset(D3DK::g_PerfCounters.m_RenderStateCounters, 0, sizeof(D3DK::g_PerfCounters.m_RenderStateCounters));
  memset(D3DK::g_PerfCounters.m_TextureStateCounters, 0, sizeof(D3DK::g_PerfCounters.m_TextureStateCounters));
  v1 = g_pPushBuffer->m_pPut;
  LODWORD(D3DK::g_PerfCounters.m_FrameTimeMin.Cycles) = -1;
  HIDWORD(D3DK::g_PerfCounters.m_FrameTimeMin.Cycles) = D3DK::g_PerfCounters.m_FrameTimeMin.Cycles;
  D3DK::g_PerfCounters.m_pPutLocationAtReset = v1;
  D3DK::g_PerfCounters.m_PushBufferEndDwordsSkipped = 0i64;
  qmemcpy(&D3DK::g_rcbAtReset, &thread, sizeof(D3DK::g_rcbAtReset));
  D3DK::g_PerfCounters.m_FrameTimeMin.Count = 0;
  D3DK::g_PerfCounters.m_FrameTimeMax.Count = 0;
  D3DK::g_PerfCounters.m_FrameTimeMax.Cycles = 0i64;
  D3DK::g_PerfCounters.m_TSCLastPresentVal = 0i64;
  if ( D3DK::g_PerfCounters.m_SetRenderStateOverridesOnReset )
  {
    v2 = 0;
    do
    {
      if ( *(_DWORD *)(8 * v2 - 2146703836) )
        D3DDevice_SetRenderStateNotInline(v2, *(_DWORD *)(8 * v2 - 2146703832));
      ++v2;
    }
    while ( (signed int)v2 < 144 );
    D3DK::g_PerfCounters.m_SetRenderStateOverridesOnReset = 0;
  }
  if ( g_ToggleVTXStatesOnReset )
  {
    v3 = D3DK::g_pDevice->m_Miniport.m_RegisterBase;
    D3DDevice_BlockUntilIdle();
    v3[1048609] ^= 0x600u;
    g_ToggleVTXStatesOnReset = 0;
  }
  result = __rdtsc();
  D3DK::g_PerfCounters.m_TSCLastResetVal = result;
  return result;
}