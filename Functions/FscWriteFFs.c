int *__userpurge FscWriteFFs@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FSCACHE_EXTENSION *CacheExtension, _IRP *Irp, unsigned __int64 ByteOffset, unsigned int WriteLength)
{
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  void *v11; // ecx
  int *v12; // edi
  int *v13; // edi
  void *v14; // ST08_4
  int v15; // edx
  unsigned int v16; // ecx
  _IO_STACK_LOCATION *v17; // eax
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  _KEVENT IoEvent; // [esp+Ch] [ebp-18h]
  unsigned int WriteBytesRemaining; // [esp+1Ch] [ebp-8h]
  void *CacheBuffer; // [esp+20h] [ebp-4h]
  unsigned int WriteLengtha; // [esp+3Ch] [ebp+18h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      a3,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5CBu,
      0);
  if ( ByteOffset >= CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "ByteOffset < (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5CCu,
      0);
  v7 = ByteOffset + WriteLength;
  if ( ByteOffset + WriteLength > CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "(ByteOffset + WriteLength) <= (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5CDu,
      0);
  if ( ByteOffset & 0xFFF )
    RtlAssert(
      a1,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "BYTE_OFFSET(ByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5CEu,
      0);
  if ( !WriteLength )
    RtlAssert(
      a1,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "WriteLength > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5CFu,
      0);
  if ( (CacheExtension->SectorSize - 1) & WriteLength )
    RtlAssert(
      a1,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "(WriteLength & (CacheExtension->SectorSize - 1)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x5D0u,
      0);
  RtlEnterCriticalSection(&FscWriteFFsLock);
  v12 = (int *)FscMapEmptyBuffer(
                 v8,
                 v9,
                 (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
                 (int)CacheExtension,
                 CacheExtension,
                 ByteOffset,
                 &CacheBuffer);
  if ( (signed int)v12 >= 0 )
  {
    if ( WriteLength > 0x1000 )
      FscInvalidateByteRange(v10, (ByteOffset + 4096) >> 32, v12, CacheExtension, ByteOffset + 4096, WriteLength - 4096);
    v13 = (int *)CacheBuffer;
    v14 = CacheBuffer;
    memset(CacheBuffer, 0xFFu, 0x1000u);
    MmLockUnlockBufferPages(v10, 0, v13 + 1024, (int)CacheExtension, v14, 0x1000u, 0);
    memset32(FscWriteFFsPtes, *(_DWORD *)((((unsigned int)CacheBuffer >> 10) & 0x3FFFFC) - 0x40000000), 8u);
    v16 = WriteLength;
    for ( WriteBytesRemaining = WriteLength; ; v16 = WriteBytesRemaining )
    {
      WriteLengtha = 0x8000;
      if ( v16 < 0x8000 )
        WriteLengtha = v16;
      IoEvent.Header.SignalState = 0;
      IoEvent.Header.WaitListHead.Blink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.WaitListHead.Flink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.Type = 0;
      IoEvent.Header.Size = 4;
      if ( !FscSignalIoEventCompletion )
        RtlAssert(
          v15,
          v16,
          (int *)FscSignalIoEventCompletion,
          (int)Irp,
          "(1) | (1) | (1) ? (FscSignalIoEventCompletion) != NULL : TRUE",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x621u,
          (char *)FscSignalIoEventCompletion);
      v17 = Irp->Tail.Overlay.CurrentStackLocation;
      v17[-1].CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FscSignalIoEventCompletion;
      v17[-1].Control = -32;
      v17[-1].Context = &IoEvent;
      v18 = Irp->Tail.Overlay.PacketType - 36;
      *(_QWORD *)(v18 + 12) = ByteOffset;
      *(_DWORD *)(v18 + 4) = WriteLengtha;
      *(_BYTE *)v18 = 3;
      *(_BYTE *)(v18 + 2) = -128;
      *(_DWORD *)(v18 + 8) = (_DWORD)FscWriteFFsPtes << 10;
      v12 = (int *)IofCallDriver(CacheExtension->TargetDeviceObject, Irp);
      if ( v12 == (int *)259 )
      {
        KeWaitForSingleObject(v19, v15, &IoEvent, Spare3, 0, 0, 0);
        v12 = (int *)Irp->IoStatus.Status;
      }
      if ( (signed int)v12 < 0 )
        break;
      ByteOffset += WriteLengtha;
      WriteBytesRemaining -= WriteLengtha;
      if ( !WriteBytesRemaining )
        break;
    }
    MiZeroAndFlushPtes(FscWriteFFsPtes, 8);
    MmLockUnlockBufferPages(v20, v21, v12, (int)Irp, CacheBuffer, 0x1000u, 1);
    if ( (signed int)v12 < 0 )
      FscDiscardBuffer(v12, (int)Irp, CacheBuffer);
    else
      FscUnmapBuffer(v12, (int)Irp, CacheBuffer);
  }
  RtlLeaveCriticalSection(v11, (_KEVENT *)&FscWriteFFsLock);
  return v12;
}