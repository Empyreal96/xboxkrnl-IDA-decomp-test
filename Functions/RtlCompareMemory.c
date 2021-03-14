SIZE_T __stdcall RtlCompareMemory(const void *Source1, const void *Source2, SIZE_T Length)
{
  _BYTE *v3; // esi
  _DWORD *v4; // edi
  bool v5; // zf
  SIZE_T v6; // ecx
  bool v7; // zf
  SIZE_T v8; // ecx
  _BYTE *v10; // edi
  signed int v11; // ecx

  v3 = Source1;
  v4 = Source2;
  v6 = Length >> 2;
  v5 = Length >> 2 == 0;
  if ( !(Length >> 2) )
    goto LABEL_16;
  do
  {
    if ( !v6 )
      break;
    v5 = *(_DWORD *)v3 == *v4;
    v3 += 4;
    ++v4;
    --v6;
  }
  while ( v5 );
  if ( !v5 )
  {
    v3 -= 4;
    v10 = v4 - 1;
    v11 = 5;
    do
    {
      if ( !v11 )
        break;
      v5 = *v3++ == *v10++;
      --v11;
    }
    while ( v5 );
  }
  else
  {
LABEL_16:
    v8 = Length & 3;
    v7 = v8 == 0;
    if ( !(Length & 3) )
      return Length;
    do
    {
      if ( !v8 )
        break;
      v7 = *v3++ == *(_BYTE *)v4;
      v4 = (_DWORD *)((char *)v4 + 1);
      --v8;
    }
    while ( v7 );
    if ( v7 )
      return Length;
  }
  return v3 - 1 - (_BYTE *)Source1;
}