// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_FrontFace(int *a1@<edi>, unsigned int Value)
{
  int *v2; // edi

  ++D3DK::g_PerfCounters.m_APICounters[134];
  v2 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v2, (unsigned int *)v2, 0x3A0u, *(float *)&Value);
  XMETAL_EndPush(v2 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v2 + 2);
  dword_800C25C0 = Value;
  D3DDevice_SetRenderState_CullMode(0);
}