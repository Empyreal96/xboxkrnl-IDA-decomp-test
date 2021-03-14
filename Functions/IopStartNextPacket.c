void __userpurge IopStartNextPacket(_LIST_ENTRY *a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *DeviceObject)
{
  _LIST_ENTRY *v5; // eax
  _DRIVER_OBJECT *v6; // ecx
  _IRP *v7; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0xA1Au,
      0);
  DeviceObject->CurrentIrp = 0;
  v5 = KeRemoveDeviceQueue(a1, a2, a3, &DeviceObject->DeviceQueue);
  if ( v5 )
  {
    v6 = DeviceObject->DriverObject;
    DeviceObject->StartIoFlags |= 1u;
    v7 = (_IRP *)&v5[-8].Blink;
    DeviceObject->CurrentIrp = v7;
    v6->DriverStartIo(DeviceObject, v7);
    DeviceObject->StartIoFlags &= 0xFEu;
  }
}