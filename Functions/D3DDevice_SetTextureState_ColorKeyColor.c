// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTextureState_ColorKeyColor(unsigned int Stage, unsigned int Value)
{
  unsigned int *v2; // ebx

  ++D3DK::g_PerfCounters.m_APICounters[166];
  v2 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v2, 4 * Stage + 2784, *(float *)&Value);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 2);
  dword_800C2240[32 * Stage] = Value;
}