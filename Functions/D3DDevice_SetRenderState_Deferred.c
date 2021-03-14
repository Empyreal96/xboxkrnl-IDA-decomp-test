// write access to const memory has been detected, the output may be wrong!
void __usercall D3DDevice_SetRenderState_Deferred(_D3DRENDERSTATETYPE State@<eax>, unsigned int Value@<ecx>, int *a3@<edx>)
{
  int *v3; // edi
  unsigned int v4; // esi
  int v5; // ecx
  int v6; // edx

  v3 = a3;
  v4 = Value;
  ++D3DK::g_PerfCounters.m_APICounters[128];
  if ( Value - 82 < 0x22 )
  {
    v6 = *(_DWORD *)(4 * Value - 2146985400);
    *(_DWORD *)(4 * Value - 2146688056) = v3;
    D3DK::g_Device.m_DirtyFlags |= v6;
  }
  else
  {
    D3DK::DXGRIP(
      a3,
      "Assertion failure: %s",
      "State - D3DRS_SIMPLE_MAX < sizeof(g_DirtyFromRenderState) / sizeof(g_DirtyFromRenderState[0])");
    v5 = *(_DWORD *)(4 * v4 - 2146985400);
    *(_DWORD *)(4 * v4 - 2146688056) = v3;
    D3DK::g_Device.m_DirtyFlags |= v5;
  }
}