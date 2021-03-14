int *__userpurge IdexCdRomDoAntiPiracy15Authentication@<eax>(int *a1@<edi>, _DVDX2_CONTROL_DATA *ControlData, char DrivePhaseLevel)
{
  _DVDX2_CONTROL_DATA *v3; // ebx
  int *result; // eax
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *v5; // edi
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *v6; // eax
  int *v7; // edi
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *v8; // esi
  int *v9; // eax
  bool v10; // zf
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *v11; // eax
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *HostChallengeResponseEntry[3]; // [esp+4h] [ebp-14h]
  int FirstChallenge; // [esp+10h] [ebp-8h]
  unsigned int UsedIndexBitmap; // [esp+14h] [ebp-4h]
  char CompletedChallengeLevel4_3; // [esp+23h] [ebp+Bh]

  UsedIndexBitmap = 0;
  v3 = ControlData;
  HostChallengeResponseEntry[2] = IdexCdRomPickRandomAuthenticationChallenge(ControlData, 23, &UsedIndexBitmap, 2u);
  if ( !HostChallengeResponseEntry[2] )
  {
    DbgPrint(a1, "IDEX: no usable challenge response entries.\n");
    return (int *)-1073741482;
  }
  v5 = IdexCdRomPickRandomAuthenticationChallenge(ControlData, 16, &UsedIndexBitmap, 0x10u);
  HostChallengeResponseEntry[0] = v5;
  if ( !v5
    || (v6 = IdexCdRomPickRandomAuthenticationChallenge(ControlData, 16, &UsedIndexBitmap, 0x20u),
        (HostChallengeResponseEntry[1] = v6) == 0)
    && (v6 = IdexCdRomPickRandomAuthenticationChallenge(ControlData, 16, &UsedIndexBitmap, 0x32u),
        (HostChallengeResponseEntry[1] = v6) == 0) )
  {
    DbgPrint((int *)&v5->ChallengeLevel, "IDEX: no usable challenge response entries.\n");
    return (int *)-1073741482;
  }
  if ( v5 > v6 )
  {
    HostChallengeResponseEntry[0] = v6;
    HostChallengeResponseEntry[1] = v5;
  }
  LOBYTE(FirstChallenge) = 1;
  CompletedChallengeLevel4_3 = 0;
  v7 = 0;
  do
  {
    v8 = HostChallengeResponseEntry[(_DWORD)v7];
    v9 = IdexCdRomAuthenticationChallenge(
           v3,
           DrivePhaseLevel,
           HostChallengeResponseEntry[(_DWORD)v7],
           FirstChallenge,
           0);
    if ( (signed int)v9 >= 0 || v9 != (int *)-1073741668 )
    {
      v10 = v8->ChallengeLevel == 4;
      LOBYTE(FirstChallenge) = 0;
      if ( v10 )
        CompletedChallengeLevel4_3 = 1;
    }
    v7 = (int *)((char *)v7 + 1);
  }
  while ( (unsigned int)v7 < 2 );
  if ( CompletedChallengeLevel4_3 )
    return IdexCdRomAuthenticationChallenge(v3, DrivePhaseLevel, HostChallengeResponseEntry[2], 0, 1);
  v11 = IdexCdRomPickRandomAuthenticationChallenge(v3, 16, &UsedIndexBitmap, 0x10u);
  if ( !v11 )
  {
    DbgPrint(v7, "IDEX: no usable challenge response entries for retry.\n");
    return (int *)-1073741482;
  }
  result = IdexCdRomAuthenticationChallenge(v3, DrivePhaseLevel, v11, FirstChallenge, 0);
  if ( (signed int)result >= 0 )
    return IdexCdRomAuthenticationChallenge(v3, DrivePhaseLevel, HostChallengeResponseEntry[2], 0, 1);
  return result;
}