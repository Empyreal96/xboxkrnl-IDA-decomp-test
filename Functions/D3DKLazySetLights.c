// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DK::LazySetLights(int *a1@<edi>, D3DK::CDevice *pDevice)
{
  bool v2; // zf
  unsigned int *v9; // esi
  unsigned int lightNum; // [esp+38h] [ebp-8h]

  ++D3DK::g_PerfCounters.m_PerformanceCounters[28].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 28
    && D3DK::g_PerfCounters.m_PerformanceCounters[28].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  pDevice->m_DirtyFlags &= 0xFFFFFFDF;
  v2 = (pDevice->m_StateFlags & 0x40) == 0;
  lightNum = 0;
  if ( !v2 )
    lightNum = 1;
  v9 = XMETAL_StartPush(a1, &pDevice->m_Pusher);
  XMETAL_Push1f(a1, v9, 0x314u, 0.0);
  XMETAL_Push1f(a1, v9 + 2, 0x3B8u, *(float *)&lightNum);
  XMETAL_Push1f(a1, v9 + 4, 0x294u, COERCE_FLOAT(131073));
  XMETAL_Push1f(a1, v9 + 6, 0x17C4u, 0.0);
  XMETAL_EndPush(a1, &pDevice->m_Pusher, v9 + 8);
}