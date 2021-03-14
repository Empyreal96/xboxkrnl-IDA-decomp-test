void __fastcall CreateIntensityTexture_8Bit(int a1, int a2, D3DTexture **ppTextures, int num, int size, int noise, int seed, int intensity_seed, int intensity_max)
{
  int v9; // esi
  int *v10; // edi
  _BYTE *v11; // edx
  int v12; // ecx
  int v13; // ebx
  int v14; // edi
  int v15; // eax
  char *v16; // esi
  char *v17; // eax
  char *v18; // ecx
  int v19; // edx
  int v20; // edi
  int v21; // edi
  char v22; // al
  int v23; // ecx
  char *v24; // esi
  int v25; // eax
  int v26; // edi
  int v27; // edi
  char v28; // al
  int v29; // ecx
  int v30; // eax
  int i; // edi
  _D3DLOCKED_RECT rcs[3]; // [esp+0h] [ebp-40h]
  int v33; // [esp+18h] [ebp-28h]
  int tex_size; // [esp+1Ch] [ebp-24h]
  QRand rng; // [esp+20h] [ebp-20h]
  int v36; // [esp+24h] [ebp-1Ch]
  char *v37; // [esp+28h] [ebp-18h]
  char *v38; // [esp+2Ch] [ebp-14h]
  int curStep; // [esp+30h] [ebp-10h]
  char *pSourceBits; // [esp+34h] [ebp-Ch]
  int curSize; // [esp+38h] [ebp-8h]
  int curY; // [esp+3Ch] [ebp-4h]
  _D3DLOCKED_RECT *bSecondPass; // [esp+48h] [ebp+8h]
  bool bSecondPass_3; // [esp+4Bh] [ebp+Bh]
  int rx; // [esp+54h] [ebp+14h]
  int rxa; // [esp+54h] [ebp+14h]
  int rxb; // [esp+54h] [ebp+14h]
  char bSquare_3; // [esp+5Bh] [ebp+1Bh]
  int curX; // [esp+5Ch] [ebp+1Ch]

  if ( num <= 3 )
  {
    v9 = size;
    tex_size = size * size;
    if ( num > 0 )
    {
      v10 = (int *)ppTextures;
      bSecondPass = rcs;
      v37 = (char *)num;
      do
      {
        D3DDevice_CreateTexture(v10, size, size, size, 1u, 0, D3DFMT_A8, 1u, (D3DTexture **)v10);
        D3DTexture_LockRect((D3DTexture *)*v10, 0, bSecondPass, 0, 0);
        ++bSecondPass;
        ++v10;
        --v37;
      }
      while ( v37 );
    }
    v11 = (_BYTE *)MemAllocContiguous(a2, a1, size, size * size * num, 0x80u);
    memset(v11, 0, num * size * size);
    v12 = size >> 1;
    rng.seed = seed;
    v13 = noise >> 1;
    pSourceBits = v11;
    *v11 = intensity_seed;
    curSize = size >> 1;
    curX = size >> 1;
    curY = size >> 1;
    curStep = size;
    bSquare_3 = 1;
    bSecondPass_3 = 0;
    if ( size >> 1 > 0 )
    {
      while ( 1 )
      {
        v11 = (_BYTE *)curY;
        rx = v12 + curX;
        v14 = curX - v12;
        v15 = curY - v12;
        v12 += curY;
        if ( v14 < 0 )
          v14 += v9;
        if ( rx >= v9 )
          rx -= v9;
        if ( v15 < 0 )
          v15 += v9;
        if ( v12 >= v9 )
          v12 -= v9;
        if ( bSquare_3 )
        {
          if ( num > 0 )
          {
            v16 = &pSourceBits[curX + size * curY];
            v17 = &pSourceBits[v14 + size * v15];
            v18 = &pSourceBits[v14 + size * v12];
            v19 = rx - v14;
            v37 = v17;
            v38 = v18;
            rxa = rx - v14;
            v36 = num;
            while ( 1 )
            {
              v20 = ((unsigned __int8)*v18
                   + (unsigned __int8)*v17
                   + (unsigned __int8)v17[v19]
                   + (unsigned __int8)v18[v19]) >> 2;
              v21 = QRand::Rand(&rng, 2 * v13) - v13 + v20;
              v22 = intensity_max;
              v23 = intensity_max;
              if ( intensity_max >= v21 )
                v23 = v21;
              if ( v23 >= 0 )
              {
                if ( intensity_max >= v21 )
                  v22 = v21;
              }
              else
              {
                v22 = 0;
              }
              *v16 = v22;
              v38 += tex_size;
              v37 += tex_size;
              v16 += tex_size;
              if ( !--v36 )
                break;
              v17 = v37;
              v18 = v38;
              v19 = rxa;
            }
          }
          v12 = curStep;
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
          v11 = (_BYTE *)num;
          if ( num > 0 )
          {
            v38 = &pSourceBits[curX + size * v15];
            v37 = &pSourceBits[curX + size * v12];
            v24 = &pSourceBits[v14 + size * curY];
            v25 = rx - v14;
            rxb = rx - v14;
            v33 = curX - v14;
            v36 = num;
            while ( 1 )
            {
              v26 = ((unsigned __int8)*v37 + (unsigned __int8)*v38 + (unsigned __int8)*v24 + (unsigned __int8)v24[v25]) >> 2;
              v27 = QRand::Rand(&rng, 2 * v13) - v13 + v26;
              v28 = intensity_max;
              v29 = intensity_max;
              if ( intensity_max >= v27 )
                v29 = v27;
              if ( v29 >= 0 )
              {
                if ( intensity_max >= v27 )
                  v28 = v27;
              }
              else
              {
                v28 = 0;
              }
              v12 = v33;
              v24[v33] = v28;
              v37 += tex_size;
              v38 += tex_size;
              v24 += tex_size;
              if ( !--v36 )
                break;
              v25 = rxb;
            }
          }
          curX += curStep;
          if ( curX >= size )
          {
            curY += curStep;
            if ( curY < size )
            {
              curX = bSecondPass_3 == 0 ? curSize : 0;
            }
            else
            {
              v30 = curSize;
              if ( bSecondPass_3 )
              {
                curStep = curSize;
                v30 = curSize >> 1;
                curSize = v30;
                v13 >>= 1;
                curX = v30;
                bSquare_3 = 1;
              }
              else
              {
                curX = 0;
              }
              curY = v30;
              bSecondPass_3 = bSecondPass_3 == 0;
            }
          }
        }
        v9 = size;
        if ( curSize <= 0 )
          break;
        v12 = curSize;
      }
    }
    for ( i = 0; i < num; ++i )
      XGSwizzleRect(pSourceBits, 0, 0, rcs[i].pBits, v9, v9, 0, 1u);
    MemFreeContiguous((int)v11, v12, (int *)i, pSourceBits);
  }
}