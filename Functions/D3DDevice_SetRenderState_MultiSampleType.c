// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_SetRenderState_MultiSampleType(unsigned int Value)
{
  ++D3DK::g_PerfCounters.m_APICounters[139];
  dword_800C25E0 = Value;
  D3DDevice_SetRenderTarget(D3DK::g_pDevice->m_pRenderTarget, D3DK::g_pDevice->m_pZBuffer);
}