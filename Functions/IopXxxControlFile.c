int __userpurge IopXxxControlFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, void *Event, void (__stdcall *ApcRoutine)(void *, _IO_STATUS_BLOCK *, unsigned int), void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, unsigned int IoControlCode, void *InputBuffer, unsigned int InputBufferLength, void *OutputBuffer, unsigned int OutputBufferLength, char DeviceIoControl)
{
  int v15; // edx
  int v16; // ST18_4
  int result; // eax
  int v18; // edx
  _FILE_OBJECT *v19; // ecx
  signed int v20; // esi
  int v21; // eax
  _DEVICE_OBJECT *v22; // edi
  _IRP *v23; // eax
  int v24; // edx
  int v25; // esi
  int v26; // eax
  int v27; // ecx
  _KEVENT *eventObject; // [esp+4h] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+8h] [ebp-4h]
  char synchronousIo; // [esp+18h] [ebp+Ch]

  eventObject = 0;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v15, v16, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x5A4u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, a3, a4, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result >= 0 )
  {
    v19 = fileObject;
    if ( fileObject->CompletionContext && ApcRoutine )
    {
      v20 = -1073741811;
LABEL_10:
      ObfDereferenceObject(v19, v18);
      return v20;
    }
    if ( Event )
    {
      v21 = ObReferenceObjectByHandle(v18, (int)fileObject, a3, a4, Event, &ExEventObjectType, (void **)&eventObject);
      if ( v21 < 0 )
      {
        v19 = fileObject;
        v20 = v21;
        goto LABEL_10;
      }
      eventObject->Header.SignalState = 0;
      v19 = fileObject;
    }
    if ( v19->Flags & 1 )
    {
      IopAcquireFileObjectLock((int)v19, v18);
      v19 = fileObject;
      synchronousIo = 1;
    }
    else
    {
      synchronousIo = 0;
    }
    v22 = v19->DeviceObject;
    v19->Event.Header.SignalState = 0;
    v23 = IoAllocateIrp((int)v19, v18, v22->StackSize);
    v25 = (int)v23;
    if ( v23 )
    {
      v23->Tail.Overlay.OriginalFileObject = fileObject;
      v23->Tail.Overlay.Thread = (_ETHREAD *)thread;
      v23->UserBuffer = OutputBuffer;
      v23->UserEvent = eventObject;
      v23->UserIosb = IoStatusBlock;
      v23->Overlay.AllocationSize.LowPart = (unsigned int)ApcRoutine;
      v23->Overlay.AllocationSize.HighPart = (int)ApcContext;
      v26 = v23->Tail.Overlay.PacketType - 36;
      *(_BYTE *)v26 = (DeviceIoControl != 0) + 9;
      *(_DWORD *)(v26 + 24) = fileObject;
      *(_DWORD *)(v26 + 12) = InputBufferLength;
      *(_DWORD *)(v26 + 4) = OutputBufferLength;
      *(_DWORD *)(v26 + 16) = IoControlCode;
      *(_DWORD *)(v26 + 8) = InputBuffer;
      if ( OutputBufferLength )
      {
        v27 = IoControlCode & 3;
        if ( v27 == 1 || v27 == 2 )
          IoLockUserBuffer(OutputBufferLength, v27, v25, (_IRP *)v25, OutputBufferLength);
      }
      if ( !DeviceIoControl )
        *(_BYTE *)(v25 + 4) |= 0x80u;
      LOBYTE(v26) = DeviceIoControl == 0;
      result = IopSynchronousServiceTail((int *)&v22->Type, v25, v22, (_IRP *)v25, fileObject, v26, synchronousIo);
    }
    else
    {
      result = IopAllocateIrpCleanup(v24, (int *)&v22->Type, 0, fileObject, eventObject);
    }
  }
  return result;
}