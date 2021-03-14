void __userpurge IdexCdRomStartRead(int a1@<edx>, int *a2@<edi>, _IRP *Irp)
{
  _IO_STACK_LOCATION *v3; // ebx
  int v4; // ecx
  unsigned int v5; // esi
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  unsigned __int64 v10; // rax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // esi
  _CDB Cdb; // [esp+8h] [ebp-18h]
  unsigned int NumberOfSectors; // [esp+18h] [ebp-8h]
  unsigned int TransferLength; // [esp+1Ch] [ebp-4h]

  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  TransferLength = v3->Parameters.Create.DesiredAccess;
  v4 = TransferLength;
  if ( TransferLength > 0x20000 )
    TransferLength = 0x20000;
  v5 = TransferLength >> 11;
  NumberOfSectors = TransferLength >> 11;
  if ( IdexCdRomCurrentSpindleSpeed >= IdexCdRomMaximumSpindleSpeed
    || !IdexCdRomCheckForRestoreSpindleSpeed(a1, v4, a2, v3->Parameters.Read.ByteOffset.LowPart, TransferLength >> 11) )
  {
    *(_QWORD *)&Cdb.CDB6GENERIC.OperationCode = 0i64;
    *((_QWORD *)&Cdb.PCDB6VERIFY + 1) = 0i64;
    Cdb.CDB6GENERIC.OperationCode = 40;
    Cdb.CDB10.LogicalBlock = RtlUlongByteSwap(v3->Parameters.Read.ByteOffset.LowPart);
    *(_QWORD *)((char *)&Cdb.CDB6VERIFY + 7) = RtlUshortByteSwap(v5);
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        v6,
        v7,
        0,
        v5,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
        0xA63u,
        0);
    KfRaiseIrql(NewIrql);
    if ( IdexCdRomSelectDeviceAndSpinWhileBusy(v8, v9, 0, v5)
      && (!(Irp->Flags & 0x400) || v3->Flags < 0 ? IdexChannelPrepareBufferTransfer(
                                                     (char *)(v3->Parameters.Create.Options
                                                            + v3->Parameters.Read.ByteOffset.HighPart),
                                                     TransferLength) : IdexChannelPrepareScatterGatherTransfer(
                                                                         v11,
                                                                         SHIDWORD(v10),
                                                                         Irp->SegmentArray,
                                                                         v3->Parameters.FileSystemControl.FsControlCode,
                                                                         TransferLength),
          LOWORD(v12) = 497,
          __outbyte(0x1F1u, 1u),
          IdexCdRomWritePacket(v12, v13, 0, v5, &Cdb)) )
    {
      v15 = unk_8004C824;
      if ( unk_8004C824 && *(_BYTE *)(unk_8004C824 + 8) & 0x20 && *(_DWORD *)(unk_8004C824 + 60) )
      {
        v10 = __rdtsc() / 0x2DD;
        *(_QWORD *)*(_DWORD *)(unk_8004C824 + 60) = v10;
        *(_DWORD *)(*(_DWORD *)(v15 + 60) + 8) ^= ((unsigned __int8)NumberOfSectors ^ (unsigned __int8)*(_DWORD *)(*(_DWORD *)(v15 + 60) + 8)) & 0x7F;
        LODWORD(v10) = *(_DWORD *)(v15 + 60);
        v14 = (*(_DWORD *)(v10 + 8) ^ (v3->Parameters.Read.ByteOffset.LowPart << 7)) & 0x7FFFFF80;
        *(_DWORD *)(v10 + 8) ^= v14;
        v15 = *(_DWORD *)(v15 + 60);
        *(_BYTE *)(v15 + 11) |= 0x80u;
      }
      WORD2(v10) = -160;
      __outbyte(0xFF60u, 9u);
      if ( IdexChannelObject.InterruptRoutine )
        RtlAssert(
          SHIDWORD(v10),
          v14,
          0,
          v15,
          "IdexChannelObject.InterruptRoutine == NULL",
          "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
          0xAA2u,
          0);
      IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexCdRomTransferInterrupt;
      dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexCdRomFinishRead;
      unk_80051359 = 1;
      unk_8005135C = 12;
      KfLowerIrql(2);
    }
    else
    {
      IdexCdRomFinishRead(SBYTE4(v10), 0);
    }
  }
}