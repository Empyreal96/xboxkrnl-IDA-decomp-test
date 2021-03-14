void __fastcall IdexCdRomStartGetDriveGeometry(_IRP *Irp, int a2)
{
  _CDB Cdb; // [esp+4h] [ebp-10h]
  int savedregs; // [esp+14h] [ebp+0h]

  *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
  *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
  Irp->IoStatus.Information = 24;
  Cdb.CDB6GENERIC.OperationCode = 37;
  IdexCdRomIssueAtapiRequest(
    a2,
    (int)Irp,
    &savedregs,
    &Cdb,
    &IdexCdRomStaticTransferBuffer,
    8u,
    0,
    (void (__stdcall *)())IdexCdRomFinishGetDriveGeometry);
}