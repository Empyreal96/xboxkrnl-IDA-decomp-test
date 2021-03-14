void __stdcall Multiply(unsigned int *A, unsigned int *B, unsigned int *C, unsigned int N)
{
  unsigned int *v4; // esi
  signed int v5; // ebp
  unsigned int *v6; // eax
  unsigned int *v7; // edi

  v4 = A;
  memset(A, 0, 8 * N);
  v5 = N;
  if ( N )
  {
    v6 = &C[N - 1];
    while ( !*v6 )
    {
      --v5;
      --v6;
      if ( !v5 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v5 = 1;
  }
  if ( N )
  {
    v7 = &A[v5];
    do
    {
      *v7 = Accumulate(v4, *(unsigned int *)((char *)v4 + (char *)B - (char *)A), C, v5);
      ++v4;
      ++v7;
      --N;
    }
    while ( N );
  }
}