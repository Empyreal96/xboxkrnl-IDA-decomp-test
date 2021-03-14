// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DTexture_LockRect(D3DTexture *pTexture, unsigned int Level, _D3DLOCKED_RECT *pLockedRect, tagRECT *pRect, unsigned int Flags)
{
  ++D3DK::g_PerfCounters.m_APICounters[201];
  D3DK::CHECK(pTexture, "D3DTexture_LockRect");
  D3DK::PixelJar::Lock2DSurface((D3DPixelContainer *)&pTexture->Common, 0, Level, pLockedRect, pRect, Flags);
}