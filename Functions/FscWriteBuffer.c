int __userpurge FscWriteBuffer@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FSCACHE_EXTENSION *CacheExtension, _IRP *Irp, unsigned __int64 ByteOffset, unsigned int WriteLength, void *CacheBuffer)
{
  _IRP *v8; // ecx
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int *v15; // edi
  int v16; // edx
  int v17; // ecx
  _IO_STACK_LOCATION *v18; // eax
  unsigned int v19; // eax
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  _KEVENT IoEvent; // [esp+Ch] [ebp-18h]
  unsigned __int64 EndingByteOffset; // [esp+1Ch] [ebp-8h]
  void *CacheBuffera; // [esp+40h] [ebp+1Ch]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      a3,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4CCu,
      0);
  v8 = Irp;
  LOBYTE(v8) = Irp->CurrentLocation;
  if ( (char)v8 <= CacheExtension->TargetDeviceObject->StackSize )
    RtlAssert(
      a1,
      (int)v8,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "Irp->CurrentLocation > CacheExtension->TargetDeviceObject->StackSize",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4CDu,
      0);
  if ( ByteOffset >= CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      (int)v8,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "ByteOffset < (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4CEu,
      0);
  v9 = ByteOffset + WriteLength;
  if ( ByteOffset + WriteLength > CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      v9,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "(ByteOffset + WriteLength) <= (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4CFu,
      0);
  if ( WriteLength + (ByteOffset & 0xFFF) > 0x1000 )
    RtlAssert(
      a1,
      v9,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "(BYTE_OFFSET(ByteOffset) + WriteLength) <= PAGE_SIZE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4D0u,
      0);
  if ( !(*(_BYTE *)((((unsigned int)CacheBuffer >> 10) & 0x3FFFFC) - 0x40000000) & 2) )
    RtlAssert(
      a1,
      v9,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)CacheExtension,
      "MiGetPteAddress(CacheBuffer)->Hard.Write != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4D1u,
      0);
  v10 = CacheExtension->SectorSize - 1;
  v12 = (ByteOffset + WriteLength + (unsigned __int64)v10) >> 32;
  v11 = ByteOffset + WriteLength + v10;
  v13 = ~v10;
  LODWORD(ByteOffset) = v13 & ByteOffset;
  v14 = v13 & v11;
  v15 = (int *)(v14 - ByteOffset);
  LODWORD(EndingByteOffset) = v14;
  CacheBuffera = (void *)(((unsigned int)CacheBuffer ^ ByteOffset) & 0xFFF ^ (unsigned int)CacheBuffer);
  if ( __PAIR__((unsigned int)v12, v14) > CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      v13,
      v12,
      v15,
      (int)CacheExtension,
      "EndingByteOffset <= (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4DDu,
      0);
  if ( (unsigned int)((unsigned int)v15 + (ByteOffset & 0xFFF)) > 0x1000 )
    RtlAssert(
      v13,
      v12,
      v15,
      (int)CacheExtension,
      "(BYTE_OFFSET(ByteOffset) + WriteLength) <= PAGE_SIZE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4DEu,
      0);
  MmLockUnlockBufferPages(v13, v12, v15, (int)CacheExtension, CacheBuffera, (unsigned int)v15, 0);
  IoEvent.Header.WaitListHead.Blink = &IoEvent.Header.WaitListHead;
  IoEvent.Header.WaitListHead.Flink = &IoEvent.Header.WaitListHead;
  IoEvent.Header.Type = 0;
  IoEvent.Header.Size = 4;
  IoEvent.Header.SignalState = 0;
  if ( !FscSignalIoEventCompletion )
    RtlAssert(
      v16,
      v17,
      v15,
      (int)CacheExtension,
      "(1) | (1) | (1) ? (FscSignalIoEventCompletion) != NULL : TRUE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x4EEu,
      0);
  v18 = Irp->Tail.Overlay.CurrentStackLocation;
  v18[-1].CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FscSignalIoEventCompletion;
  v18[-1].Control = -32;
  v18[-1].Context = &IoEvent;
  v19 = Irp->Tail.Overlay.PacketType - 36;
  *(_QWORD *)(v19 + 12) = ByteOffset;
  *(_BYTE *)v19 = 3;
  *(_BYTE *)(v19 + 2) = -128;
  *(_DWORD *)(v19 + 4) = v15;
  *(_DWORD *)(v19 + 8) = CacheBuffera;
  v22 = IofCallDriver(CacheExtension->TargetDeviceObject, Irp);
  if ( v22 == 259 )
  {
    KeWaitForSingleObject(v21, v20, &IoEvent, Spare3, 0, 0, 0);
    v22 = Irp->IoStatus.Status;
  }
  MmLockUnlockBufferPages(v20, v21, v15, v22, CacheBuffera, (unsigned int)v15, 1);
  if ( v22 < 0 )
    FscDiscardBuffer(v15, v22, CacheBuffera);
  else
    FscUnmapBuffer(v15, v22, CacheBuffera);
  return v22;
}