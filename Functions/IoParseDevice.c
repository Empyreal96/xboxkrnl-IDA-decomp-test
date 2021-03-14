int *__userpurge IoParseDevice@<eax>(int *a1@<edi>, int a2@<esi>, void *ParseObject, _OBJECT_TYPE *ObjectType, unsigned int Attributes, _STRING *CompleteName, _STRING *RemainingName, void *Context, void **Object)
{
  int v9; // edx
  int v10; // ST10_4
  void *v11; // esi
  bool v12; // zf
  void **v13; // ebx
  int *result; // eax
  int v15; // eax
  _DEVICE_OBJECT *v16; // ebx
  KIRQL v17; // al
  unsigned int v18; // edx
  signed int v19; // edi
  _DEVICE_OBJECT *v20; // edi
  int v21; // edx
  int v22; // ecx
  bool v23; // al
  int v24; // edx
  int v25; // ecx
  _IRP *v26; // ebx
  _IO_STACK_LOCATION *v27; // edx
  char v28; // al
  int v29; // edx
  int v30; // ecx
  _STRING *v31; // edi
  _STRING *v32; // eax
  _FILE_OBJECT *v33; // eax
  KIRQL v34; // al
  _LIST_ENTRY *v35; // edx
  _LIST_ENTRY *v36; // ecx
  int *v37; // edi
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // ecx
  int *v42; // edi
  int v43; // eax
  _DWORD *v44; // ecx
  int v45; // edx
  _FILE_OBJECT *v46; // ecx
  _FILE_OBJECT *v47; // ST10_4
  _OBJECT_ATTRIBUTES objectAttributes; // [esp+Ch] [ebp-1Ch]
  _IO_STATUS_BLOCK ioStatus; // [esp+18h] [ebp-10h]
  _IO_STACK_LOCATION *irpSp; // [esp+20h] [ebp-8h]
  _FILE_OBJECT *fileObject; // [esp+24h] [ebp-4h]
  _DEVICE_OBJECT *deviceObject; // [esp+30h] [ebp+8h]
  int *status; // [esp+38h] [ebp+10h]
  int statusa; // [esp+38h] [ebp+10h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, 0, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\parse.c", 0xEBu, 0);
  }
  v11 = Context;
  v12 = Context == 0;
  v13 = Object;
  *Object = 0;
  if ( v12 )
  {
    if ( !RemainingName->Length )
    {
      ObfReferenceObject(ParseObject);
      *v13 = ParseObject;
      return 0;
    }
    return (int *)-1073741788;
  }
  if ( *(_WORD *)v11 == 8 && *((_WORD *)v11 + 1) == 64 )
  {
    v15 = *((_DWORD *)v11 + 5);
    v16 = (_DEVICE_OBJECT *)ParseObject;
    if ( v15 )
      v16 = *(_DEVICE_OBJECT **)(v15 + 4);
    v17 = KeRaiseIrqlToDpcLevel();
    if ( v16->DeletePending || (v18 = v16->Flags, v18 & 0x10) )
    {
      v19 = -1073741810;
      goto LABEL_17;
    }
    if ( v18 & 2 && v16->ReferenceCount && !*((_DWORD *)v11 + 5) )
    {
      v19 = -1073741790;
LABEL_17:
      KfLowerIrql(v17);
      *((_DWORD *)v11 + 2) = v19;
      return (int *)v19;
    }
    v20 = v16->MountedOrSelfDevice;
    deviceObject = v16->MountedOrSelfDevice;
    if ( !v20 )
    {
      while ( 1 )
      {
        KfLowerIrql(v17);
        v23 = !RemainingName->Length && !*((_DWORD *)v11 + 5);
        result = IopMountVolume(v22, v21, v16, v23);
        if ( (signed int)result < 0 )
          goto LABEL_34;
        v17 = KeRaiseIrqlToDpcLevel();
        deviceObject = v16->MountedOrSelfDevice;
        if ( v16->MountedOrSelfDevice )
        {
          v20 = v16->MountedOrSelfDevice;
          break;
        }
      }
    }
    ++v20->ReferenceCount;
    KfLowerIrql(v17);
    RtlMapGenericMask((unsigned int *)v11 + 12, &IopFileMapping);
    v26 = IoAllocateIrp(v25, v24, v20->StackSize);
    if ( !v26 )
    {
      IopDecrementDeviceObjectRef((int *)&v20->Type, v20);
      return (int *)-1073741670;
    }
    v27 = (_IO_STACK_LOCATION *)(v26->Tail.Overlay.PacketType - 36);
    v26->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v26->Flags = 140;
    v27->MajorFunction = 0;
    v28 = *((_BYTE *)v11 + 40);
    irpSp = v27;
    v27->Flags = v28;
    if ( !(Attributes & 0x40) )
      v27->Flags = v28 | 0x80;
    v26->Overlay.AllocationSize.LowPart = *((_DWORD *)v11 + 6);
    v26->Overlay.AllocationSize.HighPart = *((_DWORD *)v11 + 7);
    v27->Parameters.Create.Options = *((_DWORD *)v11 + 8) & 0xFFFFFF | (*((_DWORD *)v11 + 11) << 24);
    v27->Parameters.Create.FileAttributes = *((_WORD *)v11 + 18);
    v27->Parameters.Create.ShareAccess = *((_WORD *)v11 + 19);
    v27->Parameters.Create.DesiredAccess = *((_DWORD *)v11 + 12);
    v27->Parameters.Read.ByteOffset.HighPart = (int)RemainingName;
    v26->UserIosb = &ioStatus;
    if ( *((_BYTE *)v11 + 60) || *((_BYTE *)v11 + 61) )
    {
      v31 = (_STRING *)*((_DWORD *)v11 + 14);
      Context = 0;
      RemainingName = v31;
      memset(v31, 0, 0x60u);
      v32 = RemainingName;
      fileObject = (_FILE_OBJECT *)&RemainingName[2];
      *(_DWORD *)&RemainingName[1].Length = &IoFileObjectType;
      *(_DWORD *)&v32->Length = 1;
    }
    else
    {
      objectAttributes.RootDirectory = 0;
      objectAttributes.ObjectName = 0;
      objectAttributes.Attributes = Attributes;
      Context = (void *)1;
      status = (int *)ObCreateObject(&IoFileObjectType, &objectAttributes, 0x48u, (void **)&fileObject);
      if ( (signed int)status < 0 )
      {
        IoFreeIrp(v30, v29, v26);
        IopDecrementDeviceObjectRef((int *)&v20->Type, v20);
        result = status;
LABEL_34:
        *((_DWORD *)v11 + 2) = result;
        return result;
      }
      memset(fileObject, 0, sizeof(_FILE_OBJECT));
      fileObject->Type = 5;
      fileObject->RelatedFileObject = (_FILE_OBJECT *)*((_DWORD *)v11 + 5);
      if ( *((_BYTE *)v11 + 32) & 0x30 )
      {
        fileObject->Flags = 1;
        if ( *((_BYTE *)v11 + 32) & 0x10 )
          fileObject->Flags |= 2u;
      }
      v33 = fileObject;
      if ( fileObject->Flags & 1 )
      {
        fileObject->LockCount = -1;
        fileObject->Lock.Header.Type = 1;
        fileObject->Lock.Header.Size = 4;
        fileObject->Lock.Header.SignalState = 0;
        InitializeListHead(&fileObject->Lock.Header.WaitListHead);
        v33 = fileObject;
      }
      if ( *((_BYTE *)v11 + 32) & 8 )
      {
        v33->Flags |= 4u;
        v33 = fileObject;
      }
      if ( *((_BYTE *)v11 + 32) & 4 )
      {
        v33->Flags |= 8u;
        v33 = fileObject;
      }
      v27 = irpSp;
      if ( !(*((_BYTE *)v11 + 33) & 8) )
      {
LABEL_37:
        v33->Type = 5;
        fileObject->RelatedFileObject = (_FILE_OBJECT *)*((_DWORD *)v11 + 5);
        fileObject->DeviceObject = deviceObject;
        v26->Tail.Overlay.OriginalFileObject = fileObject;
        v27->FileObject = fileObject;
        fileObject->Event.Header.Type = 0;
        fileObject->Event.Header.Size = 4;
        fileObject->Event.Header.SignalState = 0;
        InitializeListHead(&fileObject->Event.Header.WaitListHead);
        *((_DWORD *)v11 + 1) = fileObject;
        v34 = KfRaiseIrql(1);
        v35 = &v26->Tail.Overlay.Thread->IrpList;
        v36 = v35->Flink;
        v37 = (int *)&v26->ThreadListEntry;
        v26->ThreadListEntry.Flink = v35->Flink;
        v26->ThreadListEntry.Blink = v35;
        v36->Blink = &v26->ThreadListEntry;
        v35->Flink = &v26->ThreadListEntry;
        KfLowerIrql(v34);
        if ( IofCallDriver(deviceObject, v26) == 259 )
        {
          KeWaitForSingleObject(v39, v38, &fileObject->Event, 0, 0, 0, 0);
          v42 = (int *)ioStatus.Status;
        }
        else
        {
          if ( v26->PendingReturned )
            RtlAssert(
              v38,
              v39,
              v37,
              (int)v11,
              "!irp->PendingReturned",
              "d:\\xbox-apr03\\private\\ntos\\io\\parse.c",
              0x22Fu,
              0);
          HIBYTE(RemainingName) = KfRaiseIrql(1);
          ioStatus.Status = v26->IoStatus.Status;
          ioStatus.Information = v26->IoStatus.Information;
          statusa = ioStatus.Status;
          fileObject->Event.Header.SignalState = 1;
          v43 = *v37;
          v44 = &v26->ThreadListEntry.Blink->Flink;
          *v44 = *v37;
          *(_DWORD *)(v43 + 4) = v44;
          v26->ThreadListEntry.Blink = (_LIST_ENTRY *)v37;
          *v37 = (int)v37;
          IoFreeIrp((int)v44, v45, v26);
          KfLowerIrql(SHIBYTE(RemainingName));
          v42 = (int *)statusa;
        }
        if ( v42 == (int *)260 )
          RtlAssert(
            v40,
            v41,
            (int *)0x104,
            (int)v11,
            "status != STATUS_REPARSE",
            "d:\\xbox-apr03\\private\\ntos\\io\\parse.c",
            0x24Bu,
            0);
        *((_DWORD *)v11 + 3) = ioStatus.Information;
        if ( (signed int)v42 >= 0 )
        {
          if ( Context )
          {
            v46 = fileObject;
            *Object = fileObject;
            *((_DWORD *)v11 + 4) = -1096154543;
            ObfReferenceObject(v46);
            result = (int *)ioStatus.Status;
            goto LABEL_34;
          }
          if ( *((_BYTE *)v11 + 60) )
            v42 = (int *)IoQueryFileInformation(
                           v42,
                           (int)v11,
                           fileObject,
                           FileNetworkOpenInformation,
                           0x38u,
                           *((void **)v11 + 13),
                           (unsigned int *)&RemainingName);
          v47 = fileObject;
          *((_DWORD *)v11 + 4) = -1096154543;
          IopDeleteFile(v40, v41, v42, v47);
          *((_DWORD *)v11 + 1) = 0;
          result = (int *)-1073741772;
        }
        else
        {
          v12 = Context == 0;
          fileObject->DeviceObject = 0;
          if ( !v12 )
            ObfDereferenceObject(fileObject, v40);
          *((_DWORD *)v11 + 1) = 0;
          IopDecrementDeviceObjectRef(v42, deviceObject);
          result = v42;
        }
        *((_DWORD *)v11 + 2) = v42;
        return result;
      }
      v33->Flags |= 0x40u;
    }
    v33 = fileObject;
    goto LABEL_37;
  }
  return (int *)-1073741788;
}