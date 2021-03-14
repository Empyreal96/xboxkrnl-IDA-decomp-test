void __userpurge IopDeleteFile(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *Object)
{
  void *v4; // ebx
  _IRP *v5; // eax
  _IRP *v6; // esi
  _IO_STACK_LOCATION *v7; // eax
  KIRQL v8; // al
  _LIST_ENTRY *v9; // edx
  _LIST_ENTRY *v10; // ecx
  _LIST_ENTRY *v11; // edi
  int v12; // edx
  int v13; // ecx
  KIRQL v14; // al
  _LIST_ENTRY *v15; // edx
  KIRQL v16; // cl
  _LIST_ENTRY *v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  void **v21; // eax
  int *v22; // edi
  int *v23; // [esp-4h] [ebp-24h]
  _KEVENT event; // [esp+8h] [ebp-18h]
  _IO_STATUS_BLOCK ioStatusBlock; // [esp+18h] [ebp-8h]
  _DEVICE_OBJECT *Objecta; // [esp+28h] [ebp+8h]

  v4 = Object;
  Objecta = (_DEVICE_OBJECT *)*((_DWORD *)Object + 1);
  if ( Objecta )
  {
    if ( !(*((_BYTE *)v4 + 3) & 0x20) )
      IopCloseFile(a1, a2, a3, (int)Objecta, v4, 1u);
    if ( *((_BYTE *)v4 + 3) & 1 )
      IopAcquireFileObjectLock((int)v4, a1);
    event.Header.SignalState = 0;
    *((_DWORD *)v4 + 15) = 0;
    event.Header.WaitListHead.Blink = &event.Header.WaitListHead;
    event.Header.WaitListHead.Flink = &event.Header.WaitListHead;
    event.Header.Type = 1;
    event.Header.Size = 4;
    v23 = a3;
    v5 = IopAllocateIrpMustSucceed(a2, a1, Objecta->StackSize);
    v6 = v5;
    v7 = v5->Tail.Overlay.CurrentStackLocation;
    v7[-1].FileObject = (_FILE_OBJECT *)v4;
    v7[-1].MajorFunction = 1;
    v6->UserIosb = &ioStatusBlock;
    v6->UserEvent = &event;
    v6->Tail.Overlay.OriginalFileObject = (_FILE_OBJECT *)v4;
    v6->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v6->Flags = 68;
    v8 = KfRaiseIrql(1);
    v9 = &v6->Tail.Overlay.Thread->IrpList;
    v10 = v9->Flink;
    v11 = &v6->ThreadListEntry;
    v6->ThreadListEntry.Flink = v9->Flink;
    v6->ThreadListEntry.Blink = v9;
    v10->Blink = &v6->ThreadListEntry;
    v9->Flink = &v6->ThreadListEntry;
    KfLowerIrql(v8);
    if ( IofCallDriver(Objecta, v6) == 259 )
      KeWaitForSingleObject(v13, v12, &event, 0, 0, 0, 0);
    v14 = KfRaiseIrql(1);
    v15 = v11->Flink;
    v16 = v14;
    v17 = v6->ThreadListEntry.Blink;
    v17->Flink = v11->Flink;
    v15->Blink = v17;
    v6->ThreadListEntry.Blink = v11;
    v11->Flink = v11;
    KfLowerIrql(v16);
    IoFreeIrp(v19, v18, v6);
    v21 = (void **)*((_DWORD *)v4 + 8);
    v22 = v23;
    if ( v21 )
    {
      ObfDereferenceObject(*v21, v20);
      ExFreePool(*((void **)v4 + 8));
    }
    IopDecrementDeviceObjectRef(v22, Objecta);
  }
}