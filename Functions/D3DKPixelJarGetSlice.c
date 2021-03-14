unsigned int __stdcall D3DK::PixelJar::GetSlice(D3DPixelContainer *pPixels)
{
  unsigned int v1; // edi
  int v2; // ebx
  unsigned int v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // ecx

  v1 = pPixels->Size;
  v2 = D3DK::g_TextureFormat[BYTE1(pPixels->Format)] & 0x3C;
  v3 = D3DK::IsCompressedD3DFORMAT(BYTE1(pPixels->Format)) != 0 ? 2 : 0;
  if ( v1 )
    return ((v1 >> 24) + 1) * (((v1 >> 12) & 0xFFF) + 1) << 6;
  v4 = (pPixels->Format >> 20) & 0xF;
  if ( v3 > v4 )
    LOBYTE(v4) = v3;
  v5 = (pPixels->Format >> 24) & 0xF;
  if ( v3 > v5 )
    LOBYTE(v5) = v3;
  return (unsigned int)(v2 * (1 << (v4 + v5))) >> 3;
}