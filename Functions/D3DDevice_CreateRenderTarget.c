// write access to const memory has been detected, the output may be wrong!
int __userpurge D3DDevice_CreateRenderTarget@<eax>(int *a1@<edi>, unsigned int Width, unsigned int Height, _D3DFORMAT D3DFormat, unsigned int MultiSample, int Lockable, D3DSurface **ppSurface)
{
  char v7; // al

  v7 = D3DK::g_TextureFormat[D3DFormat];
  ++D3DK::g_PerfCounters.m_APICounters[30];
  if ( v7 >= 0 )
    D3DK::DXGRIP(a1, "Invalid render target format");
  return D3DK::CreateStandAloneSurface(a1, D3DFormat, Width, Height, D3DFormat, 1, ppSurface);
}