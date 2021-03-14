int *__stdcall IdexCdRomDoAntiPiracy10Authentication(_DVDX2_CONTROL_DATA *ControlData, char DrivePhaseLevel)
{
  unsigned __int64 v2; // rax
  _DVDX2_CONTROL_DATA *v3; // esi
  signed int v4; // eax
  int *v5; // edi
  int *result; // eax
  int StartingIndex; // [esp+Ch] [ebp-4h]
  char FirstChallenge; // [esp+18h] [ebp+8h]

  v2 = __rdtsc();
  v3 = ControlData;
  HIDWORD(v2) = (unsigned int)v2 % (unsigned __int8)ControlData->HostChallengeResponseTable.NumberOfEntries;
  v4 = -1;
  FirstChallenge = 1;
  v5 = (int *)HIDWORD(v2);
  StartingIndex = HIDWORD(v2);
  do
  {
    if ( v3->HostChallengeResponseTable.Entries[(_DWORD)v5].ChallengeLevel == 1 )
    {
      result = IdexCdRomAuthenticationChallenge(
                 v3,
                 DrivePhaseLevel,
                 &v3->HostChallengeResponseTable.Entries[(_DWORD)v5],
                 FirstChallenge,
                 0);
      if ( (signed int)result < 0 )
        return result;
      v4 = (signed int)v5;
      FirstChallenge = 0;
    }
    v5 = (int *)((char *)v5 + 1);
    if ( v5 == (int *)(unsigned __int8)v3->HostChallengeResponseTable.NumberOfEntries )
      v5 = 0;
  }
  while ( v5 != (int *)StartingIndex );
  if ( v4 != -1 )
    return IdexCdRomAuthenticationChallenge(v3, DrivePhaseLevel, &v3->HostChallengeResponseTable.Entries[v4], 0, 1);
  DbgPrint(v5, "IDEX: no usable challenge response entries.\n");
  return (int *)-1073741482;
}