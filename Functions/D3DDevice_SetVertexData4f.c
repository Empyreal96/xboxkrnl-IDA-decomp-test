// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetVertexData4f(int *a1@<edi>, int Register, float a, float b, float c, float d)
{
  unsigned int *v6; // ebx
  unsigned int v7; // eax

  ++D3DK::g_PerfCounters.m_APICounters[175];
  D3DK::g_PerfCounters.m_PerformanceCounters[0].Count += Register == -1;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == PERF_VERTICES
    && D3DK::g_PerfCounters.m_PerformanceCounters[0].Count < D3DK::g_PerfCounters.m_BreakCount
    && (Register == -1) + D3DK::g_PerfCounters.m_PerformanceCounters[0].Count >= D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  if ( Register < -1 || Register > 15 )
    D3DK::DXGRIP(a1, "Invalid register");
  v6 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  if ( Register == -1 )
    v7 = 5400;
  else
    v7 = 16 * (Register + 416);
  XMETAL_Push4f((int *)D3DK::g_pDevice, v6, v7, a, b, c, d);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v6 + 5);
}