// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DDevice_SetTextureState_Deferred(unsigned int Stage@<eax>, _D3DTEXTURESTAGESTATETYPE Type@<ecx>, int a3@<edx>, unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[167];
  D3DK::g_Device.m_DirtyFlags |= *(_DWORD *)(4 * a3 - 2146914056);
  *(_DWORD *)(4 * (a3 + 32 * Type) - 2146688568) = Value;
}