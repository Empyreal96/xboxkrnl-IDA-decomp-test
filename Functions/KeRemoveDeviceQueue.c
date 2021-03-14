_LIST_ENTRY *__userpurge KeRemoveDeviceQueue@<eax>(_LIST_ENTRY *a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KDEVICE_QUEUE *DeviceQueue)
{
  _LIST_ENTRY *v4; // ecx
  _LIST_ENTRY *v5; // eax
  _LIST_ENTRY *v6; // ebx

  if ( DeviceQueue->Type != 20 )
    RtlAssert(
      (int)a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "(DeviceQueue)->Type == DeviceQueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x10Fu,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
  {
    RtlAssert(
      (int)a1,
      a2,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x110u,
      0);
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        (int)a1,
        a2,
        (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
        (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
        0x116u,
        0);
  }
  if ( DeviceQueue->Busy != 1 )
    RtlAssert(
      (int)a1,
      a2,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "DeviceQueue->Busy == TRUE",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x118u,
      0);
  v4 = &DeviceQueue->DeviceListHead;
  v5 = DeviceQueue->DeviceListHead.Flink;
  if ( v5 == &DeviceQueue->DeviceListHead )
  {
    DeviceQueue->Busy = 0;
    v6 = 0;
  }
  else
  {
    v4 = v5->Flink;
    a1 = v5->Blink;
    a1->Flink = v5->Flink;
    v4->Blink = a1;
    v6 = v5;
    LOBYTE(v5[1].Blink) = 0;
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a1,
      (int)v4,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\devquobj.c",
      0x12Eu,
      0);
  return v6;
}