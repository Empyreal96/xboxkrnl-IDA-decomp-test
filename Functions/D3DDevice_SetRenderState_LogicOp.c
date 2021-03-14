// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_LogicOp(unsigned int Value)
{
  unsigned int *v1; // eax
  unsigned int *v2; // esi

  ++D3DK::g_PerfCounters.m_APICounters[136];
  v1 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  v2 = v1;
  if ( Value )
  {
    XMETAL_Push2f((int *)D3DK::g_pDevice, v1, 0x17BCu, COERCE_FLOAT(1), *(float *)&Value);
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 3);
  }
  else
  {
    XMETAL_Push1f((int *)D3DK::g_pDevice, v1, 0x17BCu, 0.0);
    XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 2);
  }
  dword_800C25D0 = Value;
}