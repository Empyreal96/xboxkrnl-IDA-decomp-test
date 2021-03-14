int __userpurge IopQueryXxxInformation@<eax>(int *a1@<edi>, int a2@<esi>, _FILE_OBJECT *FileObject, unsigned int InformationClass, unsigned int Length, void *Information, unsigned int *ReturnedLength, char FileInformation)
{
  int v8; // edx
  int v9; // ST18_4
  _FILE_OBJECT *v10; // ebx
  int v11; // edx
  int v12; // ecx
  _IRP *v13; // eax
  int v14; // edx
  _IRP *v15; // esi
  int v17; // eax
  KIRQL v18; // al
  _LIST_ENTRY *v19; // edx
  KIRQL v20; // cl
  _LIST_ENTRY *v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // esi
  _KEVENT event; // [esp+0h] [ebp-1Ch]
  _IO_STATUS_BLOCK localIoStatus; // [esp+10h] [ebp-Ch]
  _DEVICE_OBJECT *deviceObject; // [esp+18h] [ebp-4h]
  char synchronousIo_3; // [esp+27h] [ebp+Bh]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x3B4u, 0);
  }
  v10 = FileObject;
  ObfReferenceObject(FileObject);
  if ( FileObject->Flags & 1 )
  {
    IopAcquireFileObjectLock((int)FileObject, v11);
    FileObject->Event.Header.SignalState = 0;
    synchronousIo_3 = 1;
  }
  else
  {
    event.Header.SignalState = 0;
    event.Header.Type = 1;
    event.Header.Size = 4;
    event.Header.WaitListHead.Blink = &event.Header.WaitListHead;
    event.Header.WaitListHead.Flink = &event.Header.WaitListHead;
    synchronousIo_3 = 0;
  }
  deviceObject = v10->DeviceObject;
  v13 = IoAllocateIrp(v12, v11, deviceObject->StackSize);
  v15 = v13;
  if ( !v13 )
    return IopAllocateIrpCleanup(v14, a1, 0, v10, 0);
  v13->Tail.Overlay.OriginalFileObject = v10;
  v13->Tail.Overlay.Thread = (_ETHREAD *)thread;
  v13->UserBuffer = Information;
  if ( !synchronousIo_3 )
  {
    v13->UserEvent = &event;
    v13->Flags = 4;
  }
  v13->UserIosb = &localIoStatus;
  v17 = v13->Tail.Overlay.PacketType - 36;
  *(_BYTE *)v17 = FileInformation == 0 ? 7 : 4;
  *(_DWORD *)(v17 + 4) = Length;
  *(_DWORD *)(v17 + 8) = InformationClass;
  *(_DWORD *)(v17 + 24) = v10;
  v18 = KfRaiseIrql(1);
  v19 = &v15->Tail.Overlay.Thread->IrpList;
  v20 = v18;
  v21 = v19->Flink;
  v15->ThreadListEntry.Flink = v19->Flink;
  v15->ThreadListEntry.Blink = v19;
  v21->Blink = &v15->ThreadListEntry;
  v19->Flink = &v15->ThreadListEntry;
  KfLowerIrql(v20);
  v22 = IofCallDriver(deviceObject, v15);
  v25 = v22;
  if ( synchronousIo_3 )
  {
    if ( v22 == 259 )
    {
      KeWaitForSingleObject(v24, v23, &v10->Event, 0, 0, 0, 0);
      v25 = v10->FinalStatus;
    }
    IopReleaseFileObjectLock((int)v10, v23);
  }
  else if ( v22 == 259 )
  {
    KeWaitForSingleObject(v24, v23, &event, 0, 0, 0, 0);
    v25 = localIoStatus.Status;
  }
  *ReturnedLength = localIoStatus.Information;
  return v25;
}