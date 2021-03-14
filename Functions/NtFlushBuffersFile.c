int __userpurge NtFlushBuffersFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, _IO_STATUS_BLOCK *IoStatusBlock)
{
  int v6; // edx
  int v7; // ST18_4
  int result; // eax
  int v9; // edx
  _FILE_OBJECT *v10; // ecx
  _DEVICE_OBJECT *v11; // edi
  _IRP *v12; // eax
  int v13; // edx
  _IRP *v14; // esi
  _IO_STATUS_BLOCK *v15; // eax
  int v16; // eax
  int v17; // edx
  _KEVENT localEvent; // [esp+4h] [ebp-1Ch]
  _IO_STATUS_BLOCK localIoStatus; // [esp+14h] [ebp-Ch]
  _FILE_OBJECT *fileObject; // [esp+1Ch] [ebp-4h]
  char synchronousIo; // [esp+28h] [ebp+8h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\misc.c", 0x92u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result >= 0 )
  {
    v10 = fileObject;
    if ( fileObject->Flags & 1 )
    {
      IopAcquireFileObjectLock((int)fileObject, v9);
      v10 = fileObject;
      synchronousIo = 1;
    }
    else
    {
      localEvent.Header.Type = 1;
      localEvent.Header.Size = 4;
      localEvent.Header.SignalState = 0;
      localEvent.Header.WaitListHead.Blink = &localEvent.Header.WaitListHead;
      localEvent.Header.WaitListHead.Flink = &localEvent.Header.WaitListHead;
      synchronousIo = 0;
    }
    v10->Event.Header.SignalState = 0;
    v11 = fileObject->DeviceObject;
    v12 = IoAllocateIrp((int)v10, v9, v11->StackSize);
    v14 = v12;
    if ( v12 )
    {
      v12->Tail.Overlay.OriginalFileObject = fileObject;
      v12->Tail.Overlay.Thread = (_ETHREAD *)thread;
      if ( synchronousIo )
      {
        v15 = IoStatusBlock;
      }
      else
      {
        v12->UserEvent = &localEvent;
        v15 = &localIoStatus;
        v14->Flags = 4;
      }
      v14->UserIosb = v15;
      v16 = v14->Tail.Overlay.PacketType - 36;
      *(_BYTE *)v16 = 6;
      *(_DWORD *)(v16 + 24) = fileObject;
      result = IopSynchronousServiceTail((int *)&v11->Type, (int)v14, v11, v14, fileObject, 0, synchronousIo);
      if ( !synchronousIo )
        result = IopSynchronousApiServiceTail(
                   v17,
                   (int)&localEvent,
                   (int)v14,
                   result,
                   &localEvent,
                   v14,
                   &localIoStatus,
                   IoStatusBlock);
    }
    else
    {
      result = IopAllocateIrpCleanup(v13, (int *)&v11->Type, 0, fileObject, 0);
    }
  }
  return result;
}