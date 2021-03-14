void __usercall IdexCdRomStartReadTOC(_IRP *Irp@<ecx>, int a2@<edx>, int *a3@<edi>)
{
  _IRP *v3; // esi
  unsigned int v4; // ebx
  int v5; // edx
  int v6; // ecx
  _CDB Cdb; // [esp+8h] [ebp-14h]
  _IO_STACK_LOCATION *IrpSp; // [esp+18h] [ebp-4h]

  v3 = Irp;
  v4 = *(_DWORD *)(Irp->Tail.Overlay.PacketType + 4);
  IrpSp = Irp->Tail.Overlay.CurrentStackLocation;
  if ( !v4 || v4 & 1 || (_DWORD)Irp->UserBuffer & 1 )
  {
    IdexChannelInvalidParameterRequest(Irp, a3);
  }
  else
  {
    if ( v4 > 0x324 )
      v4 = 804;
    IoLockUserBuffer(a2, (int)Irp, (int)Irp, Irp, v4);
    *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
    *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
    v3->IoStatus.Information = v4;
    Cdb.CDB6GENERIC.OperationCode = 67;
    *(_WORD *)((char *)&Cdb.CDB6VERIFY + 7) = RtlUshortByteSwap(v4);
    if ( IrpSp->Parameters.Read.ByteOffset.HighPart == 147456 )
      Cdb.NEC_READ_CDDA.Reserved0 |= 2u;
    else
      Cdb.CDB12.TransferLength[3] = Cdb.CDB12.TransferLength[3] & 0x3F | 0x40;
    IdexCdRomIssueAtapiRequest(
      v5,
      v6,
      a3,
      &Cdb,
      v3->UserBuffer,
      v4,
      0,
      (void (__stdcall *)())IdexCdRomFinishGenericWithOverrun);
  }
}