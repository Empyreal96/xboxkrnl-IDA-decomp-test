void __fastcall IdexCdRomStartCheckVerify(_IRP *Irp)
{
  _CDB Cdb; // [esp+4h] [ebp-10h]
  int savedregs; // [esp+14h] [ebp+0h]

  *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
  *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
  Irp->IoStatus.Information = 0;
  Cdb.CDB6GENERIC.OperationCode = 0;
  unk_8005135E = 0;
  IdexCdRomIssueAtapiRequest(0, (int)Irp, &savedregs, &Cdb, 0, 0, 0, (void (__stdcall *)())IdexCdRomFinishGeneric);
}