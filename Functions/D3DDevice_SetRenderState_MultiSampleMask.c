// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_MultiSampleMask(int *a1@<edi>, unsigned int Value)
{
  unsigned int *v2; // eax
  int *v3; // edi

  ++D3DK::g_PerfCounters.m_APICounters[138];
  dword_800C25DC = Value;
  D3DK::CommonSetPassthroughProgram((D3DK::CDevice *)Value, (int *)D3DK::g_pDevice);
  v2 = XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  v3 = (int *)D3DK::CommonSetViewport((D3DK::CDevice *)v2, (unsigned int *)D3DK::g_pDevice, (int *)v2);
  XMETAL_Push1f(v3, (unsigned int *)v3, 0x1D7Cu, 0.0);
  XMETAL_EndPush(v3 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v3 + 2);
}