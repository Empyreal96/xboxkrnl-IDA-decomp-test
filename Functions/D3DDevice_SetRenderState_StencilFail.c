// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_StencilFail(unsigned int Value)
{
  unsigned int *v1; // esi

  ++D3DK::g_PerfCounters.m_APICounters[150];
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x1D84u, 0.0);
  v1 += 2;
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x370u, *(float *)&Value);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v1 + 2);
  dword_800C25BC = Value;
}