unsigned int __stdcall GetFormatSize(tWAVEFORMATEX *pwfxSrc, unsigned int dwAccess)
{
  unsigned int dwSize; // [esp+0h] [ebp-4h]

  if ( pwfxSrc->wFormatTag != 1 )
    return pwfxSrc->cbSize + 18;
  dwSize = 18;
  if ( dwAccess == 0x80000000 )
    dwSize = 16;
  return dwSize;
}