int __stdcall Sub(int a1, int a2, unsigned int *a3, int a4)
{
  int v4; // ecx
  int result; // eax
  unsigned int *v6; // esi
  unsigned __int64 v7; // kr08_8

  v4 = a4;
  result = 0;
  if ( a4 )
  {
    v6 = a3;
    do
    {
      v7 = *(unsigned int *)((char *)v6 + a2 - (_DWORD)a3) - (unsigned __int64)(unsigned int)result - *v6;
      *(unsigned int *)((char *)v6 + a1 - (_DWORD)a3) = v7;
      result = BYTE4(v7) & 1;
      ++v6;
      --v4;
    }
    while ( v4 );
  }
  return result;
}