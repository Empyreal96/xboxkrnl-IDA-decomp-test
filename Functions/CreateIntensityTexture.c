D3DTexture *__stdcall CreateIntensityTexture(int size, bool b_convert_to_normal_map, float f_height_scale, int noise, int seed, int clr_mask, int intensity_seed, bool b_use_intensity_seed, unsigned int intensity_max, int negative_prob)
{
  unsigned int esi1; // esi
  int v11; // edx
  int v12; // ecx
  _DWORD *v13; // ebx
  int v14; // eax
  int v15; // edi
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  unsigned int v19; // edi
  unsigned int v20; // edi
  unsigned int v21; // edi
  unsigned int v22; // edi
  int v23; // eax
  bool v24; // sf
  unsigned __int8 v25; // of
  int v26; // eax
  int v27; // esi
  unsigned int *v28; // ecx
  unsigned int v29; // eax
  double v30; // st7
  unsigned int v31; // esi
  unsigned int v32; // eax
  double v33; // st7
  int v34; // eax
  double v35; // st4
  signed int v36; // eax
  double v37; // st4
  float vPoint10_8; // ST34_4
  int v39; // edx
  int v40; // ecx
  _D3DVECTOR v; // [esp+18h] [ebp-6Ch]
  _D3DVECTOR v10; // [esp+24h] [ebp-60h]
  _D3DVECTOR v01; // [esp+30h] [ebp-54h]
  _D3DVECTOR vPoint00; // [esp+3Ch] [ebp-48h]
  _D3DVECTOR vPoint01; // [esp+48h] [ebp-3Ch]
  _D3DLOCKED_RECT rc; // [esp+54h] [ebp-30h]
  unsigned int v48; // [esp+5Ch] [ebp-28h]
  D3DTexture *pTex; // [esp+60h] [ebp-24h]
  unsigned int *pPixel; // [esp+64h] [ebp-20h]
  int v51; // [esp+68h] [ebp-1Ch]
  int curStep; // [esp+6Ch] [ebp-18h]
  int uy; // [esp+70h] [ebp-14h]
  int curNoise; // [esp+74h] [ebp-10h]
  QRand rng; // [esp+78h] [ebp-Ch]
  int curSize; // [esp+7Ch] [ebp-8h]
  int curY; // [esp+80h] [ebp-4h]
  int y; // [esp+8Ch] [ebp+8h]
  int x; // [esp+90h] [ebp+Ch]
  int rx; // [esp+98h] [ebp+14h]
  int rxa; // [esp+98h] [ebp+14h]
  int rxb; // [esp+98h] [ebp+14h]
  int bSquare; // [esp+9Ch] [ebp+18h]
  char bSquare_3; // [esp+9Fh] [ebp+1Bh]
  int curX; // [esp+A4h] [ebp+20h]
  unsigned int curXa; // [esp+A4h] [ebp+20h]
  unsigned int pTooFar; // [esp+A8h] [ebp+24h]
  bool pTooFar_3; // [esp+ABh] [ebp+27h]
  float intensity_maxa; // [esp+ACh] [ebp+28h]
  unsigned __int8 *negative_proba; // [esp+B0h] [ebp+2Ch]

  D3DDevice_CreateTexture(0, size, size, size, 1u, 0, D3DFMT_A8R8G8B8, 1u, &pTex);
  D3DTexture_LockRect(pTex, 0, &rc, 0, 0);
  esi1 = 4 * size * size;
  v48 = esi1;
  v13 = (_DWORD *)MemAllocContiguous(v11, v12, esi1, esi1, 0x80u);
  memset(v13, 0, 4 * (esi1 >> 2));
  pPixel = v13;
  rng.seed = seed;
  if ( b_use_intensity_seed )
    v14 = intensity_seed;
  else
    v14 = QRand::Rand(&rng, intensity_max);
  v15 = size;
  *v13 = v14 | ((v14 | (v14 << 8)) << 8);
  v16 = size >> 1;
  curSize = size >> 1;
  curX = size >> 1;
  curY = size >> 1;
  curNoise = noise >> 1;
  curStep = size;
  bSquare_3 = 1;
  pTooFar_3 = 0;
  if ( size >> 1 > 0 )
  {
    while ( 1 )
    {
      rx = v16 + curX;
      v17 = curX - v16;
      v18 = curY - v16;
      uy = v16 + curY;
      if ( curX - v16 < 0 )
        v17 += size;
      if ( rx >= size )
        rx -= size;
      if ( v18 < 0 )
        v18 += size;
      if ( uy >= size )
        uy -= size;
      if ( bSquare_3 )
      {
        v19 = ((v13[v17 + size * uy] & 0xFF)
             + (v13[size * uy + rx] & 0xFF)
             + (v13[v17 + size * v18] & 0xFF)
             + (v13[size * v18 + rx] & 0xFFu)) >> 2;
        if ( QRand::Rand(&rng, 100) <= negative_prob )
        {
          v20 = v19 - QRand::Rand(&rng, curNoise);
          if ( v20 > 0xFF )
            v20 = 0;
        }
        else
        {
          v20 = QRand::Rand(&rng, curNoise) + v19;
          if ( v20 > intensity_max )
            v20 = intensity_max;
        }
        v13[curX + size * curY] = v20 | ((v20 | (v20 << 8)) << 8);
        curX += curStep;
        if ( curX >= size )
        {
          curY += curStep;
          curX = curSize;
          if ( curY >= size )
          {
            curY = 0;
            bSquare_3 = 0;
          }
        }
      }
      else
      {
        v51 = size * curY;
        v21 = ((v13[v17 + size * curY] & 0xFF)
             + (v13[size * curY + rx] & 0xFF)
             + (v13[curX + size * v18] & 0xFF)
             + (v13[curX + size * uy] & 0xFFu)) >> 2;
        if ( QRand::Rand(&rng, 100) <= negative_prob )
        {
          v22 = v21 - QRand::Rand(&rng, curNoise);
          if ( v22 > 0xFF )
            v22 = 0;
        }
        else
        {
          v22 = QRand::Rand(&rng, curNoise) + v21;
          if ( v22 > intensity_max )
            v22 = intensity_max;
        }
        v23 = curStep + curX;
        v25 = __OFSUB__(curStep + curX, size);
        v24 = curStep + curX - size < 0;
        v13[curX + v51] = v22 | ((v22 | (v22 << 8)) << 8);
        curX = v23;
        if ( !(v24 ^ v25) )
        {
          curY += curStep;
          if ( curY < size )
          {
            curX = pTooFar_3 == 0 ? curSize : 0;
          }
          else
          {
            v26 = curSize;
            if ( pTooFar_3 )
            {
              curStep = curSize;
              v26 = curSize >> 1;
              curNoise >>= 1;
              curSize = v26;
              curX = v26;
              bSquare_3 = 1;
            }
            else
            {
              curX = 0;
            }
            curY = v26;
            pTooFar_3 = pTooFar_3 == 0;
          }
        }
      }
      if ( curSize <= 0 )
        break;
      v16 = curSize;
    }
    esi1 = v48;
    v15 = size;
  }
  v27 = (int)v13 + esi1;
  pTooFar = v27;
  if ( v13 != (_DWORD *)v27 )
  {
    do
    {
      v28 = pPixel;
      *pPixel = (*pPixel << 24) | clr_mask & *pPixel;
      pPixel = v28 + 1;
    }
    while ( v28 + 1 != (unsigned int *)v27 );
  }
  if ( b_convert_to_normal_map )
  {
    y = 0;
    if ( v15 > 0 )
    {
      bSquare = (int)(v13 + 1);
      curXa = (unsigned int)&v13[v15];
      do
      {
        v29 = curXa;
        if ( curXa >= pTooFar )
          v29 = pTooFar;
        v30 = (double)y;
        x = 0;
        v31 = bSquare;
        intensity_maxa = v30;
        negative_proba = (unsigned __int8 *)(v29 + 2);
        vPoint01.y = v30 + 0.1;
        do
        {
          v32 = v31;
          if ( v31 >= pTooFar )
            v32 = pTooFar;
          v33 = (double)x;
          v34 = *(unsigned __int8 *)(v32 + 2);
          rxa = *(unsigned __int8 *)(v31 - 2);
          vPoint00.y = intensity_maxa;
          v35 = (double)rxa;
          rxb = v34;
          v36 = *negative_proba;
          v37 = v35 * f_height_scale;
          vPoint00.z = v37;
          vPoint10_8 = (double)rxb * f_height_scale;
          vPoint01.x = v33;
          vPoint01.z = (double)v36 * f_height_scale;
          v10.x = v33 + 0.1 - v33;
          v10.y = intensity_maxa - intensity_maxa;
          v10.z = vPoint10_8 - v37;
          v01.x = vPoint01.x - v33;
          v01.y = vPoint01.y - intensity_maxa;
          v01.z = vPoint01.z - vPoint00.z;
          Cross(&v10, &v01, &v);
          Normalize(&v);
          ++x;
          negative_proba += 4;
          *(_DWORD *)(v31 - 4) = VectorToRGBA(&v);
          v31 += 4;
        }
        while ( x < v15 );
        ++y;
        bSquare += 4 * v15;
        curXa += 4 * v15;
      }
      while ( y < v15 );
    }
  }
  XGSwizzleRect(v13, 0, 0, rc.pBits, v15, v15, 0, 4u);
  MemFreeContiguous(v39, v40, (int *)v15, v13);
  return pTex;
}