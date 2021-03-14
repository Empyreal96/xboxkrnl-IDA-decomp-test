// write access to const memory has been detected, the output may be wrong!
void __stdcall D3DTexture_GetLevelDesc(D3DTexture *pTexture, unsigned int Level, _D3DSURFACE_DESC *pDesc)
{
  ++D3DK::g_PerfCounters.m_APICounters[199];
  D3DK::CHECK(pTexture, "D3DTexture_GetLevelDesc");
  D3DK::PixelJar::Get2DSurfaceDesc((D3DPixelContainer *)&pTexture->Common, Level, pDesc);
}