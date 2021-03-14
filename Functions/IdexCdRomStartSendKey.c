void __fastcall IdexCdRomStartSendKey(_IRP *Irp)
{
  _IRP *v1; // edi
  _IO_STACK_LOCATION *v2; // eax
  _DWORD *v3; // esi
  unsigned int v4; // ebx
  int v5; // ecx
  int v6; // edx
  _CDB Cdb; // [esp+4h] [ebp-14h]
  _DVD_COPY_PROTECT_KEY *CopyProtectKey; // [esp+14h] [ebp-4h]

  v1 = Irp;
  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->Parameters.Read.ByteOffset.LowPart >= 0x18 )
  {
    v3 = (_DWORD *)v2->Parameters.Create.Options;
    v4 = *v3 - 20;
    CopyProtectKey = (_DVD_COPY_PROTECT_KEY *)v2->Parameters.Create.Options;
    if ( v4 <= 0x20 )
    {
      Irp->IoStatus.Information = 0;
      IdexCdRomStaticTransferBuffer = RtlUshortByteSwap(v4 - 2);
      qmemcpy(byte_80051304, v3 + 6, v4 - 4);
      *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
      *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
      Cdb.CDB6GENERIC.OperationCode = -93;
      *((_WORD *)&Cdb.PCDB6VERIFY + 4) = RtlUshortByteSwap(v4);
      *(unsigned int *)((char *)&Cdb.AsUlong[2] + 2) = (unsigned __int8)((Cdb.CDB12.Reserved2 ^ LOBYTE(CopyProtectKey->KeyType)) & 0x3F ^ Cdb.CDB12.Reserved2);
      *(unsigned int *)((char *)&Cdb.AsUlong[2] + 2) = Cdb.CDB12.Reserved2 & 0x3F | (unsigned __int8)(LOBYTE(CopyProtectKey->SessionId) << 6);
      LOBYTE(v5) = Cdb.CDB12.Reserved2;
      IdexCdRomIssueAtapiRequest(
        v6,
        v5,
        (int *)&CopyProtectKey,
        &Cdb,
        &IdexCdRomStaticTransferBuffer,
        v4,
        1,
        (void (__stdcall *)())IdexCdRomFinishGeneric);
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