// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_DeletePixelShader(unsigned int Handle)
{
  bool v1; // zf

  ++D3DK::g_PerfCounters.m_APICounters[37];
  if ( !Handle )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid pixel shader handle value");
  if ( D3DK::g_pDevice->m_pPixelShader == (D3DK::PixelShader *)Handle && *(_DWORD *)(Handle + 4) == 1 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Can't delete a pixel shader that's currently active");
  if ( *(_DWORD *)Handle != 1349740644 )
    D3DK::DXGRIP((int *)D3DK::g_pDevice, "Invalid pixel shader object (already deleted?)");
  v1 = (*(_DWORD *)(Handle + 4))-- == 1;
  if ( v1 )
  {
    if ( *(_DWORD *)(Handle + 8) )
    {
      *(_DWORD *)Handle = 2021161080;
      D3DK::MemFree((void *)Handle);
    }
  }
}