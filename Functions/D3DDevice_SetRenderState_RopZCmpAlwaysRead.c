// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_RopZCmpAlwaysRead(D3DK *a1@<ecx>, int *a2@<edi>, unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[144];
  dword_800C25FC = Value;
  D3DK::CommonSetDebugRegisters(a1, a2);
}