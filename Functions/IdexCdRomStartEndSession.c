void __usercall IdexCdRomStartEndSession(_IRP *Irp@<ecx>, int *a2@<edi>)
{
  _IO_STACK_LOCATION *v2; // eax
  char *v3; // edx
  _CDB Cdb; // [esp+0h] [ebp-10h]
  int savedregs; // [esp+10h] [ebp+0h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->Parameters.Read.ByteOffset.LowPart >= 4
    && (v3 = v2->Parameters.IdexReadWrite.Buffer, v2->Parameters.Create.DesiredAccess >= 4) )
  {
    Irp->IoStatus.Information = 0;
    *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
    *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
    Cdb.CDB6GENERIC.OperationCode = -93;
    *((_WORD *)&Cdb.PCDB6FORMAT + 5) = (unsigned __int8)(*v3 << 6) | 0x3F;
    IdexCdRomIssueAtapiRequest(
      (int)v3,
      (int)Irp,
      &savedregs,
      &Cdb,
      0,
      0,
      0,
      (void (__stdcall *)())IdexCdRomFinishGeneric);
  }
  else
  {
    IdexChannelInvalidParameterRequest(Irp, a2);
  }
}