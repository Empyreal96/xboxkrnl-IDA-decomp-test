signed int __stdcall RtlUpperChar(char Character)
{
  signed int result; // eax

  if ( (unsigned __int8)Character >= 0x61u )
  {
    if ( (unsigned __int8)Character > 0x7Au )
      LOWORD(result) = (unsigned __int8)Character
                     - *(_WORD *)(2
                                * ((Character & 0xF)
                                 + 4
                                 * (unsigned __int8)Nls844UnicodeUpcaseTableLevel2[(unsigned __int8)Nls844UnicodeCaseTableLevel1[0]
                                                                                 + ((unsigned int)(unsigned __int8)Character >> 4)])
                                - 2147399760);
    else
      LOWORD(result) = (unsigned __int8)Character - 32;
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