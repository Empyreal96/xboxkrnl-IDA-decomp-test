int __stdcall BitLen(unsigned int *A, unsigned int N)
{
  unsigned int v2; // eax
  unsigned int v3; // edx
  int result; // eax
  signed int v5; // ecx

  v2 = N;
  if ( N )
  {
    while ( 1 )
    {
      v3 = A[v2-- - 1];
      if ( v3 )
        break;
      if ( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    --v2;
  }
  if ( v2 == -1 )
    return 0;
  v5 = A[v2];
  for ( result = 32 * (v2 + 1); v5 >= 0; --result )
    v5 *= 2;
  return result;
}