void *__cdecl memset(void *a1, int a2, size_t a3)
{
  size_t v3; // edx
  int v4; // eax
  _BYTE *v5; // edi
  int v6; // ecx
  size_t v7; // ecx
  unsigned int v8; // ecx

  v3 = a3;
  if ( !a3 )
    return a1;
  LOBYTE(v4) = a2;
  v5 = a1;
  if ( a3 < 4 )
    goto LABEL_13;
  v6 = -(signed int)a1 & 3;
  if ( v6 )
  {
    v3 = a3 - v6;
    do
    {
      *v5++ = a2;
      --v6;
    }
    while ( v6 );
  }
  v4 = 16843009 * (unsigned __int8)a2;
  v7 = v3;
  v3 &= 3u;
  v8 = v7 >> 2;
  if ( !v8 || (memset32(v5, v4, v8), v5 += 4 * v8, v3) )
  {
LABEL_13:
    do
    {
      *v5++ = v4;
      --v3;
    }
    while ( v3 );
  }
  return a1;
}