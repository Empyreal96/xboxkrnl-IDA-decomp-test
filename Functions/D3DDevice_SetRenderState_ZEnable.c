// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_ZEnable(int *a1@<edi>, unsigned int Value)
{
  int *v2; // edi
  BOOL v3; // eax
  int *v4; // edi
  D3DK::CDevice *v5; // eax
  unsigned int *v6; // eax
  unsigned int *v7; // eax
  int savedregs; // [esp+Ch] [ebp+0h]

  ++D3DK::g_PerfCounters.m_APICounters[156];
  v2 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
  v3 = Value && D3DK::g_pDevice->m_pZBuffer;
  XMETAL_Push1f(v2, (unsigned int *)v2, 0x30Cu, *(float *)&v3);
  v4 = v2 + 2;
  XMETAL_EndPush(v4, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v4);
  dword_800C25B4 = Value;
  if ( Value == 2 )
  {
    D3DK::UpdateProjectionViewportTransform(COERCE_FLOAT(&savedregs));
    D3DK::CommonSetPassthroughProgram(v5, (int *)D3DK::g_pDevice);
    v6 = XMETAL_StartPush(v4, &D3DK::g_pDevice->m_Pusher);
    v7 = D3DK::CommonSetControl0((D3DK::CDevice *)v6, (unsigned int *)D3DK::g_pDevice, v6, v4);
    XMETAL_EndPush(v4, &D3DK::g_pDevice->m_Pusher, v7);
  }
}