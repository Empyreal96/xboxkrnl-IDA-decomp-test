unsigned int __stdcall BaseMult(unsigned int *A, unsigned int B, unsigned int *C, unsigned int N)
{
  unsigned int result; // eax
  unsigned int v5; // ecx
  unsigned __int64 v6; // rax
  unsigned int OUT_HI; // [esp+4h] [ebp-4h]
  unsigned int Na; // [esp+1Ch] [ebp+14h]

  result = 0;
  OUT_HI = 0;
  if ( B == 1 )
  {
    qmemcpy(A, C, 4 * N);
  }
  else
  {
    Na = 4 * N;
    v5 = 0;
    do
    {
      v6 = OUT_HI + C[v5 / 4] * (unsigned __int64)B;
      OUT_HI = HIDWORD(v6);
      A[v5 / 4] = v6;
      v5 += 4;
    }
    while ( v5 != Na );
    result = HIDWORD(v6);
  }
  return result;
}