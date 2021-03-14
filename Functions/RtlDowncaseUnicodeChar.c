int __stdcall RtlDowncaseUnicodeChar(unsigned __int16 SourceCharacter)
{
  int result; // eax

  result = SourceCharacter;
  if ( SourceCharacter >= 0x41u )
  {
    if ( SourceCharacter > 0x5Au )
      result = (unsigned __int16)(SourceCharacter
                                + *(_WORD *)(2
                                           * ((SourceCharacter & 0xF)
                                            + 4
                                            * (unsigned __int8)Nls844UnicodeLowercaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[(unsigned int)SourceCharacter >> 8]
                                                                                               + ((unsigned __int8)SourceCharacter >> 4)])
                                           - 2147399760));
    else
      result = SourceCharacter + 32;
  }
  return result;
}