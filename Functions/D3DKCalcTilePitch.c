unsigned int __stdcall D3DK::CalcTilePitch(unsigned int Width, _D3DFORMAT D3DFormat)
{
  unsigned int result; // eax
  int v3; // ecx

  result = ((Width * (D3DK::g_TextureFormat[D3DFormat] & 0x3C) >> 3) + 63) & 0xFFFFFFC0;
  v3 = 0;
  while ( result > *(_DWORD *)(4 * v3 - 2146982264) )
  {
    if ( (unsigned int)++v3 >= 0x10 )
      return result;
  }
  return *(_DWORD *)(4 * v3 - 2146982264);
}