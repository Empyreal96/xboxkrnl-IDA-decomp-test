// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_VertexBlend(unsigned int Value)
{
  int *v1; // edi
  int *v2; // edi

  ++D3DK::g_PerfCounters.m_APICounters[153];
  v1 = (int *)(D3DK::g_pDevice->m_DirtyFlags | 2);
  D3DK::g_pDevice->m_DirtyFlags = (unsigned int)v1;
  v2 = (int *)XMETAL_StartPush(v1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v2, (unsigned int *)v2, 0x328u, *(float *)&Value);
  XMETAL_EndPush(v2 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v2 + 2);
  dword_800C259C = Value;
}