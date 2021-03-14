// write access to const memory has been detected, the output may be wrong!
void __usercall D3DDevice_SetRenderState_Simple(unsigned int Method@<eax>, unsigned int Value@<ecx>, unsigned int a3@<edx>, int *a4@<edi>)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // eax

  v4 = Value;
  v5 = a3;
  ++D3DK::g_PerfCounters.m_APICounters[147];
  if ( Value & 3 || (v6 = Value & 0xFFFFE000, (Value & 0xFFFFE000) != 0x40000) )
    D3DK::DXGRIP(a4, "Invalid encoding");
  D3DDevice_SetRenderState_Simple_Fast(v6, v4, v5, a4);
}