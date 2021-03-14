unsigned int __userpurge D3DK::PixelJar::EncodeFormat@<eax>(int *a1@<edi>, unsigned int Width, unsigned int Height, unsigned int Depth, unsigned int Levels, _D3DFORMAT D3DFormat, unsigned int Pitch, char isInVideoMemory, char isCubeMap, char isVolume, unsigned int *pFormat, unsigned int *pSize)
{
  unsigned int v12; // ebx
  char v13; // cl
  unsigned int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // eax
  unsigned int v20; // eax
  char v21; // al
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // edi
  unsigned int v27; // ebx
  char v28; // al
  char v29; // cl
  int v30; // eax
  unsigned int LogMin; // [esp+Ch] [ebp-18h]
  unsigned int SizeHeight; // [esp+10h] [ebp-14h]
  unsigned int SizeWidth; // [esp+14h] [ebp-10h]
  int TexelSize; // [esp+18h] [ebp-Ch]
  unsigned int LogWidth; // [esp+1Ch] [ebp-8h]
  unsigned int Size; // [esp+20h] [ebp-4h]
  unsigned int Widtha; // [esp+2Ch] [ebp+8h]
  unsigned int LogHeight; // [esp+30h] [ebp+Ch]
  unsigned int CurrentHeight; // [esp+34h] [ebp+10h]

  v12 = Height;
  if ( !Width || !Height || !Depth )
    D3DK::DXGRIP(a1, "PixelJar::EncodeFormat - All texture dimensions must be at least 1 texel.");
  if ( D3DK::g_TextureFormat[D3DFormat] & 1
    || D3DFormat == 12
    || (unsigned int)D3DFormat > 0xD && (unsigned int)D3DFormat <= 0xF )
  {
    if ( Depth <= 1 )
    {
      if ( Width > 0x1000 )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Texture width is larger than the 4096 texel maximum.");
      if ( Height > 0x1000 )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Texture height is larger than the 4096 texel maximum.");
    }
    else
    {
      if ( Width > 0x200 )
        D3DK::DXGRIP(
          (int *)D3DFormat,
          "PixelJar::EncodeFormat - Volume texture width is larger than the 512 texel maximum.");
      if ( Height > 0x200 )
        D3DK::DXGRIP(
          (int *)D3DFormat,
          "PixelJar::EncodeFormat - Volume texture height is larger than the 512 texel maximum.");
      if ( Depth > 0x200 )
        D3DK::DXGRIP(
          (int *)D3DFormat,
          "PixelJar::EncodeFormat - Volume texture depth is larger than the 512 texel maximum.");
      if ( isCubeMap )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Volume textures cannot be cube mapped.");
      if ( D3DK::g_TextureFormat[D3DFormat] & 0x40 )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Volume textures cannot have a depth format.");
    }
    if ( (Width - 1) & Width || (Height - 1) & Height || (Depth - 1) & Depth )
      D3DK::DXGRIP(
        (int *)D3DFormat,
        "PixelJar::EncodeFormat - Each dimension of a swizzled texture must be a power of 2.");
    if ( Levels > 0x10 )
      D3DK::DXGRIP(
        (int *)D3DFormat,
        "PixelJar::EncodeFormat - Texture mipmap level count is larger than the 16 level maximum.");
    if ( isCubeMap )
    {
      if ( D3DK::g_TextureFormat[D3DFormat] & 0x40 )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Depth format textures cannot be cube mapped.");
      if ( Width != Height )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Cube maps must be square (width == height).");
    }
    goto LABEL_45;
  }
  if ( Depth != 1 )
    D3DK::DXGRIP(
      (int *)D3DFormat,
      "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be a volume texture.");
  if ( Width > 0x1000 )
    D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Texture width is larger than the 4096 texel maximum.");
  if ( Height > 0x1000 )
    D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - Texture height is larger than the 4096 texel maximum.");
  if ( Levels > 1 )
    D3DK::DXGRIP(
      (int *)D3DFormat,
      "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be mip mapped.");
  v13 = isCubeMap;
  if ( isCubeMap )
  {
    D3DK::DXGRIP(
      (int *)D3DFormat,
      "PixelJar::EncodeFormat - Non swizzled and non compressed textures cannot be cube mapped.");
LABEL_45:
    v13 = isCubeMap;
  }
  Size = 0;
  TexelSize = D3DK::g_TextureFormat[D3DFormat] & 0x3C;
  if ( D3DK::g_TextureFormat[D3DFormat] & 1
    || D3DFormat == 12
    || (unsigned int)D3DFormat > 0xD && (unsigned int)D3DFormat <= 0xF )
  {
    if ( !Width )
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "Value");
    if ( (Width - 1) & Width )
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "(Value & (Value - 1)) == 0");
    _BitScanForward(&v16, Width);
    LogWidth = v16;
    if ( !Height )
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "Value");
    if ( (Height - 1) & Height )
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "(Value & (Value - 1)) == 0");
    _BitScanForward(&v17, Height);
    v18 = v17;
    v19 = Depth;
    LogHeight = v18;
    if ( !Depth )
    {
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "Value");
      v19 = 0;
    }
    if ( (v19 - 1) & v19 )
      D3DK::DXGRIP((int *)D3DFormat, "Assertion failure: %s", "(Value & (Value - 1)) == 0");
    _BitScanForward(&v20, Depth);
    v14 = v20;
    v21 = 0;
    SizeWidth = 0;
    SizeHeight = 0;
    if ( D3DFormat == 12 || (unsigned int)D3DFormat > 0xD && (unsigned int)D3DFormat <= 0xF )
      v21 = 1;
    LogMin = v21 != 0 ? 2 : 0;
    v22 = v18;
    if ( Levels )
    {
      if ( v18 <= v14 )
        v22 = v14;
      if ( LogWidth <= v22 )
      {
        v24 = v18;
        if ( v18 <= v14 )
          v24 = v14;
      }
      else
      {
        v24 = LogWidth;
      }
      if ( Levels > v24 + 1 )
        D3DK::DXGRIP((int *)D3DFormat, "PixelJar::EncodeFormat - too many mip levels were specified for this texture.");
    }
    else
    {
      if ( v18 <= v14 )
        v22 = v14;
      if ( LogWidth <= v22 )
      {
        v23 = v18;
        if ( v18 <= v14 )
          v23 = v14;
        Levels = v23 + 1;
      }
      else
      {
        Levels = LogWidth + 1;
      }
    }
    v25 = LogWidth;
    CurrentHeight = v18;
    v26 = v14;
    if ( Levels )
    {
      v27 = 0;
      Widtha = Levels;
      do
      {
        v28 = LogMin;
        v29 = v25;
        if ( v25 <= LogMin )
          v29 = LogMin;
        if ( CurrentHeight > LogMin )
          v28 = CurrentHeight;
        v27 += (unsigned int)(TexelSize * (1 << (v26 + v28 + v29))) >> 3;
        if ( v25 )
          --v25;
        if ( CurrentHeight )
          --CurrentHeight;
        if ( v26 )
          --v26;
        --Widtha;
      }
      while ( Widtha );
      Size = v27;
    }
    v15 = Pitch;
    if ( isCubeMap )
      Size = 6 * ((Size + 127) & 0xFFFFFF80);
    v13 = isCubeMap;
  }
  else
  {
    v14 = 0;
    LogHeight = 0;
    LogWidth = 0;
    if ( !Levels )
      Levels = 1;
    v15 = Pitch;
    if ( !Pitch )
      v15 = ((Width * TexelSize >> 3) + 63) & 0xFFFFFFC0;
    SizeHeight = v12;
    SizeWidth = Width;
    Size = v15 * v12;
  }
  *pFormat = (v13 != 0 ? 4 : 0) | ((isInVideoMemory != 0) + 1) | 16
                                                               * (((isVolume != 0) + 2) | 16
                                                                                        * (D3DFormat | ((Levels | 16 * (LogWidth | 16 * (LogHeight | 16 * v14))) << 8))) | 8;
  if ( SizeWidth )
  {
    v30 = (SizeWidth - 1) | (((SizeHeight - 1) | (((v15 >> 6) - 1) << 12)) << 12);
    *pSize = v30;
    if ( (v30 & 0xFFF) + 1 != SizeWidth )
      D3DK::DXGRIP((int *)v15, "Assertion failure: %s", "(*pSize & D3DSIZE_WIDTH_MASK) + 1 == SizeWidth");
    if ( ((*pSize >> 12) & 0xFFF) + 1 != SizeHeight )
      D3DK::DXGRIP(
        (int *)v15,
        "Assertion failure: %s",
        "((*pSize & D3DSIZE_HEIGHT_MASK) >> D3DSIZE_HEIGHT_SHIFT) + 1 == SizeHeight");
    if ( (*((unsigned __int8 *)pSize + 3) + 1) << 6 != v15 )
    {
      D3DK::DXGRIP(
        (int *)v15,
        "PixelJar::EncodeFormat - The surface pitch is too large, possibly caused by using antialiasing with a large surface.");
      return Size;
    }
  }
  else
  {
    *pSize = 0;
  }
  return Size;
}