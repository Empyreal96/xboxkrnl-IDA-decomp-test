void __usercall IdexCdRomFinishGeneric(char a1@<dl>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  _CDB Cdb; // [esp+0h] [ebp-10h]
  int savedregs; // [esp+10h] [ebp+0h]

  v3 = Irp->IoStatus.Status;
  if ( v3 == -1073741435 )
  {
    *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
    *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
    Cdb.CDB6GENERIC.OperationCode = 3;
    Cdb.CDB6GENERIC.CommandUniqueBytes[2] = 18;
    IdexCdRomIssueAtapiRequest(
      a1,
      (int)Irp,
      &savedregs,
      &Cdb,
      &IdexCdRomStaticTransferBuffer,
      0x12u,
      0,
      (void (__stdcall *)())IdexCdRomFinishRequestSense);
  }
  else if ( v3 == -1073741643 )
  {
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        a1,
        (int)Irp,
        a2,
        a3,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0x4C9u,
        0);
    KfRaiseIrql(NewIrql);
    IdexCdRomResetDevice(v4, v5, a2, a3);
  }
  else
  {
    IofCompleteRequest(Irp, 1, a2);
    dword_80051354();
  }
}