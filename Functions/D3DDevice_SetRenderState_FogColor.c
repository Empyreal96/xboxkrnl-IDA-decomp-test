// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_FogColor(int *a1@<edi>, unsigned int Value)
{
  int *v2; // edi

  ++D3DK::g_PerfCounters.m_APICounters[133];
  v2 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  XMETAL_Push1f(
    v2,
    (unsigned int *)v2,
    0x2A8u,
    COERCE_FLOAT(Value & 0xFF00FF00 | ((unsigned __int8)Value << 16) | BYTE2(Value)));
  XMETAL_EndPush(v2 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v2 + 2);
  dword_800C25A0 = Value;
}