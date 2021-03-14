_LIST_ENTRY *__fastcall KeRemoveByKeyDeviceQueue(int a1, int a2, _KDEVICE_QUEUE *DeviceQueue, unsigned int SortKey)
{
  _LIST_ENTRY *v4; // ecx
  _KDEVICE_QUEUE *v5; // edx
  _LIST_ENTRY *v6; // esi
  _LIST_ENTRY *v7; // eax
  _LIST_ENTRY *v8; // eax

  if ( DeviceQueue->Type != 20 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "(DeviceQueue)->Type == DeviceQueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x159u,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
  {
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x15Au,
      0);
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        a2,
        a1,
        (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        (int)DeviceQueue,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        0x160u,
        0);
  }
  if ( DeviceQueue->Busy != 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)DeviceQueue,
      "DeviceQueue->Busy == TRUE",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x162u,
      0);
  v4 = &DeviceQueue->DeviceListHead;
  v5 = (_KDEVICE_QUEUE *)DeviceQueue->DeviceListHead.Flink;
  if ( v5 == (_KDEVICE_QUEUE *)&DeviceQueue->DeviceListHead )
  {
    DeviceQueue->Busy = 0;
    v6 = 0;
  }
  else
  {
    v7 = DeviceQueue->DeviceListHead.Flink;
    do
    {
      v6 = v7;
      if ( (_LIST_ENTRY *)SortKey <= v7[1].Flink )
        break;
      v7 = v7->Flink;
    }
    while ( v7 != v4 );
    if ( v7 == v4 )
    {
      v8 = *(_LIST_ENTRY **)&v5->Type;
      v4 = v5->DeviceListHead.Flink;
      v6 = DeviceQueue->DeviceListHead.Flink;
    }
    else
    {
      v8 = v6->Flink;
      v4 = v6->Blink;
    }
    v4->Flink = v8;
    v8->Blink = v4;
    LOBYTE(v6[1].Blink) = 0;
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)v5,
      (int)v4,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      (int)v6,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x188u,
      0);
  return v6;
}