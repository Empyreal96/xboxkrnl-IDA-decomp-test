int __stdcall Reduce(unsigned int *A, unsigned int B, unsigned int *C, unsigned int N)
{
  unsigned int v5; // ecx
  unsigned int *v6; // esi
  unsigned int v7; // ebp
  unsigned int *v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // edx

  if ( B == 1 )
    return Sub((int)A, (int)A, C, N);
  v5 = 0;
  if ( B )
  {
    v6 = &C[N];
    if ( N )
    {
      v7 = -N & 0xFFFFFFFC;
      v8 = &A[N];
      switch ( N & 3 )
      {
        case 0u:
          goto mul0_0;
        case 1u:
          goto mul3_0;
        case 2u:
          goto mul2_0;
      }
      while ( 1 )
      {
        v11 = v8[v7 + 1];
        v12 = (B * (unsigned __int64)v6[v7 + 1] + __PAIR__(v11 < v5, v5)) >> 32;
        v8[v7 + 1] = v11 - (B * v6[v7 + 1] + v5);
        v5 = v12;
mul2_0:
        v13 = v8[v7 + 2];
        v14 = (B * (unsigned __int64)v6[v7 + 2] + __PAIR__(v13 < v5, v5)) >> 32;
        v8[v7 + 2] = v13 - (B * v6[v7 + 2] + v5);
        v5 = v14;
mul3_0:
        v15 = v8[v7 + 3];
        v16 = (B * (unsigned __int64)v6[v7 + 3] + __PAIR__(v15 < v5, v5)) >> 32;
        v8[v7 + 3] = v15 - (B * v6[v7 + 3] + v5);
        v5 = v16;
        v7 += 4;
        if ( !v7 )
          break;
mul0_0:
        v9 = v8[v7];
        v10 = (B * (unsigned __int64)v6[v7] + __PAIR__(v9 < v5, v5)) >> 32;
        v8[v7] = v9 - (B * v6[v7] + v5);
        v5 = v10;
      }
    }
  }
  return v5;
}