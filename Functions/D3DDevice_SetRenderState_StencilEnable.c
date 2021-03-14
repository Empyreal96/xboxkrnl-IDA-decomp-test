// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_StencilEnable(unsigned int Value)
{
  unsigned int *v1; // esi
  unsigned int *v2; // esi
  BOOL v3; // eax

  ++D3DK::g_PerfCounters.m_APICounters[149];
  if ( Value )
    D3DK::g_StencilEverEnabled = 1;
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x1D84u, 0.0);
  v2 = v1 + 2;
  v3 = Value && D3DK::g_pDevice->m_pZBuffer;
  XMETAL_Push1f((int *)D3DK::g_pDevice, v2, 0x32Cu, *(float *)&v3);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 2);
  dword_800C25B8 = Value;
}