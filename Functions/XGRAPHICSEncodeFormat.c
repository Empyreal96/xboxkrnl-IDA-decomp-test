unsigned int __stdcall XGRAPHICS::EncodeFormat(unsigned int Width, unsigned int Height, unsigned int Depth, unsigned int Levels, _D3DFORMAT D3DFormat, unsigned int Pitch, char isInVideoMemory, char isCubeMap, char isVolume, unsigned int *pFormat, unsigned int *pSize)
{
  unsigned int v11; // ebx
  unsigned int v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // esi
  char v15; // cl
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ebx
  char v22; // cl
  char v23; // al
  unsigned int v24; // eax
  int TexelSize; // [esp+Ch] [ebp-14h]
  unsigned int LogMin; // [esp+10h] [ebp-10h]
  unsigned int SizeHeight; // [esp+14h] [ebp-Ch]
  unsigned int SizeWidth; // [esp+18h] [ebp-8h]
  unsigned int LogHeight; // [esp+1Ch] [ebp-4h]
  unsigned int LogWidth; // [esp+28h] [ebp+8h]
  unsigned int Size; // [esp+2Ch] [ebp+Ch]
  unsigned int CurrentHeight; // [esp+30h] [ebp+10h]

  v11 = Width;
  v12 = Height;
  if ( !Width || !Height || !Depth )
    XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - All texture dimensions must be at least 1 texel.");
  if ( XGRAPHICS::g_TextureFormat[D3DFormat] & 1 || XGRAPHICS::IsCompressedD3DFORMAT(D3DFormat) )
  {
    if ( Depth <= 1 )
    {
      if ( Width > 0x1000 )
        XGRAPHICS::DXGRIP(
          (int *)Height,
          "PixelJar::EncodeFormat - Texture width is larger than the 4096 texel maximum.");
      if ( Height > 0x1000 )
        XGRAPHICS::DXGRIP(
          (int *)Height,
          "PixelJar::EncodeFormat - Texture height is larger than the 4096 texel maximum.");
    }
    else
    {
      if ( Width > 0x200 )
        XGRAPHICS::DXGRIP(
          (int *)Height,
          "PixelJar::EncodeFormat - Volume texture width is larger than the 512 texel maximum.");
      if ( Height > 0x200 )
        XGRAPHICS::DXGRIP(
          (int *)Height,
          "PixelJar::EncodeFormat - Volume texture height is larger than the 512 texel maximum.");
      if ( Depth > 0x200 )
        XGRAPHICS::DXGRIP(
          (int *)Height,
          "PixelJar::EncodeFormat - Volume texture depth is larger than the 512 texel maximum.");
      if ( isCubeMap )
        XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Volume textures cannot be cube mapped.");
      if ( XGRAPHICS::g_TextureFormat[D3DFormat] & 0x40 )
        XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Volume textures cannot have a depth format.");
    }
    if ( (Width - 1) & Width || (Height - 1) & Height || (Depth - 1) & Depth )
      XGRAPHICS::DXGRIP(
        (int *)Height,
        "PixelJar::EncodeFormat - Each dimension of a swizzled texture must be a power of 2.");
    if ( Levels > 0x10 )
      XGRAPHICS::DXGRIP(
        (int *)Height,
        "PixelJar::EncodeFormat - Texture mipmap level count is larger than the 16 level maximum.");
    if ( isCubeMap )
    {
      if ( XGRAPHICS::g_TextureFormat[D3DFormat] & 0x40 )
        XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Depth format textures cannot be cube mapped.");
      if ( Width != Height )
        XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Cube maps must be square (width == height).");
    }
  }
  else
  {
    if ( Depth != 1 )
      XGRAPHICS::DXGRIP(
        (int *)Height,
        "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be a volume texture.");
    if ( Width > 0x1000 )
      XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Texture width is larger than the 4096 texel maximum.");
    if ( Height > 0x1000 )
      XGRAPHICS::DXGRIP((int *)Height, "PixelJar::EncodeFormat - Texture height is larger than the 4096 texel maximum.");
    if ( Levels > 1 )
      XGRAPHICS::DXGRIP(
        (int *)Height,
        "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be mip mapped.");
    if ( isCubeMap )
      XGRAPHICS::DXGRIP(
        (int *)Height,
        "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be cube mapped.");
  }
  v13 = D3DFormat;
  LOBYTE(v13) = XGRAPHICS::g_TextureFormat[D3DFormat];
  Size = 0;
  TexelSize = v13 & 0x3C;
  if ( v13 & 1 || (LOBYTE(v13) = XGRAPHICS::IsCompressedD3DFORMAT(D3DFormat), (_BYTE)v13) )
  {
    LogWidth = XGRAPHICS::Log2(v13, Width);
    LogHeight = XGRAPHICS::Log2(LogWidth, v12);
    v14 = XGRAPHICS::Log2(LogHeight, Depth);
    SizeWidth = 0;
    SizeHeight = 0;
    LogMin = XGRAPHICS::MinimumTextureSizeOfD3DFORMAT(D3DFormat);
    v16 = LogHeight;
    if ( Levels )
    {
      if ( LogHeight <= v14 )
        v16 = v14;
      if ( LogWidth <= v16 )
      {
        v18 = LogHeight;
        if ( LogHeight <= v14 )
          v18 = v14;
      }
      else
      {
        v18 = LogWidth;
      }
      if ( Levels > v18 + 1 )
        XGRAPHICS::DXGRIP(0, "PixelJar::EncodeFormat - too many mip levels were specified for this texture.");
    }
    else
    {
      if ( LogHeight <= v14 )
        v16 = v14;
      if ( LogWidth <= v16 )
      {
        v17 = LogHeight;
        if ( LogHeight <= v14 )
          v17 = v14;
      }
      else
      {
        v17 = LogWidth;
      }
      Levels = v17 + 1;
    }
    v19 = LogWidth;
    CurrentHeight = LogHeight;
    v20 = v14;
    if ( Levels )
    {
      v21 = Levels;
      do
      {
        v22 = v19;
        if ( v19 <= LogMin )
          v22 = LogMin;
        v23 = CurrentHeight;
        if ( CurrentHeight <= LogMin )
          v23 = LogMin;
        Size += (unsigned int)(TexelSize * (1 << (v20 + v23 + v22))) >> 3;
        if ( v19 )
          --v19;
        if ( CurrentHeight )
          --CurrentHeight;
        if ( v20 )
          --v20;
        --v21;
      }
      while ( v21 );
    }
    v15 = isCubeMap;
    if ( isCubeMap )
      Size = 6 * ((Size + 127) & 0xFFFFFF80);
  }
  else
  {
    v14 = 0;
    LogHeight = 0;
    LogWidth = 0;
    if ( !Levels )
      Levels = 1;
    if ( !Pitch )
      Pitch = ((v11 * TexelSize >> 3) + 63) & 0xFFFFFFC0;
    v15 = isCubeMap;
    SizeHeight = v12;
    SizeWidth = v11;
    Size = Pitch * v12;
  }
  *pFormat = (v15 != 0 ? 4 : 0) | ((isInVideoMemory != 0) + 1) | 16
                                                               * (((isVolume != 0) + 2) | 16
                                                                                        * (D3DFormat | ((Levels | 16 * (LogWidth | 16 * (LogHeight | 16 * v14))) << 8))) | 8;
  if ( SizeWidth )
  {
    v24 = (SizeWidth - 1) | (((SizeHeight - 1) | (((Pitch >> 6) - 1) << 12)) << 12);
    *pSize = v24;
    if ( (v24 & 0xFFF) + 1 != SizeWidth )
      XGRAPHICS::DXGRIP((int *)pSize, "Assertion failure: %s", "(*pSize & D3DSIZE_WIDTH_MASK) + 1 == SizeWidth");
    if ( ((*pSize >> 12) & 0xFFF) + 1 != SizeHeight )
      XGRAPHICS::DXGRIP(
        (int *)pSize,
        "Assertion failure: %s",
        "((*pSize & D3DSIZE_HEIGHT_MASK) >> D3DSIZE_HEIGHT_SHIFT) + 1 == SizeHeight");
    if ( (*((unsigned __int8 *)pSize + 3) + 1) << 6 != Pitch )
      XGRAPHICS::DXGRIP((int *)pSize, "Assertion failure: %s", "PitchFromSize(*pSize) == Pitch");
  }
  else
  {
    *pSize = 0;
  }
  return Size;
}