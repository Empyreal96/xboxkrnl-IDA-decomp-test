// write access to const memory has been detected, the output may be wrong!
int __stdcall D3DCubeTexture_GetCubeMapSurface(D3DCubeTexture *pTexture, _D3DCUBEMAP_FACES FaceType, unsigned int Level, D3DSurface **ppCubeMapSurface)
{
  D3DCubeTexture *v4; // esi
  int *v5; // edi
  unsigned int RowPitch; // [esp+8h] [ebp-10h]
  unsigned int SlicePitch; // [esp+Ch] [ebp-Ch]
  unsigned int Format; // [esp+10h] [ebp-8h]
  unsigned int Size; // [esp+14h] [ebp-4h]

  v4 = pTexture;
  ++D3DK::g_PerfCounters.m_APICounters[202];
  D3DK::CHECK(pTexture, "D3DCubeTexture_GetCubeMapSurface");
  v5 = (int *)Level;
  if ( Level >= (BYTE2(v4->Format) & 0xFu) )
    D3DK::DXGRIP((int *)Level, "D3DTexture_GetSurfaceLevel - invalid mipmap level.");
  D3DK::PixelJar::FindSurfaceWithinTexture(
    (D3DPixelContainer *)&v4->Common,
    FaceType,
    (unsigned int)v5,
    (char **)&pTexture,
    &RowPitch,
    &SlicePitch,
    &Format,
    &Size);
  return D3DK::CreateSurfaceOfTexture(
           v5,
           (int)pTexture,
           Format,
           (int)v4,
           Format,
           Size,
           (D3DBaseTexture *)&v4->Common,
           pTexture,
           ppCubeMapSurface);
}