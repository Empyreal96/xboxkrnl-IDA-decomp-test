int *__userpurge NtSetInformationFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *FileHandle, _IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, unsigned int Length, _FILE_INFORMATION_CLASS FileInformationClass)
{
  int v8; // edx
  int v9; // ST10_4
  _FILE_INFORMATION_CLASS v10; // ebx
  unsigned __int8 v11; // al
  int *result; // eax
  int *v13; // edi
  int v14; // edx
  _FILE_OBJECT *v15; // ecx
  _FILE_INFORMATION_CLASS v16; // esi
  _DEVICE_OBJECT *v17; // esi
  _LARGE_INTEGER v18; // rax
  unsigned int v19; // edi
  _IO_STATUS_BLOCK *v20; // eax
  _IRP *v21; // eax
  int v22; // edx
  _IRP *v23; // esi
  bool v24; // zf
  _IO_STATUS_BLOCK *v25; // eax
  int v26; // eax
  KIRQL v27; // al
  _LIST_ENTRY *v28; // edx
  KIRQL v29; // cl
  _LIST_ENTRY *v30; // eax
  int *v31; // edi
  _BYTE *v34; // edi
  int *v35; // edi
  int v36; // edx
  _FILE_OBJECT *v37; // ecx
  _DWORD *v38; // ebx
  int *v39; // eax
  int v40; // edx
  _IO_STATUS_BLOCK *v41; // eax
  unsigned int v42; // ecx
  KIRQL v43; // bl
  int v44; // edx
  int v45; // ecx
  _KEVENT localEvent; // [esp+Ch] [ebp-20h]
  _IO_STATUS_BLOCK localIoStatus; // [esp+1Ch] [ebp-10h]
  void *targetHandle; // [esp+24h] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+28h] [ebp-4h]
  _DEVICE_OBJECT *deviceObject; // [esp+34h] [ebp+8h]

  targetHandle = 0;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, a3, 0, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\qsinfo.c", 0x1E3u, 0);
  }
  v10 = FileInformationClass;
  if ( (unsigned int)FileInformationClass >= 0x25 )
    return (int *)-1073741821;
  if ( FileInformationClass == 36 )
    return (int *)-1073741821;
  v11 = IopSetOperationLength[FileInformationClass];
  if ( !v11 )
    return (int *)-1073741821;
  if ( Length < v11 )
    return (int *)-1073741820;
  if ( FileInformationClass != 20 && FileInformationClass != 19 && FileInformationClass != 14 )
  {
    v13 = (int *)FileInformation;
  }
  else
  {
    v13 = (int *)FileInformation;
    if ( *((_DWORD *)FileInformation + 1) < 0 )
      return (int *)-1073741811;
  }
  result = (int *)ObReferenceObjectByHandle(a1, a2, v13, 0, FileHandle, &IoFileObjectType, (void **)&fileObject);
  FileInformationClass = (_FILE_INFORMATION_CLASS)result;
  if ( (signed int)result >= 0 )
  {
    v15 = fileObject;
    if ( *(_BYTE *)(4 * v10 - 2147412032) & 2 && !(*((_BYTE *)fileObject + 2) & 4) )
    {
      v16 = -1073741790;
LABEL_27:
      ObfDereferenceObject(v15, v14);
      return (int *)v16;
    }
    v17 = fileObject->DeviceObject;
    deviceObject = fileObject->DeviceObject;
    if ( fileObject->Flags & 1 )
    {
      IopAcquireFileObjectLock((int)fileObject, v14);
      v15 = fileObject;
      if ( v10 == 14 )
      {
        v18 = *(_LARGE_INTEGER *)v13;
        if ( fileObject->Flags & 4 && (v19 = v17->SectorSize) != 0 && (v19 - 1) & v18.LowPart || v18.HighPart < 0 )
        {
          FileInformationClass = -1073741811;
        }
        else
        {
          fileObject->CurrentByteOffset = v18;
          v20 = IoStatusBlock;
          IoStatusBlock->Status = 0;
          v20->Information = 0;
          v15 = fileObject;
        }
        IopReleaseFileObjectLock((int)v15, v18.HighPart);
        v16 = FileInformationClass;
        v15 = fileObject;
        goto LABEL_27;
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
    v15->Event.Header.SignalState = 0;
    v21 = IoAllocateIrp((int)v15, v14, v17->StackSize);
    v23 = v21;
    if ( !v21 )
      return (int *)IopAllocateIrpCleanup(v22, v13, 0, fileObject, 0);
    v24 = HIBYTE(FileInformationClass) == 0;
    v21->Tail.Overlay.OriginalFileObject = fileObject;
    v21->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v21->UserBuffer = v13;
    if ( v24 )
    {
      v21->UserEvent = &localEvent;
      v25 = &localIoStatus;
      v23->Flags = 4;
    }
    else
    {
      v25 = IoStatusBlock;
    }
    LOBYTE(v23->Flags) |= 0x80u;
    v23->UserIosb = v25;
    v26 = v23->Tail.Overlay.PacketType - 36;
    *(_BYTE *)v26 = 5;
    *(_DWORD *)(v26 + 24) = fileObject;
    *(_DWORD *)(v26 + 4) = Length;
    *(_DWORD *)(v26 + 8) = v10;
    v27 = KfRaiseIrql(1);
    v28 = &v23->Tail.Overlay.Thread->IrpList;
    v29 = v27;
    v30 = v28->Flink;
    v31 = (int *)&v23->ThreadListEntry;
    v23->ThreadListEntry.Flink = v28->Flink;
    v23->ThreadListEntry.Blink = v28;
    v30->Blink = &v23->ThreadListEntry;
    v28->Flink = &v23->ThreadListEntry;
    KfLowerIrql(v29);
    switch ( v10 )
    {
      case 16:
        v34 = FileInformation;
        _ECX = *(_DWORD *)FileInformation;
        if ( *(_DWORD *)FileInformation & 0xFFFFFFC9
          || (_EDX = *(_DWORD *)FileInformation & 0x30, _ECX & 0x30) && !(fileObject->Flags & 1)
          || !(_ECX & 0x30) && fileObject->Flags & 1
          || _ECX & 0x10 && _ECX & 0x20 )
        {
          v35 = (int *)-1073741811;
        }
        else
        {
          if ( _ECX & 4 )
            fileObject->Flags |= 8u;
          else
            fileObject->Flags &= 0xF7u;
          if ( fileObject->Flags & 1 )
          {
            if ( *v34 & 0x10 )
              fileObject->Flags |= 2u;
            else
              fileObject->Flags &= 0xFDu;
          }
          v35 = 0;
        }
        v23->IoStatus.Information = 0;
        v23->IoStatus.Status = (int)v35;
LABEL_59:
        if ( v35 == (int *)259 )
        {
          if ( !HIBYTE(FileInformationClass) )
          {
            KeWaitForSingleObject(_ECX, _EDX, &localEvent, 0, 0, 0, 0);
            v41 = IoStatusBlock;
            v35 = (int *)localIoStatus.Status;
            v42 = localIoStatus.Information;
            IoStatusBlock->Status = localIoStatus.Status;
            v41->Information = v42;
LABEL_78:
            if ( targetHandle )
              NtClose(v35, targetHandle);
            return v35;
          }
          KeWaitForSingleObject(_ECX, _EDX, &fileObject->Event, 0, 0, 0, 0);
          v37 = fileObject;
          v35 = (int *)fileObject->FinalStatus;
        }
        else
        {
          if ( !HIBYTE(FileInformationClass) )
            v23->UserEvent = 0;
          v23->UserIosb = IoStatusBlock;
          v43 = KfRaiseIrql(1);
          IopCompleteRequest(
            v45,
            v44,
            (_KAPC *)&v23->Tail,
            (void (__stdcall **)(void *, void *, void *))&IoStatusBlock,
            &FileInformation,
            (void **)&fileObject,
            &FileInformation);
          KfLowerIrql(v43);
          if ( !HIBYTE(FileInformationClass) )
            goto LABEL_78;
          v37 = fileObject;
        }
        IopReleaseFileObjectLock((int)v37, v36);
        goto LABEL_78;
      case 10:
        if ( (!*((_WORD *)FileInformation + 4) || **((_BYTE **)FileInformation + 3) != 92)
          && !*((_DWORD *)FileInformation + 1) )
        {
          goto LABEL_58;
        }
        v35 = IopOpenRenameTarget(
                v31,
                (int)v23,
                &targetHandle,
                v23,
                (_FILE_RENAME_INFORMATION *)FileInformation,
                fileObject);
        if ( (signed int)v35 >= 0 )
          goto LABEL_58;
        break;
      case 30:
        if ( fileObject->CompletionContext || fileObject->Flags & 1 )
        {
          v35 = (int *)-1073741811;
        }
        else
        {
          v38 = FileInformation;
          v35 = (int *)ObReferenceObjectByHandle(
                         _EDX,
                         _ECX,
                         v31,
                         (int)v23,
                         *(void **)FileInformation,
                         &IoCompletionObjectType,
                         &FileInformation);
          if ( (signed int)v35 >= 0 )
          {
            v39 = ExAllocatePoolWithTag(_EDX, _ECX, (int)v23, 8u, 0x63436F49u);
            Length = (unsigned int)v39;
            if ( v39 )
            {
              *v39 = (int)FileInformation;
              v39[1] = v38[1];
              _ECX = (int)&fileObject->CompletionContext;
              _EDX = Length;
              __asm { cmpxchg [ecx], edx }
              v35 = 0;
            }
            else
            {
              ObfDereferenceObject(FileInformation, v40);
              v35 = (int *)-1073741670;
            }
          }
        }
        v23->IoStatus.Information = 0;
        break;
      default:
LABEL_58:
        v35 = (int *)IofCallDriver(deviceObject, v23);
        goto LABEL_59;
    }
    v23->IoStatus.Status = (int)v35;
    goto LABEL_59;
  }
  return result;
}