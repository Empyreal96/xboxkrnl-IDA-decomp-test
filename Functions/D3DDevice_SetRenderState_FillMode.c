// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_FillMode(int *a1@<edi>, unsigned int Value)
{
  int *v2; // edi

  ++D3DK::g_PerfCounters.m_APICounters[132];
  v2 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push2f(v2, (unsigned int *)v2, 0x38Cu, *(float *)&Value, *(float *)&Value);
  XMETAL_EndPush(v2 + 3, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v2 + 3);
  dword_800C25A4 = Value;
}