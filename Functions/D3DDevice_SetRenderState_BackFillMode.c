// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetRenderState_BackFillMode(int *a1@<edi>, unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[126];
  LODWORD(b) = Value;
  D3DDevice_SetRenderState_FillMode(a1, 0);
}