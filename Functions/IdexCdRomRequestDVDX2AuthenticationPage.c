int __fastcall IdexCdRomRequestDVDX2AuthenticationPage(int a1, int a2, _DVDX2_AUTHENTICATION *Authentication)
{
  int result; // eax
  _SCSI_PASS_THROUGH_DIRECT PassThrough; // [esp+8h] [ebp-2Ch]

  memset(&PassThrough, 0, sizeof(PassThrough));
  PassThrough.Length = 44;
  PassThrough.DataIn = 1;
  PassThrough.DataBuffer = Authentication;
  PassThrough.DataTransferLength = 28;
  *(_DWORD *)PassThrough.Cdb = 0;
  *(_DWORD *)&PassThrough.Cdb[4] = 0;
  *(_DWORD *)&PassThrough.Cdb[8] = 0;
  *(_DWORD *)&PassThrough.Cdb[12] = 0;
  *(_WORD *)&PassThrough.Cdb[2] = 62;
  memset(Authentication, 0, sizeof(_DVDX2_AUTHENTICATION));
  PassThrough.Cdb[0] = 90;
  *(_WORD *)&PassThrough.Cdb[7] = 7168;
  result = IoSynchronousDeviceIoControlRequest(0, a2, 0x4D014u, IdexCdRomDeviceObject, &PassThrough, 0x2Cu, 0, 0, 0, 0);
  if ( result >= 0 )
    return Authentication->AuthenticationPage.CDFValid != 1 ? 0xC0000014 : 0;
  if ( result == -1073741482 )
    result = -1073741804;
  return result;
}