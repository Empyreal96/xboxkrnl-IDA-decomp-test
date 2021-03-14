// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_PSTextureModes(unsigned int Value)
{
  unsigned int v1; // edx

  ++D3DK::g_PerfCounters.m_APICounters[143];
  v1 = D3DK::g_pDevice->m_DirtyFlags | 0x400;
  D3DK::g_pDevice->m_PSShaderStageProgram = Value;
  D3DK::g_pDevice->m_DirtyFlags = v1;
  dword_800C2598 = Value;
}