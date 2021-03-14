int __stdcall RtlUpcaseUnicodeToMultiByteN(char *MultiByteString, unsigned int MaxBytesInMultiByteString, unsigned int *BytesInMultiByteString, unsigned __int16 *UnicodeString, unsigned int BytesInUnicodeString)
{
  unsigned int v5; // eax
  unsigned __int16 *v6; // ecx
  char *v7; // edx
  unsigned int v8; // esi
  char v9; // al
  signed int UnicodeChar; // [esp+Ch] [ebp+Ch]

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
      UnicodeChar = *v6;
      if ( *v6 >= 0x100u )
        UnicodeChar = 63;
      if ( (unsigned __int16)UnicodeChar >= 0x61u )
      {
        if ( (unsigned __int16)UnicodeChar > 0x7Au )
          LOWORD(UnicodeChar) = UnicodeChar
                              - *(_WORD *)(2
                                         * ((UnicodeChar & 0xF)
                                          + 4
                                          * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)(unsigned __int16)UnicodeChar >> 8]
                                                                                          + (((unsigned int)(unsigned __int16)UnicodeChar >> 4) & 0xF)])
                                         - 2147399760);
        else
          UnicodeChar += 65504;
      }
      if ( (unsigned __int16)UnicodeChar >= 0x100u )
        v9 = 63;
      else
        v9 = UnicodeChar;
      ++v6;
      *v7++ = v9;
      --v8;
    }
    while ( v8 );
  }
  return 0;
}