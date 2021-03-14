int *__stdcall IdexCdRomAuthenticationChallenge(_DVDX2_CONTROL_DATA *ControlData, char DrivePhaseLevel, _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *HostChallengeResponseEntry, char FirstChallenge, char FinalChallenge)
{
  _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY *v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  int *v8; // eax
  int *v9; // edi
  int *v10; // eax
  _SCSI_PASS_THROUGH_DIRECT PassThrough; // [esp+Ch] [ebp-4Ch]
  _DVDX2_AUTHENTICATION Authentication; // [esp+38h] [ebp-20h]
  char RetryOnReadError; // [esp+57h] [ebp-1h]

  v5 = HostChallengeResponseEntry;
  RetryOnReadError = HostChallengeResponseEntry->ChallengeLevel == 4;
  memset(&PassThrough, 0, sizeof(PassThrough));
  memset(&Authentication, 0, sizeof(Authentication));
  v6 = 0;
  Authentication.AuthenticationPage = (_DVDX2_AUTHENTICATION_PAGE)(*(_BYTE *)&Authentication.AuthenticationPage & 0xFE | 0x3E);
  Authentication.AuthenticationPage.DiscCategoryAndVersion = (char)ControlData->LayerDescriptor;
  Authentication.AuthenticationPage.DrivePhaseLevel = DrivePhaseLevel;
  Authentication.AuthenticationPage.ChallengeID = HostChallengeResponseEntry->ChallengeID;
  v7 = HostChallengeResponseEntry->ChallengeValue;
  PassThrough.Length = 44;
  *(_WORD *)Authentication.Header.ModeDataLength = 6656;
  Authentication.AuthenticationPage.PageLength = 18;
  Authentication.AuthenticationPage.CDFValid = 1;
  Authentication.AuthenticationPage.ChallengeValue = v7;
  if ( !FirstChallenge )
    Authentication.AuthenticationPage.Authentication = 1;
  if ( FinalChallenge )
    Authentication.AuthenticationPage.PartitionArea = 1;
  while ( 1 )
  {
    PassThrough.DataBuffer = &Authentication;
    PassThrough.DataIn = 0;
    PassThrough.DataTransferLength = 28;
    *(_DWORD *)PassThrough.Cdb = 0;
    *(_DWORD *)&PassThrough.Cdb[4] = 0;
    *(_DWORD *)&PassThrough.Cdb[8] = 0;
    *(_DWORD *)&PassThrough.Cdb[12] = 0;
    PassThrough.Cdb[0] = 85;
    *(_WORD *)&PassThrough.Cdb[7] = 7168;
    v8 = (int *)IoSynchronousDeviceIoControlRequest(
                  v6,
                  (int)v5,
                  0x4D014u,
                  IdexCdRomDeviceObject,
                  &PassThrough,
                  0x2Cu,
                  0,
                  0,
                  0,
                  0);
    v9 = v8;
    if ( (signed int)v8 < 0 )
    {
      if ( v8 != (int *)-1073741668 || !RetryOnReadError )
      {
        DbgPrint(v8, "IDEX: challenge operation failed (status=%08x).\n");
        return v9;
      }
      goto LABEL_12;
    }
    PassThrough.Cdb[2] = PassThrough.Cdb[2] & 0xFE | 0x3E;
    PassThrough.DataIn = 1;
    PassThrough.Cdb[0] = 90;
    *(_WORD *)&PassThrough.Cdb[7] = 7168;
    v10 = (int *)IoSynchronousDeviceIoControlRequest(
                   v6,
                   (int)v5,
                   0x4D014u,
                   IdexCdRomDeviceObject,
                   &PassThrough,
                   0x2Cu,
                   0,
                   0,
                   0,
                   0);
    v9 = v10;
    if ( (signed int)v10 >= 0 )
      break;
    if ( v10 != (int *)-1073741668 || !RetryOnReadError )
    {
      DbgPrint(v10, "IDEX: response operation failed (status=%08x).\n");
      return v9;
    }
LABEL_12:
    RetryOnReadError = 0;
  }
  if ( Authentication.AuthenticationPage.Authentication
    && Authentication.AuthenticationPage.ResponseValue == HostChallengeResponseEntry->ResponseValue )
  {
    return 0;
  }
  DbgPrint(v10, "IDEX: invalid response from drive.\n");
  return (int *)-1073741482;
}