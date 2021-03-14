int __userpurge NtWriteFileGather@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *FileHandle, void *Event, void (__stdcall *ApcRoutine)(void *, _IO_STATUS_BLOCK *, unsigned int), void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, _FILE_SEGMENT_ELEMENT *SegmentArray, unsigned int Length, _LARGE_INTEGER *ByteOffset)
{
  int v11; // edx
  int v12; // ST18_4
  int result; // eax
  int v14; // edx
  _FILE_OBJECT *v15; // ecx
  signed int v16; // esi
  _DEVICE_OBJECT *v17; // ebx
  char v18; // al
  int v19; // eax
  _IRP *v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // esi
  _IO_STACK_LOCATION *v24; // edi
  _KEVENT *v25; // eax
  int *v26; // edi
  int v27; // edx
  int v28; // ecx
  _LARGE_INTEGER fileOffset; // [esp+4h] [ebp-10h]
  _KEVENT *eventObject; // [esp+Ch] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+10h] [ebp-4h]
  _DEVICE_OBJECT *deviceObject; // [esp+1Ch] [ebp+8h]
  char synchronousIo; // [esp+20h] [ebp+Ch]
  int status; // [esp+24h] [ebp+10h]

  eventObject = 0;
  fileOffset.QuadPart = 0i64;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(0, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v11, v12, 0, a3, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\write.c", 0x174u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, 0, a3, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result < 0 )
    return result;
  v15 = fileObject;
  if ( !(*((_BYTE *)fileObject + 2) & 4) )
  {
    v16 = -1073741790;
LABEL_26:
    ObfDereferenceObject(v15, v14);
    return v16;
  }
  v17 = fileObject->DeviceObject;
  deviceObject = fileObject->DeviceObject;
  if ( !(fileObject->Flags & 4) )
    goto LABEL_35;
  v18 = v17->DeviceType;
  if ( v18 != 8 && v18 != 3 )
    goto LABEL_35;
  if ( fileObject->CompletionContext && ApcRoutine )
  {
LABEL_25:
    v16 = -1073741811;
    goto LABEL_26;
  }
  if ( ByteOffset )
    fileOffset = *ByteOffset;
  if ( Event )
  {
    v19 = ObReferenceObjectByHandle(
            v14,
            (int)fileObject,
            0,
            (int)ByteOffset,
            Event,
            &ExEventObjectType,
            (void **)&eventObject);
    if ( v19 < 0 )
    {
      v15 = fileObject;
      v16 = v19;
      goto LABEL_26;
    }
    eventObject->Header.SignalState = 0;
    v15 = fileObject;
  }
  if ( v15->Flags & 1 )
  {
    IopAcquireFileObjectLock((int)v15, v14);
    synchronousIo = 1;
    if ( (ByteOffset || fileOffset.LowPart) && fileOffset.QuadPart != -2 )
    {
      v15 = fileObject;
    }
    else
    {
      v15 = fileObject;
      fileOffset = fileObject->CurrentByteOffset;
    }
    goto LABEL_29;
  }
  if ( !ByteOffset )
  {
    if ( eventObject )
    {
      ObfDereferenceObject(eventObject, v14);
      v15 = fileObject;
    }
    goto LABEL_25;
  }
  synchronousIo = 0;
LABEL_29:
  if ( fileOffset.HighPart < 0 && fileOffset.QuadPart != -1 )
  {
    if ( eventObject )
    {
      ObfDereferenceObject(eventObject, v14);
      v15 = fileObject;
    }
    if ( synchronousIo )
    {
      IopReleaseFileObjectLock((int)v15, v14);
      v15 = fileObject;
    }
LABEL_35:
    ObfDereferenceObject(v15, v14);
    return -1073741811;
  }
  v15->Event.Header.SignalState = 0;
  v20 = IoAllocateIrp((int)v15, v14, v17->StackSize);
  v23 = (int)v20;
  if ( !v20 )
    return IopAllocateIrpCleanup(v21, 0, 0, fileObject, eventObject);
  v24 = v20->Tail.Overlay.CurrentStackLocation;
  v20->Tail.Overlay.OriginalFileObject = fileObject;
  v20->Tail.Overlay.Thread = (_ETHREAD *)thread;
  v25 = eventObject;
  *(_WORD *)(v23 + 4) |= 0x4A1u;
  *(_DWORD *)(v23 + 32) = v25;
  *(_DWORD *)(v23 + 28) = IoStatusBlock;
  *(_DWORD *)(v23 + 40) = ApcRoutine;
  v26 = (int *)&v24[-1].MajorFunction;
  *(_DWORD *)(v23 + 44) = ApcContext;
  *(_BYTE *)v26 = 3;
  v26[6] = (int)fileObject;
  if ( Length
    && (status = MmLockSelectedIoPages(
                   v21,
                   v22,
                   v26,
                   v23,
                   SegmentArray,
                   Length,
                   (_IRP *)v23,
                   ~(unsigned __int8)(deviceObject->Flags >> 6) & 1),
        status < 0) )
  {
    IopExceptionCleanup(v27, v28, v26, v23, fileObject, (_IRP *)v23, eventObject);
    result = status;
  }
  else
  {
    v26[2] = 0;
    v26[3] = fileOffset.LowPart;
    v26[1] = Length;
    v26[4] = fileOffset.HighPart;
    result = IopSynchronousServiceTail(v26, v23, deviceObject, (_IRP *)v23, fileObject, 1, synchronousIo);
  }
  return result;
}