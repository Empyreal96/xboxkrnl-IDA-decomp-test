// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_NormalizeNormals(int *a1@<edi>, unsigned int Value)
{
  int *v2; // edi

  ++D3DK::g_PerfCounters.m_APICounters[140];
  v2 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(v2, (unsigned int *)v2, 0x3A4u, *(float *)&Value);
  XMETAL_EndPush(v2 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v2 + 2);
  D3DK::g_pDevice->m_DirtyFlags |= 2u;
  dword_800C25B0 = Value;
}