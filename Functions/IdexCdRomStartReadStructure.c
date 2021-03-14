void __stdcall IdexCdRomStartReadStructure(_IRP *Irp)
{
  _IO_STACK_LOCATION *v1; // eax
  unsigned int v2; // ebx
  int v3; // esi
  __int64 v4; // rax
  char v5; // cl
  int v6; // edx
  int v7; // ecx
  _CDB Cdb; // [esp+4h] [ebp-14h]
  unsigned int LogicalBlockAddress; // [esp+14h] [ebp-4h]

  v1 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v1->Parameters.Read.ByteOffset.LowPart >= 0x18 )
  {
    v2 = v1->Parameters.Create.DesiredAccess;
    v3 = v1->Parameters.Create.Options;
    if ( v2 < (*(_DWORD *)(v3 + 8) != 0 ? 4 : 21) || v2 > 0xFFFF || v2 & 1 )
    {
      IdexChannelInvalidParameterRequest(Irp, (int *)&Irp->Type);
    }
    else
    {
      v4 = *(_QWORD *)v3 >> 11;
      LogicalBlockAddress = v4;
      IoLockUserBuffer(SHIDWORD(v4), v5, v3, Irp, v2);
      Irp->IoStatus.Information = v2;
      *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
      *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
      Cdb.CDB6GENERIC.OperationCode = -83;
      *((_WORD *)&Cdb.PCDB6VERIFY + 4) = RtlUshortByteSwap(v2);
      Cdb.CDB10.LogicalBlock = RtlUlongByteSwap(LogicalBlockAddress);
      *((_WORD *)&Cdb.PCDB6INQUIRY + 3) = *(unsigned __int8 *)(v3 + 16);
      Cdb.CDB10.TransferBlocksMsb = *(_BYTE *)(v3 + 8);
      if ( *(_BYTE *)(v3 + 16) < 0 )
        Cdb.CDB10.Control = -64;
      if ( *(_DWORD *)(v3 + 8) == 2 )
      {
        LOBYTE(v7) = Cdb.CDB12.Reserved2 & 0x3F;
        Cdb.CDB12.Reserved2 = Cdb.CDB12.Reserved2 & 0x3F | (*(_BYTE *)(v3 + 12) << 6);
      }
      IdexCdRomIssueAtapiRequest(
        v6,
        v7,
        (int *)&LogicalBlockAddress,
        &Cdb,
        Irp->UserBuffer,
        v2,
        0,
        (void (__stdcall *)())IdexCdRomFinishGenericWithOverrun);
    }
  }
  else
  {
    IdexChannelInvalidParameterRequest(Irp, (int *)&Irp->Type);
  }
}