int __userpurge NtQueryVolumeInformationFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, _IO_STATUS_BLOCK *IoStatusBlock, void *FsInformation, unsigned int Length, _FSINFOCLASS FsInformationClass)
{
  int v9; // edx
  int v10; // ST1C_4
  _FSINFOCLASS v11; // ebx
  unsigned __int8 v12; // al
  int result; // eax
  int v14; // edx
  _FILE_OBJECT *v15; // ecx
  _DEVICE_OBJECT *v16; // edi
  _IRP *v17; // eax
  int v18; // edx
  _IRP *v19; // esi
  _IO_STATUS_BLOCK *v20; // eax
  int v21; // eax
  int v22; // edx
  _KEVENT localEvent; // [esp+0h] [ebp-1Ch]
  _IO_STATUS_BLOCK localIoStatus; // [esp+10h] [ebp-Ch]
  _FILE_OBJECT *fileObject; // [esp+18h] [ebp-4h]
  char synchronousIo; // [esp+34h] [ebp+18h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\qsfs.c", 0x4Bu, 0);
  }
  v11 = FsInformationClass;
  if ( (unsigned int)FsInformationClass >= 9 )
    return -1073741821;
  v12 = IopQueryFsOperationLength[FsInformationClass];
  if ( !v12 )
    return -1073741821;
  if ( Length < v12 )
    return -1073741820;
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result >= 0 )
  {
    v15 = fileObject;
    if ( !(*(_BYTE *)(4 * FsInformationClass - 2147411868) & 1) || *((_BYTE *)fileObject + 2) & 2 )
    {
      if ( fileObject->Flags & 1 )
      {
        IopAcquireFileObjectLock((int)fileObject, v14);
        v15 = fileObject;
        synchronousIo = 1;
      }
      else
      {
        synchronousIo = 0;
      }
      v15->Event.Header.SignalState = 0;
      v16 = fileObject->DeviceObject;
      if ( !(fileObject->Flags & 1) )
      {
        localEvent.Header.SignalState = 0;
        localEvent.Header.Type = 1;
        localEvent.Header.Size = 4;
        localEvent.Header.WaitListHead.Blink = &localEvent.Header.WaitListHead;
        localEvent.Header.WaitListHead.Flink = &localEvent.Header.WaitListHead;
      }
      v17 = IoAllocateIrp((int)v15, v14, v16->StackSize);
      v19 = v17;
      if ( v17 )
      {
        v17->Tail.Overlay.OriginalFileObject = fileObject;
        v17->Tail.Overlay.Thread = (_ETHREAD *)thread;
        v17->UserBuffer = FsInformation;
        if ( synchronousIo )
        {
          v20 = IoStatusBlock;
        }
        else
        {
          v17->UserEvent = &localEvent;
          v20 = &localIoStatus;
          v19->Flags = 4;
        }
        LOBYTE(v19->Flags) |= 0x80u;
        v19->UserIosb = v20;
        v21 = v19->Tail.Overlay.PacketType - 36;
        *(_BYTE *)v21 = 7;
        *(_DWORD *)(v21 + 24) = fileObject;
        *(_DWORD *)(v21 + 4) = Length;
        *(_DWORD *)(v21 + 8) = v11;
        result = IopSynchronousServiceTail((int *)&v16->Type, (int)v19, v16, v19, fileObject, 1, synchronousIo);
        if ( !synchronousIo )
          result = IopSynchronousApiServiceTail(
                     v22,
                     (int)&localEvent,
                     (int)v19,
                     result,
                     &localEvent,
                     v19,
                     &localIoStatus,
                     IoStatusBlock);
      }
      else
      {
        result = IopAllocateIrpCleanup(v18, (int *)&v16->Type, 0, fileObject, 0);
      }
    }
    else
    {
      ObfDereferenceObject(fileObject, v14);
      result = -1073741790;
    }
  }
  return result;
}