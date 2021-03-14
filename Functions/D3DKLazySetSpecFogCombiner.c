// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::LazySetSpecFogCombiner(int *a1@<edi>, D3DK::CDevice *pDevice)
{
  D3DK::CDevice *v2; // eax
  int *v3; // edi

  v2 = (D3DK::CDevice *)D3DK::g_PerfCounters.m_Breakperfctr;
  ++D3DK::g_PerfCounters.m_PerformanceCounters[26].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 26 )
  {
    v2 = (D3DK::CDevice *)(D3DK::g_PerfCounters.m_PerformanceCounters[26].Count + 1);
    if ( D3DK::g_PerfCounters.m_PerformanceCounters[26].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
      __debugbreak();
  }
  pDevice->m_DirtyFlags &= 0xFFFFFFBF;
  D3DK::CommonSetPassthroughProgram(v2, (int *)pDevice);
  v3 = (int *)XMETAL_StartPush(a1, &pDevice->m_Pusher);
  XMETAL_Push1f(v3, (unsigned int *)v3, 0x2A4u, 0.0);
  if ( pDevice->m_pPixelShader && pDevice->m_ShaderUsesSpecFog )
  {
    XMETAL_EndPush(v3 + 2, &pDevice->m_Pusher, (unsigned int *)v3 + 2);
  }
  else
  {
    XMETAL_Push2f(v3, (unsigned int *)v3 + 2, 0x288u, COERCE_FLOAT(12), COERCE_FLOAT(7296));
    XMETAL_EndPush(v3 + 5, &pDevice->m_Pusher, (unsigned int *)v3 + 5);
  }
}