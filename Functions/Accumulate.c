int __stdcall Accumulate(unsigned int *A, unsigned int B, unsigned int *C, unsigned int N)
{
  unsigned int v5; // ecx
  unsigned int *v6; // esi
  unsigned int v7; // ebp
  unsigned int *v8; // edi
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax

  if ( B == 1 )
    return Add((int)A, (int)A, C, N);
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
          goto mul0;
        case 1u:
          goto mul3;
        case 2u:
          goto mul2;
      }
      while ( 1 )
      {
        LODWORD(v11) = v8[v7 + 1];
        HIDWORD(v11) = (B * (unsigned __int64)v6[v7 + 1] + v5) >> 32;
        v12 = B * v6[v7 + 1] + v5 + v11;
        v8[v7 + 1] = v12;
        v5 = HIDWORD(v12);
mul2:
        LODWORD(v13) = v8[v7 + 2];
        HIDWORD(v13) = (B * (unsigned __int64)v6[v7 + 2] + v5) >> 32;
        v14 = B * v6[v7 + 2] + v5 + v13;
        v8[v7 + 2] = v14;
        v5 = HIDWORD(v14);
mul3:
        LODWORD(v15) = v8[v7 + 3];
        HIDWORD(v15) = (B * (unsigned __int64)v6[v7 + 3] + v5) >> 32;
        v16 = B * v6[v7 + 3] + v5 + v15;
        v8[v7 + 3] = v16;
        v5 = HIDWORD(v16);
        v7 += 4;
        if ( !v7 )
          break;
mul0:
        LODWORD(v9) = v8[v7];
        HIDWORD(v9) = (B * (unsigned __int64)v6[v7] + v5) >> 32;
        v10 = B * v6[v7] + v5 + v9;
        v8[v7] = v10;
        v5 = HIDWORD(v10);
      }
    }
  }
  return v5;
}