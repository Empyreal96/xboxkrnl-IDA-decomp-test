D3DTexture *__stdcall CreateGlowTexture(int width, int height, int colorScale, int noise, int seed)
{
  int *v5; // edi
  unsigned int j; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int k; // esi
  unsigned int v10; // eax
  unsigned int l; // ecx
  signed int v12; // esi
  signed int v13; // edi
  int v14; // eax
  unsigned int *v15; // edi
  unsigned int v16; // ebx
  int v17; // edx
  int v18; // ebx
  unsigned int v19; // eax
  int v22; // edx
  unsigned __int8 v23; // of
  int v24; // ebx
  unsigned int v26; // eax
  unsigned int v27; // eax
  int v28; // edx
  int v29; // ecx
  _D3DSURFACE_DESC desc; // [esp+Ch] [ebp-50h]
  _D3DLOCKED_RECT rc; // [esp+28h] [ebp-34h]
  int sHeight; // [esp+30h] [ebp-2Ch]
  int cntrx; // [esp+34h] [ebp-28h]
  int cntry; // [esp+38h] [ebp-24h]
  unsigned int *pSourceBits; // [esp+3Ch] [ebp-20h]
  unsigned int *pPixel; // [esp+40h] [ebp-1Ch]
  int scale; // [esp+44h] [ebp-18h]
  int mipLevels; // [esp+48h] [ebp-14h]
  int y; // [esp+4Ch] [ebp-10h]
  int x; // [esp+50h] [ebp-Ch]
  D3DTexture *pTexture; // [esp+54h] [ebp-8h]
  int i; // [esp+58h] [ebp-4h]

  v5 = 0;
  for ( j = (unsigned int)width >> 1; j; j >>= 1 )
    v5 = (int *)((char *)v5 + 1);
  v7 = 0;
  v8 = (unsigned int)height >> 1;
  for ( k = (unsigned int)height >> 1; k; k >>= 1 )
    ++v7;
  if ( (unsigned int)v5 <= v7 )
  {
    for ( l = 0; v8; v8 >>= 1 )
      ++l;
  }
  else
  {
    v10 = (unsigned int)width >> 1;
    for ( l = 0; v10; v10 >>= 1 )
      ++l;
  }
  mipLevels = l;
  D3DDevice_CreateTexture(v5, k, width, height, l, 0, D3DFMT_A8R8G8B8, 1u, &pTexture);
  for ( i = 0; i < mipLevels; ++i )
  {
    D3DTexture_GetLevelDesc(pTexture, i, &desc);
    D3DTexture_LockRect(pTexture, i, &rc, 0, 0);
    v12 = width >> i;
    v13 = height >> i;
    v14 = 4096 / (width >> i);
    sHeight = height >> i;
    scale = 1;
    while ( v14 != 1 )
    {
      ++scale;
      v14 >>= 1;
    }
    cntrx = (v12 - 1) / 2;
    cntry = (v13 - 1) / 2;
    pSourceBits = (unsigned int *)MemAllocContiguous((v13 - 1) >> 31, 1, v12, 4 * v12 * v13, 0x80u);
    pPixel = pSourceBits;
    for ( y = 0; y < v13; ++y )
    {
      x = 0;
      if ( v12 > 0 )
      {
        do
        {
          v15 = pPixel;
          v16 = ((y - cntry) << scale) * ((y - cntry) << scale) + ((x - cntrx) << scale) * ((x - cntrx) << scale);
          v17 = 0x1000000 - v16;
          if ( v16 > 0x1000000 )
            v17 = 0;
          v18 = v17;
          v19 = (unsigned int)noise * (unsigned __int64)(unsigned int)v17 >> 32;
          _EDX = seed;
          __asm { rcl     ecx, 0Dh }
          seed = _ECX - (seed - 11);
          v22 = (unsigned int)seed * (unsigned __int64)v19 >> 32 << 15;
          v23 = __OFSUB__(v18, v22);
          v24 = v18 - v22;
          if ( (v24 < 0) ^ v23 )
            v24 = 0;
          _EBX = v24 & 0x1FF0000;
          __asm { rcl     ebx, 8 }
          v26 = (unsigned __int16)(HIBYTE(_EBX) * HIBYTE(_EBX))
              * (unsigned int)(unsigned __int16)(HIBYTE(_EBX) * HIBYTE(_EBX)) >> 16;
          v27 = (v26 * v26 >> 16) & 0xFF00 | (((v26 * v26 >> 16) & 0xFF00) >> 8);
          *pPixel = v27 | (v27 << 16);
          pPixel = v15 + 1;
          ++x;
        }
        while ( x < v12 );
        v13 = sHeight;
      }
    }
    XGSwizzleRect(pSourceBits, 0, 0, rc.pBits, v12, v13, 0, 4u);
    MemFreeContiguous(v28, v29, (int *)v13, pSourceBits);
  }
  return pTexture;
}