int __stdcall RtlUnicodeToMultiByteN(char *MultiByteString, unsigned int MaxBytesInMultiByteString, unsigned int *BytesInMultiByteString, unsigned __int16 *UnicodeString, unsigned int BytesInUnicodeString)
{
  unsigned int v5; // eax
  unsigned __int16 *v6; // ecx
  char *v7; // edx
  unsigned int v8; // esi
  char v9; // al

  v5 = BytesInUnicodeString >> 1;
  if ( BytesInUnicodeString >> 1 >= MaxBytesInMultiByteString )
    v5 = MaxBytesInMultiByteString;
  if ( BytesInMultiByteString )
    *BytesInMultiByteString = v5;
  if ( v5 )
  {
    v6 = UnicodeString;
    v7 = MultiByteString;
    v8 = v5;
    do
    {
      if ( *v6 >= 0x100u )
        v9 = 63;
      else
        v9 = *(_BYTE *)v6;
      ++v6;
      *v7++ = v9;
      --v8;
    }
    while ( v8 );
  }
  return 0;
}