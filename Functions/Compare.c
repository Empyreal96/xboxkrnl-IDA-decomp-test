int __stdcall Compare(unsigned int *A, unsigned int *B, unsigned int N)
{
  signed int v3; // esi
  unsigned int *v4; // eax
  unsigned int v5; // ecx

  v3 = N - 1;
  if ( (signed int)(N - 1) < 0 )
    return 0;
  v4 = &B[v3];
  while ( 1 )
  {
    v5 = *(unsigned int *)((char *)v4 + (char *)A - (char *)B);
    if ( v5 > *v4 )
      return 1;
    if ( v5 < *v4 )
      break;
    --v3;
    --v4;
    if ( v3 < 0 )
      return 0;
  }
  return -1;
}