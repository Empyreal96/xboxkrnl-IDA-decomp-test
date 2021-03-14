int __stdcall RtlUpcaseUnicodeChar(unsigned __int16 SourceCharacter)
{
  unsigned __int16 v1; // cx

  v1 = SourceCharacter;
  if ( SourceCharacter >= 0x61u )
  {
    if ( SourceCharacter <= 0x7Au )
      return SourceCharacter - 32;
    v1 = SourceCharacter
       - *(_WORD *)(2
                  * ((SourceCharacter & 0xF)
                   + 4
                   * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)SourceCharacter >> 8]
                                                                   + ((unsigned __int8)SourceCharacter >> 4)])
                  - 2147399760);
  }
  return v1;
}