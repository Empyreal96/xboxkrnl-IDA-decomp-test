// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DSurface_GetDesc(int *a1@<edi>, D3DSurface *pSurface, _D3DSURFACE_DESC *pDesc)
{
  ++D3DK::g_PerfCounters.m_APICounters[215];
  if ( !pSurface )
    D3DK::DXGRIP(a1, "%s - Null THIS pointer.", "D3DSurface_GetDesc");
  if ( (pSurface->Common & 0x70000) != 327680 || (pSurface->Format & 0xF0) != 32 )
    D3DK::DXGRIP(a1, "%s - This points to the wrong type of object.", "D3DSurface_GetDesc");
  D3DK::PixelJar::Get2DSurfaceDesc((D3DPixelContainer *)&pSurface->Common, 0, pDesc);
}