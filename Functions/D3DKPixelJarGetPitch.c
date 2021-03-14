unsigned int __stdcall D3DK::PixelJar::GetPitch(D3DPixelContainer *pPixels)
{
  unsigned int v1; // eax
  signed int v2; // eax
  signed int v3; // edx

  v1 = pPixels->Size;
  if ( v1 )
    return ((v1 >> 24) + 1) << 6;
  v2 = BYTE1(pPixels->Format);
  v3 = 1 << ((pPixels->Format >> 20) & 0xF);
  if ( v2 == 12 )
    return 2 * v3;
  if ( v2 <= 13 || v2 > 15 )
    return v3 * (D3DK::g_TextureFormat[v2] & 0x3Cu) >> 3;
  return 4 * v3;
}