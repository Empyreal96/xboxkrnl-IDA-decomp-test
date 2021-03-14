// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_LineWidth(unsigned int Value)
{
  float f; // ST08_4
  int *v2; // edi
  unsigned int *v3; // ebx

  ++D3DK::g_PerfCounters.m_APICounters[135];
  f = *(float *)&Value * D3DK::g_pDevice->m_SuperSampleScale * 8.0 + 0.5;
  v2 = (int *)D3DK::FloatToLong(f);
  if ( (unsigned int)v2 > 0x1FF )
    v2 = (int *)511;
  v3 = XMETAL_StartPush(v2, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v2, v3, 0x380u, *(float *)&v2);
  XMETAL_EndPush(v2, &D3DK::g_pDevice->m_Pusher, v3 + 2);
  dword_800C25E8 = Value;
}