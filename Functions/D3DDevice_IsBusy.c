// write access to const memory has been detected, the output may be wrong!
BOOL __stdcall D3DDevice_IsBusy()
{
  D3DK::_HWREG *v0; // ebx
  unsigned int v1; // edi
  BOOL result; // eax

  ++D3DK::g_PerfCounters.m_APICounters[98];
  v0 = D3DK::g_pDevice->m_NvBase;
  v1 = D3DK::g_pDevice->m_pControlDma->Get;
  if ( v1 > 0x4000000 )
  {
    DbgPrint((int *)v1, "DebugVerifyPhysical - Not a valid physical memory offset.");
    DbgPrint((int *)v1, "\n");
    __debugbreak();
  }
  if ( (v1 ^ (_DWORD)D3DK::g_pDevice->m_pKickOff) & 0xFFFFFFF )
    result = 1;
  else
    result = v0[1049024].Reg032[0] != 0;
  return result;
}