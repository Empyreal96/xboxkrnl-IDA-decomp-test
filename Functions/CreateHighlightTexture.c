D3DTexture *__stdcall CreateHighlightTexture(int size, int power, bool b_falloff_alpha, float f_linear_w, float f_cos_w)
{
  int v5; // esi
  int v6; // edi
  __int64 v7; // rax
  int v8; // ecx
  long double v9; // st7
  float *v10; // ecx
  int j; // eax
  int v12; // eax
  int v13; // ebx
  float x; // ST1C_4
  double v15; // st7
  double v16; // st7
  char v17; // cl
  unsigned __int16 v18; // dx
  bool v19; // zf
  int v20; // edx
  int v21; // ecx
  char cosTable[257]; // [esp+10h] [ebp-150h]
  _D3DSURFACE_DESC desc; // [esp+114h] [ebp-4Ch]
  float ooRadius; // [esp+130h] [ebp-30h]
  int v26; // [esp+134h] [ebp-2Ch]
  _D3DLOCKED_RECT rc; // [esp+138h] [ebp-28h]
  unsigned int c; // [esp+140h] [ebp-20h]
  float Sin; // [esp+144h] [ebp-1Ch]
  int v30; // [esp+148h] [ebp-18h]
  unsigned int *pSourceBits; // [esp+14Ch] [ebp-14h]
  float indexShift; // [esp+150h] [ebp-10h]
  int i; // [esp+154h] [ebp-Ch]
  float Cos; // [esp+158h] [ebp-8h]
  float f_sum; // [esp+15Ch] [ebp-4h]

  v5 = size;
  v6 = 0;
  D3DDevice_CreateTexture(0, size, size, size, 1u, 0, D3DFMT_A8R8G8B8, 0, (D3DTexture **)&size);
  D3DTexture_GetLevelDesc((D3DTexture *)size, 0, &desc);
  D3DTexture_LockRect((D3DTexture *)size, 0, &rc, 0, 0);
  pSourceBits = (unsigned int *)(v5 / 2);
  v7 = v5 - 1;
  v30 = (signed int)v7 / 2;
  ooRadius = 1.0 / (double)(v5 / 2);
  pSourceBits = (unsigned int *)MemAllocContiguous(SHIDWORD(v7), v8, v5, 4 * v5 * v5, 0x80u);
  indexShift = COERCE_FLOAT(&Cos);
  c = (unsigned int)&Sin;
  i = 0;
  v26 = (int)&f_sum;
  do
  {
    f_sum = (double)i * 0.00390625;
    v9 = *(float *)v26;
    v10 = (float *)c;
    *(float *)LODWORD(indexShift) = cos(v9);
    *v10 = sin(v9);
    for ( j = power; j; Cos = Cos * Cos )
      --j;
    f_sum = ((double)(256 - v6) * 0.00390625 * f_linear_w + Cos * f_cos_w) * 255.0;
    cosTable[i] = (signed int)f_sum;
    i = ++v6;
  }
  while ( v6 < 256 );
  f_linear_w = 0.0;
  if ( v5 > 0 )
  {
    v6 = -v30;
    f_cos_w = *(float *)&pSourceBits;
    do
    {
      power = LODWORD(f_cos_w);
      if ( SLODWORD(f_linear_w) > 0 )
      {
        v12 = v6 * v6;
        v13 = -v30;
        v26 = v6 * v6;
        i = -v30;
        f_sum = f_linear_w;
        while ( 1 )
        {
          LODWORD(indexShift) = v12 + v13 * v13;
          x = (double)SLODWORD(indexShift);
          v15 = fast_sqrt(x);
          v16 = v15 * ooRadius;
          if ( v16 >= 1.0 )
          {
            *(_DWORD *)power = 0;
          }
          else
          {
            indexShift = v16 * 256.0;
            c = (unsigned __int8)cosTable[indexShift];
            v17 = b_falloff_alpha ? (_BYTE)c : -1;
            v13 = i;
            LOBYTE(v18) = 0;
            HIBYTE(v18) = v17;
            *(_DWORD *)power = c | ((c | ((c | v18) << 8)) << 8);
          }
          power += 4;
          ++v13;
          v19 = LODWORD(f_sum)-- == 1;
          i = v13;
          if ( v19 )
            break;
          v12 = v26;
        }
      }
      ++LODWORD(f_linear_w);
      LODWORD(f_cos_w) += 4 * v5;
      ++v6;
    }
    while ( SLODWORD(f_linear_w) < v5 );
  }
  XGSwizzleRect(pSourceBits, 0, 0, rc.pBits, v5, v5, 0, 4u);
  MemFreeContiguous(v20, v21, (int *)v6, pSourceBits);
  return (D3DTexture *)size;
}