// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_TextureFactor(int *a1@<edi>, unsigned int Value)
{
  unsigned int *v2; // esi

  ++D3DK::g_PerfCounters.m_APICounters[151];
  if ( !D3DK::g_pDevice->m_pPixelShader )
  {
    v2 = XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
    XMETAL_PushCount(a1, v2, 0xA60u, 0x10u);
    memset32(v2 + 1, Value, 0x10u);
    XMETAL_EndPush((int *)v2 + 17, &D3DK::g_pDevice->m_Pusher, v2 + 17);
  }
  dword_800C25C8 = Value;
}