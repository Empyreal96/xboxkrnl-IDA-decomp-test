void __stdcall IoQueueThreadIrp(_IRP *Irp)
{
  KIRQL v1; // al
  _LIST_ENTRY *v2; // edx
  _LIST_ENTRY *v3; // ebx

  v1 = KfRaiseIrql(1);
  v2 = &Irp->Tail.Overlay.Thread->IrpList;
  v3 = v2->Flink;
  Irp->ThreadListEntry.Flink = v2->Flink;
  Irp->ThreadListEntry.Blink = v2;
  v3->Blink = &Irp->ThreadListEntry;
  v2->Flink = &Irp->ThreadListEntry;
  KfLowerIrql(v1);
}