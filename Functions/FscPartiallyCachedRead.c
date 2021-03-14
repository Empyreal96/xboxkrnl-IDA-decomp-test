int __userpurge FscPartiallyCachedRead@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FSCACHE_EXTENSION *CacheExtension, _IRP *Irp, unsigned __int64 ByteOffset, unsigned int ReadLength, unsigned int BufferByteOffset, char NonCachedEndOfFileTransfer)
{
  unsigned int v9; // ebx
  unsigned int v10; // ebx
  _IRP *v11; // edi
  _IO_STACK_LOCATION *v12; // eax
  int v13; // esi
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // edx
  int v17; // ecx
  _FSCACHE_EXTENSION *v18; // esi
  _FSCACHE_EXTENSION *v19; // ST14_4
  char v20; // al
  char *v21; // edi
  unsigned int v22; // ecx
  char *v23; // edi
  _DEVICE_OBJECT **v24; // esi
  int v25; // ecx
  _KEVENT IoEvent; // [esp+Ch] [ebp-10h]

  if ( ByteOffset & 0xFFF )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      a3,
      "BYTE_OFFSET(ByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x709u,
      0);
  if ( NonCachedEndOfFileTransfer )
  {
    a2 = ReadLength;
    v9 = ~(CacheExtension->SectorSize - 1) & (CacheExtension->SectorSize + ReadLength - 1);
    ReadLength = ~(CacheExtension->SectorSize - 1) & (CacheExtension->SectorSize + ReadLength - 1);
  }
  else
  {
    v10 = ReadLength;
    if ( ReadLength < 0x1000 )
      RtlAssert(
        a1,
        a2,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        a3,
        "ReadLength >= PAGE_SIZE",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x715u,
        0);
    v9 = v10 & 0xFFFFF000;
  }
  IoEvent.Header.SignalState = 0;
  IoEvent.Header.WaitListHead.Blink = &IoEvent.Header.WaitListHead;
  IoEvent.Header.WaitListHead.Flink = &IoEvent.Header.WaitListHead;
  IoEvent.Header.Type = 0;
  IoEvent.Header.Size = 4;
  if ( !FscSignalIoEventCompletion )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)FscSignalIoEventCompletion,
      "(1) | (1) | (1) ? (FscSignalIoEventCompletion) != NULL : TRUE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x721u,
      (char *)FscSignalIoEventCompletion);
  v11 = Irp;
  v12 = Irp->Tail.Overlay.CurrentStackLocation;
  v12[-1].CompletionRoutine = (int (__stdcall *)(_DEVICE_OBJECT *, _IRP *, void *))FscSignalIoEventCompletion;
  v13 = HIDWORD(ByteOffset);
  v12[-1].Control = -32;
  v12[-1].Context = &IoEvent;
  v14 = v11->Tail.Overlay.PacketType - 36;
  *(_DWORD *)(v14 + 12) = ByteOffset;
  v15 = BufferByteOffset;
  *(_BYTE *)v14 = 2;
  *(_DWORD *)(v14 + 16) = v13;
  *(_DWORD *)(v14 + 4) = v9;
  *(_DWORD *)(v14 + 8) = v15;
  *(_DWORD *)&NonCachedEndOfFileTransfer = IofCallDriver(CacheExtension->TargetDeviceObject, v11);
  if ( NonCachedEndOfFileTransfer == 259 )
  {
    KeWaitForSingleObject(v17, v16, &IoEvent, Spare2, 0, 0, 0);
    *(_DWORD *)&NonCachedEndOfFileTransfer = v11->IoStatus.Status;
  }
  if ( NonCachedEndOfFileTransfer >= 0 )
  {
    ReadLength -= v9;
    if ( ReadLength )
    {
      *(_DWORD *)&NonCachedEndOfFileTransfer = FscMapBuffer(
                                                 v16,
                                                 (__PAIR__(v13, (unsigned int)ByteOffset) + (unsigned __int64)v9) >> 32,
                                                 (int *)&v11->Type,
                                                 v13,
                                                 CacheExtension,
                                                 v11,
                                                 __PAIR__(v13, (unsigned int)ByteOffset) + v9,
                                                 0,
                                                 (void **)&CacheExtension);
      if ( NonCachedEndOfFileTransfer >= 0 )
      {
        v18 = CacheExtension;
        v19 = CacheExtension;
        v20 = ReadLength;
        v21 = (char *)v11->UserBuffer + v9 + BufferByteOffset;
        v22 = ReadLength >> 2;
        qmemcpy(v21, CacheExtension, 4 * (ReadLength >> 2));
        v24 = &v18->TargetDeviceObject + v22;
        v23 = &v21[4 * v22];
        v25 = v20 & 3;
        qmemcpy(v23, v24, v25);
        FscUnmapBuffer((int *)&v23[v25], (int)v24 + v25, v19);
      }
    }
  }
  return NonCachedEndOfFileTransfer;
}