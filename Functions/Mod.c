int __fastcall Mod(int a1, unsigned int *a2, unsigned int *A, unsigned int *B, unsigned int *R, unsigned int T, unsigned int N)
{
  unsigned int v7; // ebx
  unsigned int *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebp
  int *v12; // eax
  unsigned int *v13; // edi
  int v14; // eax
  unsigned int *v15; // edx
  int v16; // ebx
  unsigned int *v17; // esi
  int v18; // ebx
  unsigned int *v19; // ecx
  unsigned int v20; // eax
  unsigned int v21; // eax
  signed int v22; // edi
  unsigned int *v23; // eax
  int v24; // esi
  unsigned int v25; // edx
  bool v26; // sf
  int i; // [esp+10h] [ebp-54h]
  unsigned int *TempB; // [esp+14h] [ebp-50h]
  unsigned int *TempA; // [esp+18h] [ebp-4Ch]
  unsigned int *TempR; // [esp+1Ch] [ebp-48h]
  unsigned int *pdwSlowBuffer; // [esp+20h] [ebp-44h]
  unsigned int dwTemp[16]; // [esp+24h] [ebp-40h]
  unsigned int *Aa; // [esp+68h] [ebp+4h]
  unsigned int *Ta; // [esp+74h] [ebp+10h]

  v7 = T;
  pdwSlowBuffer = 0;
  if ( T )
  {
    v8 = &A[T - 1];
    while ( !*v8 )
    {
      --v7;
      --v8;
      if ( !v7 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v7 = 1;
  }
  v9 = N;
  if ( N )
  {
    a2 = &B[N - 1];
    while ( !*a2 )
    {
      --v9;
      --a2;
      if ( !v9 )
        goto LABEL_10;
    }
    v10 = v9;
    if ( v9 > 1 )
      goto LABEL_13;
  }
  else
  {
LABEL_10:
    v10 = 1;
  }
  if ( !*B )
    return 0;
LABEL_13:
  if ( v7 < v10 )
  {
    qmemcpy(R, A, 4 * N);
    return 1;
  }
  if ( 4 * (v7 + 2 * v10) + 12 <= 0x40 )
  {
    TempA = dwTemp;
  }
  else
  {
    v12 = RSA32Alloc((int)a2, N, (int)B, 4 * (v7 + 2 * v10) + 12);
    pdwSlowBuffer = (unsigned int *)v12;
    if ( !v12 )
      return 0;
    TempA = (unsigned int *)v12;
  }
  v13 = &TempA[v10];
  Ta = v13;
  ++v13;
  TempR = &v13[v10 + 1];
  qmemcpy(v13, B, 4 * (4 * v10 >> 2));
  v13[v10] = 0;
  v14 = v7;
  qmemcpy(TempR, A, 4 * (4 * v7 >> 2));
  v15 = &v13[v10 + 1];
  v16 = v7 - v10;
  TempR[v14] = 0;
  i = v16;
  if ( v16 >= 0 )
  {
    v17 = &TempR[v16];
    v18 = v10 + v16;
    v19 = &TempR[v18];
    TempB = v17;
    for ( Aa = &TempR[v18]; ; v19 = Aa )
    {
      if ( v10 <= 1 )
        v20 = 0;
      else
        v20 = B[v10 - 2];
      v21 = EstimateQuotient(*v19, *(v19 - 1), B[v10 - 1], v20);
      if ( !v21 )
        v21 = 1;
      *Ta = BaseMult(TempA, v21, B, v10);
      while ( 1 )
      {
        v22 = v10;
        if ( (v10 & 0x80000000) != 0 )
          break;
        v23 = Ta;
        v24 = (char *)v17 - (char *)TempA;
        while ( 1 )
        {
          v25 = *(unsigned int *)((char *)v23 + v24);
          if ( *v23 > v25 )
            break;
          if ( *v23 >= v25 )
          {
            --v22;
            --v23;
            if ( v22 >= 0 )
              continue;
          }
          v17 = TempB;
          goto LABEL_35;
        }
        Sub((int)TempA, (int)TempA, Ta + 1, v10 + 1);
        v17 = TempB;
      }
LABEL_35:
      Sub((int)v17, (int)v17, TempA, v10 + 1);
      if ( Compare(v17, Ta + 1, v10 + 1) >= 0 )
      {
        ++i;
        ++Aa;
        ++v17;
      }
      --v17;
      v26 = i-- - 1 < 0;
      --Aa;
      TempB = v17;
      if ( v26 )
        break;
    }
    v15 = TempR;
  }
  qmemcpy(R, v15, 4 * (4 * v10 >> 2));
  memset(&R[v10], 0, 4 * (4 * (N - v10) >> 2));
  if ( pdwSlowBuffer )
    RSA32Free(pdwSlowBuffer);
  return 1;
}