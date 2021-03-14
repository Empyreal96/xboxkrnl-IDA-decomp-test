void __userpurge IopCloseFile(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Object, unsigned int SystemHandleCount)
{
  int v6; // edx
  int v7; // ST1C_4
  int v8; // esi
  _IRP *v9; // esi
  int v10; // eax
  KIRQL v11; // al
  _LIST_ENTRY *v12; // edx
  _LIST_ENTRY *v13; // ecx
  _LIST_ENTRY *v14; // edi
  int v15; // edx
  int v16; // ecx
  KIRQL v17; // al
  _LIST_ENTRY *v18; // edx
  KIRQL v19; // cl
  _LIST_ENTRY *v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  _KEVENT event; // [esp+0h] [ebp-10h]
  _DEVICE_OBJECT *deviceObject; // [esp+1Ch] [ebp+Ch]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\objsup.c", 0x3Cu, 0);
  }
  if ( SystemHandleCount == 1 )
  {
    *((_BYTE *)Object + 3) |= 0x20u;
    v8 = *((_DWORD *)Object + 1);
    deviceObject = (_DEVICE_OBJECT *)*((_DWORD *)Object + 1);
    if ( *((_BYTE *)Object + 3) & 1 )
      IopAcquireFileObjectLock((int)Object, a1);
    event.Header.WaitListHead.Blink = &event.Header.WaitListHead;
    event.Header.WaitListHead.Flink = &event.Header.WaitListHead;
    event.Header.Type = 1;
    event.Header.Size = 4;
    event.Header.SignalState = 0;
    *((_DWORD *)Object + 15) = 0;
    v9 = IopAllocateIrpMustSucceed(a2, a1, *(_BYTE *)(v8 + 30));
    v9->Tail.Overlay.OriginalFileObject = (_FILE_OBJECT *)Object;
    v9->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v9->UserEvent = &event;
    v9->UserIosb = &v9->IoStatus;
    v10 = v9->Tail.Overlay.PacketType - 36;
    v9->Overlay.AllocationSize.LowPart = 0;
    v9->Flags = 68;
    *(_BYTE *)v10 = 13;
    *(_DWORD *)(v10 + 24) = Object;
    v11 = KfRaiseIrql(1);
    v12 = &v9->Tail.Overlay.Thread->IrpList;
    v13 = v12->Flink;
    v14 = &v9->ThreadListEntry;
    v9->ThreadListEntry.Flink = v12->Flink;
    v9->ThreadListEntry.Blink = v12;
    v13->Blink = &v9->ThreadListEntry;
    v12->Flink = &v9->ThreadListEntry;
    KfLowerIrql(v11);
    if ( IofCallDriver(deviceObject, v9) == 259 )
      KeWaitForSingleObject(v16, v15, &event, UserRequest, 0, 0, 0);
    v17 = KfRaiseIrql(1);
    v18 = v14->Flink;
    v19 = v17;
    v20 = v9->ThreadListEntry.Blink;
    v20->Flink = v14->Flink;
    v18->Blink = v20;
    v9->ThreadListEntry.Blink = v14;
    v14->Flink = v14;
    KfLowerIrql(v19);
    IoFreeIrp(v22, v21, v9);
    if ( *((_BYTE *)Object + 3) & 1 )
      IopReleaseFileObjectLock((int)Object, v23);
  }
}