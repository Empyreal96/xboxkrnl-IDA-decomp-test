// write access to const memory has been detected, the output may be wrong!
int __stdcall D3DTexture_GetSurfaceLevel(D3DTexture *pTexture, unsigned int Level, D3DSurface **ppSurfaceLevel)
{
  D3DTexture *v3; // esi
  int *v4; // edi
  unsigned int RowPitch; // [esp+8h] [ebp-10h]
  unsigned int SlicePitch; // [esp+Ch] [ebp-Ch]
  unsigned int Format; // [esp+10h] [ebp-8h]
  unsigned int Size; // [esp+14h] [ebp-4h]

  v3 = pTexture;
  ++D3DK::g_PerfCounters.m_APICounters[200];
  D3DK::CHECK(pTexture, "D3DTexture_GetSurfaceLevel");
  v4 = (int *)Level;
  if ( Level >= (BYTE2(v3->Format) & 0xFu) )
    D3DK::DXGRIP((int *)Level, "D3DTexture_GetSurfaceLevel - invalid mipmap level.");
  D3DK::PixelJar::FindSurfaceWithinTexture(
    (D3DPixelContainer *)&v3->Common,
    0,
    (unsigned int)v4,
    (char **)&pTexture,
    &RowPitch,
    &SlicePitch,
    &Format,
    &Size);
  return D3DK::CreateSurfaceOfTexture(
           v4,
           Size,
           (int)pTexture,
           (int)v3,
           Format,
           Size,
           (D3DBaseTexture *)&v3->Common,
           pTexture,
           ppSurfaceLevel);
}