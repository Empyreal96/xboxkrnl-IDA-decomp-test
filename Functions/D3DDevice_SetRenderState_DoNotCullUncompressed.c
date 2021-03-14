// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_DoNotCullUncompressed(D3DK *a1@<ecx>, int *a2@<edi>, unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[129];
  dword_800C2604 = Value;
  D3DK::CommonSetDebugRegisters(a1, a2);
}