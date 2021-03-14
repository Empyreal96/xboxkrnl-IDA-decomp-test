void __usercall IdexCdRomStartRawRead(_IRP *Irp@<ecx>, int *a2@<edi>)
{
  _IO_STACK_LOCATION *v2; // eax
  bool v3; // zf
  unsigned int v4; // esi
  __int64 v5; // rax
  int *v6; // edi
  ULONG v7; // ecx
  unsigned int v8; // ebx
  _IRP *v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // esi
  int v13; // esi
  _IRP *v14; // ecx
  _CDB Cdb; // [esp+0h] [ebp-14h]
  _IRP *v16; // [esp+10h] [ebp-4h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  v3 = v2->Parameters.Read.ByteOffset.LowPart == 16;
  v16 = Irp;
  if ( !v3 )
  {
    IdexChannelInvalidParameterRequest(Irp, a2);
    return;
  }
  v4 = v2->Parameters.Create.Options;
  HIDWORD(v5) = *(_DWORD *)(v4 + 4);
  v6 = *(int **)v4;
  LODWORD(v5) = *(_DWORD *)v4;
  v7 = v5 >> 11;
  v8 = 2352 * *(_DWORD *)(v4 + 8);
  if ( *(_DWORD *)(v4 + 8) > 0x38u || v8 > 0x20000 || *(_QWORD *)v4 + v8 > IdexCdRomPartitionLength )
  {
    v9 = v16;
    goto LABEL_17;
  }
  v9 = v16;
  if ( (_DWORD)v16->UserBuffer & 1 )
  {
LABEL_17:
    v14 = v9;
    goto LABEL_18;
  }
  v16->IoStatus.Information = v8;
  *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
  *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
  v6 = (int *)&v16;
  Cdb.CDB6GENERIC.OperationCode = -66;
  Cdb.CDB10.LogicalBlock = RtlUlongByteSwap(v7);
  *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = *(unsigned __int8 *)(v4 + 8);
  Cdb.CDB10.TransferBlocksMsb = *(_WORD *)(v4 + 8) >> 8;
  Cdb.CDB10.Reserved2 = *(_BYTE *)(v4 + 10);
  v12 = *(_DWORD *)(v4 + 12);
  if ( !v12 )
  {
    Cdb.NEC_READ_CDDA.Reserved0 = Cdb.NEC_READ_CDDA.Reserved0 & 0xEF | 0xC;
    LOBYTE(v11) = Cdb.CDB12.TransferLength[3] & 0xF | 0xB0;
    Cdb.CDB12.TransferLength[3] = Cdb.CDB12.TransferLength[3] & 0xF | 0xB0;
    goto LABEL_15;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    LOBYTE(v11) = Cdb.NEC_READ_CDDA.Reserved0 & 0xF7 | 0x14;
    goto LABEL_13;
  }
  if ( v13 == 1 )
  {
    LOBYTE(v11) = Cdb.NEC_READ_CDDA.Reserved0 & 0xE7 | 4;
LABEL_13:
    Cdb.CDB12.TransferLength[3] |= 0xF0u;
    Cdb.NEC_READ_CDDA.Reserved0 = v11;
LABEL_15:
    unk_8005135E = 0;
    IdexCdRomIssueAtapiRequest(
      v10,
      v11,
      (int *)&v16,
      &Cdb,
      v16->UserBuffer,
      v8,
      0,
      (void (__stdcall *)())IdexCdRomFinishGeneric);
    return;
  }
  v14 = v16;
LABEL_18:
  IdexChannelInvalidParameterRequest(v14, v6);
}