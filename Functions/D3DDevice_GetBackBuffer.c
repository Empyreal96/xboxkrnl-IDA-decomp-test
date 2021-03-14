// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DDevice_GetBackBuffer(int BackBuffer, unsigned int Type, D3DSurface **ppBackBuffer)
{
  int *v3; // edi
  signed int v4; // esi
  D3DSurface *v5; // eax

  ++D3DK::g_PerfCounters.m_APICounters[53];
  v3 = (int *)(BackBuffer + 1);
  if ( BackBuffer + 1 > (signed int)D3DK::g_pDevice->m_FrameBufferCount )
    D3DK::DXGRIP(v3, "BackBuffer parameter is too big.");
  if ( Type )
    D3DK::DXGRIP(v3, "Xbox supports only D3DBACKBUFFER_TYPE_MONO.");
  if ( BackBuffer == -1 )
    v4 = 1;
  else
    v4 = BackBuffer != 0 ? (unsigned int)v3 : 0;
  v5 = &D3DK::g_pDevice->m_FrameBufferSurfaces[v4];
  *ppBackBuffer = v5;
  D3DResource_AddRef(v3, (D3DResource *)&v5->Common);
}