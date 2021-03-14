void __stdcall Square(unsigned int *A, unsigned int *B, unsigned int N)
{
  unsigned int *v3; // ebx
  unsigned int v4; // eax
  unsigned int *v5; // ecx
  unsigned int v6; // ebp
  unsigned int *v7; // eax
  unsigned int v8; // esi
  unsigned int *v9; // edi
  int v10; // ebx

  v3 = A;
  memset(A, 0, 8 * N);
  v4 = N;
  if ( N )
  {
    v5 = &B[N - 1];
    while ( !*v5 )
    {
      --v4;
      --v5;
      if ( !v4 )
        goto LABEL_5;
    }
    v6 = v4;
  }
  else
  {
LABEL_5:
    v6 = 1;
  }
  v7 = B;
  v8 = v6 - 1;
  v9 = A + 1;
  if ( v6 != 1 )
  {
    do
    {
      v10 = (int)(v7 + 1);
      v9[v8] = Accumulate(v9, *v7, v7 + 1, v8);
      --v8;
      v9 += 2;
      v7 = (unsigned int *)v10;
    }
    while ( v8 );
    v3 = A;
  }
  Add((int)v3, (int)v3, v3, 2 * v6);
  AccumulateSquares(v3, B, v6);
}