unsigned int __stdcall DigitLen(unsigned int *A, unsigned int N)
{
  unsigned int result; // eax
  unsigned int *v3; // ecx

  result = N;
  if ( !N )
    return 1;
  v3 = &A[N - 1];
  while ( !*v3 )
  {
    --result;
    --v3;
    if ( !result )
      return 1;
  }
  return result;
}