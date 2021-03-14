// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DK::LazySetPointParams(D3DK::CDevice *pDevice)
{
  int *v1; // edi
  unsigned int *v2; // esi
  double v3; // st7
  float f; // ST0C_4
  unsigned int v5; // eax
  float delta; // [esp+20h] [ebp-8h]
  float size; // [esp+30h] [ebp+8h]

  v1 = (int *)pDevice;
  v1[2] &= 0xFFFFFFFE;
  ++D3DK::g_PerfCounters.m_PerformanceCounters[23].Count;
  if ( D3DK::g_PerfCounters.m_Breakperfctr == 23
    && D3DK::g_PerfCounters.m_PerformanceCounters[23].Count + 1 == D3DK::g_PerfCounters.m_BreakCount )
  {
    __debugbreak();
  }
  delta = 0.0;
  v2 = XMETAL_StartPush((int *)pDevice, &pDevice->m_Pusher);
  if ( 0.0 >= 0.0 )
  {
    D3DK::DXGRIP((int *)pDevice, "D3DRS_POINTSIZE_MIN must be less than D3DRS_POINTSIZE_MAX");
    delta = 0.0 + 0.001;
  }
  v3 = 0.0 * pDevice->m_SuperSampleScale;
  size = v3;
  if ( v3 < 0.0 )
    size = 0.0;
  if ( size > (double)delta )
    size = delta;
  if ( size > 64.0 )
    size = 64.0;
  XMETAL_Push2f(v1, v2, 0x318u, 0.0, 0.0);
  f = size * 8.0 + 0.5;
  v5 = D3DK::FloatToLong(f);
  if ( v5 > 0x1FF )
    v5 = 511;
  XMETAL_Push1f(v1, v2 + 3, 0x43Cu, *(float *)&v5);
  XMETAL_EndPush(v1, (_XMETAL_PushBuffer *)v1, v2 + 5);
}