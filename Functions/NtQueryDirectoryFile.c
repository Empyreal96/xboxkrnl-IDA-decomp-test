int __userpurge NtQueryDirectoryFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, void *Event, void (__stdcall *ApcRoutine)(void *, _IO_STATUS_BLOCK *, unsigned int), void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, unsigned int Length, _FILE_INFORMATION_CLASS FileInformationClass, _STRING *FileName, char RestartScan)
{
  int v14; // edx
  int v15; // ST18_4
  int result; // eax
  int v17; // edx
  int v18; // ecx
  signed int v19; // esi
  int v20; // eax
  _FILE_OBJECT *v21; // ecx
  _DEVICE_OBJECT *v22; // esi
  _IRP *v23; // eax
  int v24; // edx
  _KEVENT *v25; // ecx
  int v26; // ecx
  _KEVENT *eventObject; // [esp+4h] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+8h] [ebp-4h]
  char synchronousIo; // [esp+18h] [ebp+Ch]

  eventObject = 0;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v14, v15, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\dir.c", 0x75u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result >= 0 )
  {
    if ( fileObject->CompletionContext && ApcRoutine )
    {
      v19 = -1073741811;
LABEL_10:
      ObfDereferenceObject(fileObject, v17);
      return v19;
    }
    if ( Event )
    {
      v20 = ObReferenceObjectByHandle(v17, v18, (int *)ApcRoutine, a4, Event, &ExEventObjectType, (void **)&eventObject);
      if ( v20 < 0 )
      {
        v19 = v20;
        goto LABEL_10;
      }
      eventObject->Header.SignalState = 0;
    }
    v21 = fileObject;
    if ( fileObject->Flags & 1 )
    {
      IopAcquireFileObjectLock((int)fileObject, v17);
      synchronousIo = 1;
    }
    else
    {
      synchronousIo = 0;
    }
    fileObject->Event.Header.SignalState = 0;
    v22 = fileObject->DeviceObject;
    v23 = IoAllocateIrp((int)v21, v17, v22->StackSize);
    if ( v23 )
    {
      v23->Tail.Overlay.OriginalFileObject = fileObject;
      v23->Tail.Overlay.Thread = (_ETHREAD *)thread;
      v25 = eventObject;
      LOBYTE(v23->Flags) |= 0x80u;
      v23->UserEvent = v25;
      v23->UserIosb = IoStatusBlock;
      v23->Overlay.AllocationSize.HighPart = (int)ApcContext;
      v26 = v23->Tail.Overlay.PacketType - 36;
      v23->Overlay.AllocationSize.LowPart = (unsigned int)ApcRoutine;
      *(_BYTE *)v26 = 8;
      *(_DWORD *)(v26 + 24) = fileObject;
      v23->UserBuffer = FileInformation;
      *(_DWORD *)(v26 + 4) = Length;
      *(_DWORD *)(v26 + 12) = FileInformationClass;
      *(_DWORD *)(v26 + 8) = FileName;
      if ( RestartScan )
        *(_BYTE *)(v26 + 2) = 1;
      result = IopSynchronousServiceTail((int *)ApcRoutine, (int)v22, v22, v23, fileObject, 1, synchronousIo);
    }
    else
    {
      result = IopAllocateIrpCleanup(v24, (int *)ApcRoutine, (int)v22, fileObject, eventObject);
    }
  }
  return result;
}