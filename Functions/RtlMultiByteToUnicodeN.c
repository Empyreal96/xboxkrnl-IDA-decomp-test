int __stdcall RtlMultiByteToUnicodeN(unsigned __int16 *UnicodeString, unsigned int MaxBytesInUnicodeString, unsigned int *BytesInUnicodeString, char *MultiByteString, unsigned int BytesInMultiByteString)
{
  unsigned int v5; // eax
  char *v6; // ecx
  unsigned int v7; // edx
  unsigned __int16 *v8; // eax

  v5 = MaxBytesInUnicodeString >> 1;
  if ( MaxBytesInUnicodeString >> 1 >= BytesInMultiByteString )
    v5 = BytesInMultiByteString;
  if ( BytesInUnicodeString )
    *BytesInUnicodeString = 2 * v5;
  if ( v5 )
  {
    v6 = MultiByteString;
    v7 = v5;
    v8 = UnicodeString;
    do
    {
      *v8 = (unsigned __int8)*v6;
      ++v8;
      ++v6;
      --v7;
    }
    while ( v7 );
  }
  return 0;
}