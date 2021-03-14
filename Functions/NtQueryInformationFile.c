int *__userpurge NtQueryInformationFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *FileHandle, _IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, unsigned int Length, _FILE_INFORMATION_CLASS FileInformationClass)
{
  int v9; // edx
  int v10; // ST1C_4
  _FILE_INFORMATION_CLASS v11; // ebx
  unsigned __int8 v12; // al
  int v14; // edx
  int *v15; // edi
  _FILE_OBJECT *v16; // ecx
  signed int v17; // esi
  _DEVICE_OBJECT *v18; // esi
  _DWORD *v19; // eax
  int v20; // edx
  _IO_STATUS_BLOCK *v21; // eax
  _IRP *v22; // eax
  int v23; // edx
  _IRP *v24; // esi
  bool v25; // zf
  _IO_STATUS_BLOCK *v26; // eax
  int v27; // eax
  KIRQL v28; // al
  _LIST_ENTRY *v29; // edx
  KIRQL v30; // cl
  _LIST_ENTRY *v31; // eax
  unsigned int v32; // eax
  KIRQL v33; // bl
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  _FILE_OBJECT *v37; // ecx
  int v38; // edx
  int v39; // ecx
  _KEVENT localEvent; // [esp+0h] [ebp-1Ch]
  _IO_STATUS_BLOCK localIoStatus; // [esp+10h] [ebp-Ch]
  _FILE_OBJECT *fileObject; // [esp+18h] [ebp-4h]
  _DEVICE_OBJECT *deviceObject; // [esp+24h] [ebp+8h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\qsinfo.c", 0x74u, 0);
  }
  v11 = FileInformationClass;
  if ( (unsigned int)FileInformationClass < 0x25 )
  {
    v12 = IopQueryOperationLength[FileInformationClass];
    if ( v12 )
    {
      if ( Length < v12 )
        return (int *)-1073741820;
      v15 = (int *)ObReferenceObjectByHandle(a1, a2, a3, a4, FileHandle, &IoFileObjectType, (void **)&fileObject);
      if ( (signed int)v15 < 0 )
        return v15;
      v16 = fileObject;
      if ( *(_BYTE *)(4 * v11 - 2147412184) & 1 && !(*((_BYTE *)fileObject + 2) & 2) )
      {
        v17 = -1073741790;
LABEL_14:
        ObfDereferenceObject(v16, v14);
        return (int *)v17;
      }
      v18 = fileObject->DeviceObject;
      deviceObject = fileObject->DeviceObject;
      if ( fileObject->Flags & 1 )
      {
        IopAcquireFileObjectLock((int)fileObject, v14);
        v16 = fileObject;
        if ( v11 == 14 )
        {
          v19 = FileInformation;
          *(_DWORD *)FileInformation = fileObject->CurrentByteOffset.LowPart;
          v20 = v16->CurrentByteOffset.HighPart;
          v19[1] = v20;
          v21 = IoStatusBlock;
          IoStatusBlock->Status = 0;
          v21->Information = 8;
          IopReleaseFileObjectLock((int)v16, v20);
          v16 = fileObject;
          v17 = (signed int)v15;
          goto LABEL_14;
        }
        HIBYTE(FileInformationClass) = 1;
      }
      else
      {
        localEvent.Header.SignalState = 0;
        localEvent.Header.Type = 1;
        localEvent.Header.Size = 4;
        localEvent.Header.WaitListHead.Blink = &localEvent.Header.WaitListHead;
        localEvent.Header.WaitListHead.Flink = &localEvent.Header.WaitListHead;
        HIBYTE(FileInformationClass) = 0;
      }
      v16->Event.Header.SignalState = 0;
      v22 = IoAllocateIrp((int)v16, v14, v18->StackSize);
      v24 = v22;
      if ( !v22 )
        return (int *)IopAllocateIrpCleanup(v23, v15, 0, fileObject, 0);
      v25 = HIBYTE(FileInformationClass) == 0;
      v22->Tail.Overlay.OriginalFileObject = fileObject;
      v22->Tail.Overlay.Thread = (_ETHREAD *)thread;
      v22->UserBuffer = FileInformation;
      if ( v25 )
      {
        v22->UserEvent = &localEvent;
        v26 = &localIoStatus;
        v24->Flags = 4;
      }
      else
      {
        v26 = IoStatusBlock;
      }
      LOBYTE(v24->Flags) |= 0x80u;
      v24->UserIosb = v26;
      v27 = v24->Tail.Overlay.PacketType - 36;
      *(_BYTE *)v27 = 4;
      *(_DWORD *)(v27 + 24) = fileObject;
      *(_DWORD *)(v27 + 4) = Length;
      *(_DWORD *)(v27 + 8) = v11;
      v28 = KfRaiseIrql(1);
      v29 = &v24->Tail.Overlay.Thread->IrpList;
      v30 = v28;
      v31 = v29->Flink;
      v24->ThreadListEntry.Flink = v29->Flink;
      v24->ThreadListEntry.Blink = v29;
      v31->Blink = &v24->ThreadListEntry;
      v29->Flink = &v24->ThreadListEntry;
      KfLowerIrql(v30);
      if ( v11 == 16 )
      {
        v32 = IopGetModeInformation(fileObject);
      }
      else
      {
        if ( v11 != 17 )
        {
          v15 = (int *)IofCallDriver(deviceObject, v24);
          if ( v15 == (int *)259 )
          {
            if ( !HIBYTE(FileInformationClass) )
            {
              KeWaitForSingleObject(v39, v38, &localEvent, 0, 0, 0, 0);
              v15 = (int *)localIoStatus.Status;
              *IoStatusBlock = localIoStatus;
              return v15;
            }
            KeWaitForSingleObject(v39, v38, &fileObject->Event, 0, 0, 0, 0);
            v37 = fileObject;
            v15 = (int *)fileObject->FinalStatus;
LABEL_31:
            IopReleaseFileObjectLock((int)v37, v36);
            return v15;
          }
LABEL_27:
          if ( !HIBYTE(FileInformationClass) )
            v24->UserEvent = 0;
          v24->UserIosb = IoStatusBlock;
          v33 = KfRaiseIrql(1);
          IopCompleteRequest(
            v35,
            v34,
            (_KAPC *)&v24->Tail,
            (void (__stdcall **)(void *, void *, void *))&IoStatusBlock,
            &FileInformation,
            (void **)&fileObject,
            &FileInformation);
          KfLowerIrql(v33);
          if ( !HIBYTE(FileInformationClass) )
            return v15;
          v37 = fileObject;
          goto LABEL_31;
        }
        v32 = deviceObject->AlignmentRequirement;
      }
      *(_DWORD *)FileInformation = v32;
      v15 = 0;
      v24->IoStatus.Information = 4;
      v24->IoStatus.Status = 0;
      goto LABEL_27;
    }
  }
  return (int *)-1073741821;
}