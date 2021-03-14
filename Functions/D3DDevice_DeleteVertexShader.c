// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DeleteVertexShader(unsigned int Handle)
{
  D3DK::VertexShader *v1; // esi
  bool v2; // zf

  ++D3DK::g_PerfCounters.m_APICounters[39];
  v1 = (D3DK::VertexShader *)(Handle - 1);
  if ( !(Handle & 1) )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid vertex shader handle value");
  if ( D3DK::g_pDevice->m_pVertexShader == v1 && v1->RefCount == 1 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Can't delete a vertex shader that's currently active");
  if ( v1->Signature != 1450403940 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid vertex shader object (already deleted?)");
  v2 = v1->RefCount-- == 1;
  if ( v2 )
  {
    v1->Signature = 2021161080;
    D3DK::MemFree(v1);
  }
}