int *__usercall IdexCdRomAuthenticationSequence@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  int *result; // eax
  int v5; // edx
  int v6; // ecx
  int *v7; // esi
  _DVDX2_CONTROL_DATA ControlData; // [esp+4h] [ebp-680h]
  _DVDX2_AUTHENTICATION Authentication; // [esp+668h] [ebp-1Ch]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0xE46u,
      0);
  if ( IdexCdRomDVDX2Authenticated )
    return 0;
  result = (int *)IdexCdRomRequestDVDX2AuthenticationPage(a2, a1, &Authentication);
  if ( (signed int)result >= 0 )
  {
    result = (int *)IdexCdRomRequestDVDX2ControlData(v6, v5, &ControlData);
    if ( (signed int)result >= 0 )
    {
      if ( (unsigned __int8)Authentication.AuthenticationPage.DiscCategoryAndVersion != (*(_BYTE *)&ControlData.LayerDescriptor & 0xF)
                                                                                      + 16
                                                                                      * ((unsigned int)*(_BYTE *)&ControlData.LayerDescriptor >> 4) )
      {
        DbgPrint(a3, "IDEX: disc category and version mismatch.\n");
        return (int *)-1073741482;
      }
      if ( Authentication.AuthenticationPage.PartitionArea && Authentication.AuthenticationPage.Authentication )
      {
        IdexCdRomDVDX2Authenticated = 1;
        return 0;
      }
      v7 = (int *)IdexCdRomVerifyDVDX2AuthoringSignature(&ControlData);
      if ( (signed int)v7 >= 0 )
      {
        IdexCdRomDecryptHostChallengeResponseTable(&ControlData);
        if ( ControlData.HostChallengeResponseTable.Version == 1
          && ControlData.HostChallengeResponseTable.NumberOfEntries
          && ControlData.HostChallengeResponseTable.NumberOfEntries <= 0x17u )
        {
          if ( Authentication.AuthenticationPage.DrivePhaseLevel != 1 && ControlData.Features & 1 )
            result = IdexCdRomDoAntiPiracy15Authentication(
                       a3,
                       &ControlData,
                       Authentication.AuthenticationPage.DrivePhaseLevel);
          else
            result = IdexCdRomDoAntiPiracy10Authentication(
                       &ControlData,
                       Authentication.AuthenticationPage.DrivePhaseLevel);
          if ( (signed int)result >= 0 )
          {
            XeCdRomMediaTimeDateStamp = ControlData.TitleTimeDateStamp;
            IdexCdRomDVDX2Authenticated = 1;
            result = 0;
          }
        }
        else
        {
          DbgPrint(a3, "IDEX: invalid host challenge response table.\n");
          result = (int *)-1073741482;
        }
      }
      else
      {
        DbgPrint(a3, "IDEX: failed to verify control data structure (status=%08x).\n");
        result = v7;
      }
    }
  }
  return result;
}