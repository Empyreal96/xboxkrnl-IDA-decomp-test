// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DSurface_LockRect(int *a1@<edi>, D3DSurface *pSurface, _D3DLOCKED_RECT *pLockedRect, tagRECT *pRect, unsigned int Flags)
{
  ++D3DK::g_PerfCounters.m_APICounters[216];
  if ( !pSurface )
    D3DK::DXGRIP(a1, "%s - Null THIS pointer.", "D3DSurface_LockRect");
  if ( (pSurface->Common & 0x70000) != 327680 || (pSurface->Format & 0xF0) != 32 )
    D3DK::DXGRIP(a1, "%s - This points to the wrong type of object.", "D3DSurface_LockRect");
  D3DK::PixelJar::Lock2DSurface((D3DPixelContainer *)&pSurface->Common, 0, 0, pLockedRect, pRect, Flags);
}