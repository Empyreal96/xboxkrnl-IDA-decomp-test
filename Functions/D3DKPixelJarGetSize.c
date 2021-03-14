void __stdcall D3DK::PixelJar::GetSize(D3DPixelContainer *pPixels, unsigned int Level, unsigned int *pWidth, unsigned int *pHeight, unsigned int *pDepth, unsigned int *pPitch, unsigned int *pSlice)
{
  D3DPixelContainer *v7; // esi
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  signed int v10; // eax
  signed int v11; // edx
  signed int v12; // esi
  char v13; // cl
  int v14; // ecx
  signed int v15; // edi
  signed int v16; // eax
  int v17; // edx
  unsigned int v18; // ebx
  int BitsPerPixel; // [esp+14h] [ebp+8h]

  v7 = pPixels;
  v8 = pPixels->Size;
  if ( Level >= (BYTE2(pPixels->Format) & 0xFu) )
    D3DK::DXGRIP((int *)Level, "PixelJar::GetSize - invalid mipmap level.");
  if ( v8 )
  {
    *pWidth = (v8 & 0xFFF) + 1;
    *pHeight = ((v8 >> 12) & 0xFFF) + 1;
    *pDepth = 1;
    v18 = ((v8 >> 24) + 1) << 6;
    *pPitch = v18;
    *pSlice = v18 * *pHeight;
  }
  else
  {
    v9 = pPixels->Format;
    v10 = ((pPixels->Format >> 20) & 0xF) - Level;
    v11 = ((pPixels->Format >> 24) & 0xF) - Level;
    BitsPerPixel = D3DK::g_TextureFormat[BYTE1(pPixels->Format)] & 0x3C;
    *pHeight = 1 << (v11 <= 0 ? 0 : v11);
    *pDepth = 1 << (((v9 >> 28) - Level) & (((signed int)((v9 >> 28) - Level) <= 0) - 1));
    *pWidth = 1 << (v10 <= 0 ? 0 : v10);
    v12 = BYTE1(v7->Format);
    v13 = 0;
    if ( v12 == 12 || (unsigned int)v12 > 0xD && (unsigned int)v12 <= 0xF )
      v13 = 1;
    v14 = v13 != 0 ? 2 : 0;
    if ( v14 > v10 )
      LOBYTE(v10) = v14;
    v15 = 1 << v10;
    if ( v14 > v11 )
      LOBYTE(v11) = v14;
    v16 = 1 << v11;
    if ( v12 == 12 )
    {
      v17 = 2 * v15;
    }
    else if ( v12 <= 13 || v12 > 15 )
    {
      v17 = (unsigned int)(BitsPerPixel * v15) >> 3;
    }
    else
    {
      v17 = 4 * v15;
    }
    *pPitch = v17;
    *pSlice = (unsigned int)(BitsPerPixel * v15 * v16) >> 3;
  }
}