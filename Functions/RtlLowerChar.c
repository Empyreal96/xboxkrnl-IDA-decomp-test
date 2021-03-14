signed int __stdcall RtlLowerChar(char Character)
{
  signed int result; // eax

  if ( (unsigned __int8)Character >= 0x41u )
  {
    if ( (unsigned __int8)Character > 0x5Au )
      LOWORD(result) = *(_WORD *)(2
                                * ((Character & 0xF)
                                 + 4
                                 * (unsigned __int8)Nls844UnicodeLowercaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[0]
                                                                                    + ((unsigned int)(unsigned __int8)Character >> 4)])
                                - 2147399760)
                     + (unsigned __int8)Character;
    else
      LOWORD(result) = (unsigned __int8)Character + 32;
  }
  else
  {
    LOWORD(result) = (unsigned __int8)Character;
  }
  if ( (unsigned __int16)result >= 0x100u )
    result = 63;
  else
    result = (unsigned __int16)result;
  return result;
}