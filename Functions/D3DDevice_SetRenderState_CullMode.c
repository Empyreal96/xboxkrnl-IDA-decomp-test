// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_CullMode(unsigned int Value)
{
  unsigned int *v1; // eax
  unsigned int *v2; // esi

  ++D3DK::g_PerfCounters.m_APICounters[127];
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  v2 = v1;
  if ( Value )
  {
    XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x308u, COERCE_FLOAT(1));
    XMETAL_Push1f((int *)D3DK::g_pDevice, v2 + 2, 0x39Cu, COERCE_FLOAT((Value != 0) + 1028));
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 4);
  }
  else
  {
    XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x308u, 0.0);
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 2);
  }
  ::Value = Value;
}