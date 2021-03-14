int __stdcall D3DK::VideoBitsPerPixelOfD3DFORMAT(unsigned int Format)
{
  int result; // eax

  if ( Format == 3 || Format == 28 )
    result = 15;
  else
    result = D3DK::g_TextureFormat[Format] & 0x3C;
  return result;
}