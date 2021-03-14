int __fastcall IdexCdRomRequestDVDX2ControlData(int a1, int a2, _DVDX2_CONTROL_DATA *ControlData)
{
  int v3; // eax
  int v4; // esi
  _SCSI_PASS_THROUGH_DIRECT PassThrough; // [esp+Ch] [ebp-2Ch]
  int savedregs; // [esp+38h] [ebp+0h]

  memset(&PassThrough, 0, sizeof(PassThrough));
  PassThrough.DataBuffer = ControlData;
  PassThrough.Length = 44;
  PassThrough.DataIn = 1;
  PassThrough.DataTransferLength = 1636;
  *(_DWORD *)PassThrough.Cdb = 0;
  *(_DWORD *)&PassThrough.Cdb[8] = 0;
  *(_DWORD *)&PassThrough.Cdb[12] = 0;
  PassThrough.Cdb[0] = -83;
  *(_WORD *)&PassThrough.Cdb[8] = 25606;
  *(_DWORD *)&PassThrough.Cdb[2] = -195841;
  PassThrough.Cdb[6] = -2;
  PassThrough.Cdb[7] = 0;
  PassThrough.Cdb[11] = -64;
  v3 = IoSynchronousDeviceIoControlRequest(0, a2, 0x4D014u, IdexCdRomDeviceObject, &PassThrough, 0x2Cu, 0, 0, 0, 0);
  v4 = v3;
  if ( v3 < 0 )
    DbgPrint(&savedregs, "IDEX: control data read failed (status=%08x).\n", v3);
  return v4;
}