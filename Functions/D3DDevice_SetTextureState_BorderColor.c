// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetTextureState_BorderColor(unsigned int Stage, unsigned int Value)
{
  unsigned int *v2; // ebx

  ++D3DK::g_PerfCounters.m_APICounters[164];
  v2 = XMETAL_StartPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f((int *)D3DK::g_pDevice, v2, (Stage << 6) + 6948, *(float *)&Value);
  XMETAL_EndPush((int *)D3DK::g_pDevice, &D3DK::g_pDevice->m_Pusher, v2 + 2);
  dword_800C223C[32 * Stage] = Value;
}