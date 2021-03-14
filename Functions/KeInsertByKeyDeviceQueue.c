char __fastcall KeInsertByKeyDeviceQueue(int a1, _LIST_ENTRY *a2, _KDEVICE_QUEUE *DeviceQueue, _KDEVICE_QUEUE_ENTRY *DeviceQueueEntry, unsigned int SortKey)
{
  _KDEVICE_QUEUE *v5; // esi
  int v6; // ecx
  _LIST_ENTRY *v7; // ecx
  _LIST_ENTRY *v8; // edx
  _LIST_ENTRY *v9; // ecx
  char Inserted_3; // [esp+17h] [ebp+Bh]

  v5 = DeviceQueue;
  if ( DeviceQueue->Type != 20 )
    RtlAssert(
      (int)a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "(DeviceQueue)->Type == DeviceQueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0xC7u,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
  {
    RtlAssert(
      (int)a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0xC8u,
      0);
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        (int)a2,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        (int)DeviceQueue,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        0xCEu,
        0);
  }
  v7 = (_LIST_ENTRY *)SortKey;
  DeviceQueueEntry->SortKey = SortKey;
  if ( DeviceQueue->Busy == 1 )
  {
    v8 = &DeviceQueue->DeviceListHead;
    v9 = DeviceQueue->DeviceListHead.Flink;
    Inserted_3 = 1;
    while ( v9 != v8 )
    {
      v5 = (_KDEVICE_QUEUE *)SortKey;
      if ( (_LIST_ENTRY *)SortKey < v9[1].Flink )
        break;
      v9 = v9->Flink;
    }
    v7 = v9->Blink;
    a2 = v7->Flink;
    DeviceQueueEntry->DeviceListEntry.Flink = v7->Flink;
    DeviceQueueEntry->DeviceListEntry.Blink = v7;
    a2->Blink = &DeviceQueueEntry->DeviceListEntry;
    v7->Flink = &DeviceQueueEntry->DeviceListEntry;
  }
  else
  {
    DeviceQueue->Busy = 1;
    Inserted_3 = 0;
  }
  LOBYTE(v7) = Inserted_3;
  DeviceQueueEntry->Inserted = Inserted_3;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a2,
      (int)v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)v5,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0xEAu,
      0);
  return Inserted_3;
}