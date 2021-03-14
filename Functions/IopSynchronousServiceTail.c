int __userpurge IopSynchronousServiceTail@<eax>(int *a1@<edi>, int a2@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, _FILE_OBJECT *FileObject, int DeferredIoCompletion, char SynchronousIo)
{
  int v7; // edx
  int v8; // ST10_4
  KIRQL v9; // al
  _LIST_ENTRY *v10; // edx
  KIRQL v11; // cl
  _LIST_ENTRY *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  int v17; // edx
  int v18; // ecx
  _FILE_OBJECT *v19; // edi

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v7, v8, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x4AAu, 0);
  }
  v9 = KfRaiseIrql(1);
  v10 = &Irp->Tail.Overlay.Thread->IrpList;
  v11 = v9;
  v12 = v10->Flink;
  Irp->ThreadListEntry.Flink = v10->Flink;
  Irp->ThreadListEntry.Blink = v10;
  v12->Blink = &Irp->ThreadListEntry;
  v10->Flink = &Irp->ThreadListEntry;
  KfLowerIrql(v11);
  v13 = IofCallDriver(DeviceObject, Irp);
  v16 = v13;
  if ( (_BYTE)DeferredIoCompletion && v13 != 259 )
  {
    if ( Irp->PendingReturned )
      RtlAssert(
        v14,
        v15,
        (int *)&Irp->Type,
        v13,
        "!Irp->PendingReturned",
        "d:\\xbox-apr03\\private\\ntos\\io\\internal.c",
        0x4CCu,
        0);
    HIBYTE(DeferredIoCompletion) = KfRaiseIrql(1);
    IopCompleteRequest(
      v18,
      v17,
      (_KAPC *)&Irp->Tail,
      (void (__stdcall **)(void *, void *, void *))&DeferredIoCompletion,
      (void **)&DeferredIoCompletion,
      (void **)&FileObject,
      (void **)&DeferredIoCompletion);
    KfLowerIrql(SHIBYTE(DeferredIoCompletion));
  }
  if ( SynchronousIo )
  {
    v19 = FileObject;
    if ( v16 == 259 )
    {
      KeWaitForSingleObject(v15, v14, &FileObject->Event, 0, 0, 0, 0);
      v16 = v19->FinalStatus;
    }
    IopReleaseFileObjectLock((int)v19, v14);
  }
  return v16;
}