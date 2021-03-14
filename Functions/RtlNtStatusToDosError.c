unsigned int __stdcall RtlNtStatusToDosError(int Status)
{
  unsigned int result; // eax
  int v2; // ecx
  int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned __int16 v6; // cx
  int v7; // esi

  result = Status;
  if ( !(Status & 0x20000000) )
  {
    if ( (_UNKNOWN *)(Status & 0xFFFF0000) == (_UNKNOWN *)((char *)&loc_8006FFFE + 2) )
    {
      result = (unsigned __int16)Status;
    }
    else
    {
      if ( (Status & 0xF0000000) == -805306368 )
        result = Status & 0xCFFFFFFF;
      v2 = 0;
      v3 = 0;
      while ( result >= *(_DWORD *)(8 * v2 - 2147396232) )
      {
        v3 += *(unsigned __int16 *)(8 * v2 - 2147396236) * *(unsigned __int16 *)(8 * v2 - 2147396234);
        if ( (unsigned int)++v2 >= 0x67 )
          goto LABEL_11;
      }
      v4 = 4 * v2;
      v5 = result - RtlpRunTable[v4 / 4].BaseCode;
      if ( v5 >= (unsigned __int16)word_80015574[v4] )
      {
LABEL_11:
        if ( (result & 0xFFFF0000) == -1073676288 )
          result = (unsigned __int16)result;
        else
          result = 317;
        return result;
      }
      v6 = word_80015576[v4];
      v7 = v5 * v6 + v3;
      if ( v6 == 1 )
        result = *(unsigned __int16 *)(2 * v7 - 2147397776);
      else
        result = RtlpStatusTable[v7] | ((unsigned __int16)word_80014F72[v7] << 16);
    }
  }
  return result;
}