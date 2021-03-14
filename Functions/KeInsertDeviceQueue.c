char __fastcall KeInsertDeviceQueue(char a1, _LIST_ENTRY *a2, _KDEVICE_QUEUE *DeviceQueue, _KDEVICE_QUEUE_ENTRY *DeviceQueueEntry)
{
  _KDEVICE_QUEUE *v4; // esi
  char v5; // cl
  char Inserted_3; // [esp+17h] [ebp+Bh]

  v4 = DeviceQueue;
  if ( DeviceQueue->Type != 20 )
    RtlAssert(
      (int)a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "(DeviceQueue)->Type == DeviceQueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x81u,
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
      0x82u,
      0);
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        (int)a2,
        v5,
        (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        (int)DeviceQueue,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        0x88u,
        0);
  }
  if ( DeviceQueue->Busy == 1 )
  {
    a2 = DeviceQueue->DeviceListHead.Blink;
    DeviceQueueEntry->DeviceListEntry.Flink = &DeviceQueue->DeviceListHead;
    DeviceQueueEntry->DeviceListEntry.Blink = a2;
    a2->Flink = &DeviceQueueEntry->DeviceListEntry;
    Inserted_3 = 1;
    v4->DeviceListHead.Blink = &DeviceQueueEntry->DeviceListEntry;
  }
  else
  {
    DeviceQueue->Busy = 1;
    Inserted_3 = 0;
  }
  DeviceQueueEntry->Inserted = Inserted_3;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a2,
      Inserted_3,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x99u,
      0);
  return Inserted_3;
}