int __userpurge NtWriteFile@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *FileHandle, void *Event, void (__stdcall *ApcRoutine)(void *, _IO_STATUS_BLOCK *, unsigned int), void *ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, unsigned int Length, _LARGE_INTEGER *ByteOffset)
{
  int v11; // edx
  int v12; // ST18_4
  int result; // eax
  int v14; // edx
  _FILE_OBJECT *v15; // ecx
  signed int v16; // esi
  _DEVICE_OBJECT *v17; // ebx
  int v18; // eax
  _IRP *v19; // eax
  int v20; // edx
  int v21; // ecx
  _IRP *v22; // edi
  _IO_STACK_LOCATION *v23; // esi
  int v24; // esi
  _LARGE_INTEGER fileOffset; // [esp+4h] [ebp-10h]
  _KEVENT *eventObject; // [esp+Ch] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+10h] [ebp-4h]
  _DEVICE_OBJECT *deviceObject; // [esp+1Ch] [ebp+8h]
  char synchronousIo; // [esp+20h] [ebp+Ch]

  eventObject = 0;
  fileOffset.QuadPart = 0i64;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(0, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v11, v12, 0, a3, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\write.c", 0x56u, 0);
  }
  result = ObReferenceObjectByHandle(a1, a2, 0, a3, FileHandle, &IoFileObjectType, (void **)&fileObject);
  if ( result >= 0 )
  {
    v15 = fileObject;
    if ( !(*((_BYTE *)fileObject + 2) & 4) )
    {
      v16 = -1073741790;
LABEL_23:
      ObfDereferenceObject(v15, v14);
      return v16;
    }
    v17 = fileObject->DeviceObject;
    deviceObject = fileObject->DeviceObject;
    if ( !fileObject->CompletionContext || !ApcRoutine )
    {
      if ( ByteOffset )
        fileOffset = *ByteOffset;
      if ( Event )
      {
        v18 = ObReferenceObjectByHandle(
                v14,
                (int)fileObject,
                0,
                (int)ByteOffset,
                Event,
                &ExEventObjectType,
                (void **)&eventObject);
        if ( v18 < 0 )
        {
          v15 = fileObject;
          v16 = v18;
          goto LABEL_23;
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
LABEL_26:
        if ( fileOffset.HighPart >= 0 || fileOffset.QuadPart == -1 )
        {
          v15->Event.Header.SignalState = 0;
          v19 = IoAllocateIrp((int)v15, v14, v17->StackSize);
          v22 = v19;
          if ( v19 )
          {
            v23 = v19->Tail.Overlay.CurrentStackLocation;
            v19->Tail.Overlay.OriginalFileObject = fileObject;
            v19->Tail.Overlay.Thread = (_ETHREAD *)thread;
            v19->UserBuffer = Buffer;
            v19->UserEvent = eventObject;
            v19->UserIosb = IoStatusBlock;
            v19->Overlay.AllocationSize.LowPart = (unsigned int)ApcRoutine;
            v19->Overlay.AllocationSize.HighPart = (int)ApcContext;
            v24 = (int)&v23[-1];
            *(_BYTE *)v24 = 3;
            *(_DWORD *)(v24 + 24) = fileObject;
            if ( v17->Flags & 4 && Length )
              IoLockUserBuffer(v20, v21, v24, v19, Length);
            if ( fileObject->Flags & 4 )
              LOBYTE(v22->Flags) |= 0xA1u;
            else
              LOBYTE(v22->Flags) |= 0xA0u;
            *(_DWORD *)(v24 + 8) = 0;
            *(_DWORD *)(v24 + 12) = fileOffset.LowPart;
            *(_DWORD *)(v24 + 4) = Length;
            *(_DWORD *)(v24 + 16) = fileOffset.HighPart;
            result = IopSynchronousServiceTail((int *)&v22->Type, v24, deviceObject, v22, fileObject, 1, synchronousIo);
          }
          else
          {
            result = IopAllocateIrpCleanup(v20, 0, (int)ByteOffset, fileObject, eventObject);
          }
        }
        else
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
          ObfDereferenceObject(v15, v14);
          result = -1073741811;
        }
        return result;
      }
      if ( ByteOffset )
      {
        synchronousIo = 0;
        goto LABEL_26;
      }
      if ( eventObject )
      {
        ObfDereferenceObject(eventObject, v14);
        v15 = fileObject;
      }
    }
    v16 = -1073741811;
    goto LABEL_23;
  }
  return result;
}