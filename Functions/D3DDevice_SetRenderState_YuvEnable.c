// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_YuvEnable(int *a1@<edi>, unsigned int Value)
{
  unsigned int *v2; // eax
  unsigned int *v3; // eax

  ++D3DK::g_PerfCounters.m_APICounters[154];
  dword_800C25F0 = Value;
  v2 = XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  v3 = D3DK::CommonSetControl0((D3DK::CDevice *)v2, (unsigned int *)D3DK::g_pDevice, v2, a1);
  XMETAL_EndPush(a1, &D3DK::g_pDevice->m_Pusher, v3);
}