// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_TwoSidedLighting(int *a1@<edi>, unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[152];
  D3DK::g_pDevice->m_DirtyFlags |= 0x20u;
  LODWORD(value) = Value;
  D3DDevice_SetRenderState_FillMode(a1, 0);
}