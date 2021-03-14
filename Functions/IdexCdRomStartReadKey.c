void __fastcall IdexCdRomStartReadKey(_IRP *Irp)
{
  _IRP *v1; // edi
  _IO_STACK_LOCATION *v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // edx
  char v7; // al
  int v8; // ecx
  _CDB Cdb; // [esp+4h] [ebp-10h]
  int savedregs; // [esp+14h] [ebp+0h]

  v1 = Irp;
  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->Parameters.Read.ByteOffset.LowPart >= 0x18 )
  {
    v3 = v2->Parameters.Create.Options;
    v4 = v2->Parameters.Create.DesiredAccess;
    if ( v4 >= 0x18 )
    {
      v5 = v4 - 20;
      if ( v4 - 20 <= 0x20 )
      {
        *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
        *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
        Cdb.CDB6GENERIC.OperationCode = -92;
        *((_WORD *)&Cdb.PCDB6VERIFY + 4) = RtlUshortByteSwap(v5);
        v7 = (Cdb.CDB12.Reserved2 ^ *(_BYTE *)(v3 + 8)) & 0x3F ^ Cdb.CDB12.Reserved2;
        Cdb.CDB12.Reserved2 = v7;
        v7 &= 0x3Fu;
        LOBYTE(v8) = v7 | (*(_BYTE *)(v3 + 4) << 6);
        Cdb.CDB12.Reserved2 = v7 | (*(_BYTE *)(v3 + 4) << 6);
        if ( *(_DWORD *)(v3 + 8) == 4 )
          Cdb.CDB10.LogicalBlock = RtlUlongByteSwap(*(_QWORD *)(v3 + 16) >> 11);
        IdexCdRomIssueAtapiRequest(
          v6,
          v8,
          &savedregs,
          &Cdb,
          &IdexCdRomStaticTransferBuffer,
          v5,
          0,
          (void (__stdcall *)())IdexCdRomFinishReadKey);
      }
      else
      {
        DbgPrint((int *)&Irp->Type, "IDEX: transfer length exceeds static buffer length.\n");
        IdexChannelInvalidParameterRequest(v1, (int *)&v1->Type);
      }
    }
    else
    {
      IdexChannelInvalidParameterRequest(Irp, (int *)&Irp->Type);
    }
  }
  else
  {
    IdexChannelInvalidParameterRequest(Irp, (int *)&Irp->Type);
  }
}