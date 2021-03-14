char __userpurge KeRemoveEntryDeviceQueue@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KDEVICE_QUEUE *DeviceQueue, _KDEVICE_QUEUE_ENTRY *DeviceQueueEntry)
{
  KIRQL v5; // al
  char v6; // bl
  _LIST_ENTRY *v7; // esi
  _LIST_ENTRY *v8; // edx

  if ( DeviceQueue->Type != 20 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "(DeviceQueue)->Type == DeviceQueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x1AEu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x1AFu,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = DeviceQueueEntry->Inserted;
  if ( v6 == 1 )
  {
    v7 = DeviceQueueEntry->DeviceListEntry.Flink;
    DeviceQueueEntry->Inserted = 0;
    v8 = DeviceQueueEntry->DeviceListEntry.Blink;
    v8->Flink = v7;
    v7->Blink = v8;
  }
  KfLowerIrql(v5);
  return v6;
}