_DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *__stdcall IdexCdRomPickRandomAuthenticationChallenge(_DVDX2_CONTROL_DATA *ControlData, int IndexLimit, unsigned int *UsedIndexBitmap, unsigned int ChallengeLevelBitmap)
{
  unsigned __int64 v4; // rax
  unsigned int v5; // edi
  unsigned int v6; // esi
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *result; // eax
  int StartingIndex; // [esp+4h] [ebp-4h]

  if ( IndexLimit > (unsigned __int8)ControlData->HostChallengeResponseTable.NumberOfEntries )
    IndexLimit = (unsigned __int8)ControlData->HostChallengeResponseTable.NumberOfEntries;
  v4 = __rdtsc();
  v5 = (unsigned int)v4 % IndexLimit;
  v6 = *UsedIndexBitmap;
  StartingIndex = (unsigned int)v4 % IndexLimit;
  while ( 1 )
  {
    result = &ControlData->HostChallengeResponseTable.Entries[v5];
    if ( !((1 << v5) & v6) )
    {
      if ( (1 << result->ChallengeLevel) & ChallengeLevelBitmap )
        break;
    }
    if ( ++v5 == IndexLimit )
      v5 = 0;
    if ( v5 == StartingIndex )
    {
      DbgPrint((int *)v5, "IDEX: failed to find challenge entry (bitmap=%08x).\n", ChallengeLevelBitmap);
      return 0;
    }
  }
  *UsedIndexBitmap = v6 | (1 << v5);
  return result;
}