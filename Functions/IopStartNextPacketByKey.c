void __userpurge IopStartNextPacketByKey(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *DeviceObject, unsigned int Key)
{
  _LIST_ENTRY *v6; // eax
  _DRIVER_OBJECT *v7; // ecx
  _IRP *v8; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0xA67u,
      0);
  DeviceObject->CurrentIrp = 0;
  v6 = KeRemoveByKeyDeviceQueue(a2, a1, &DeviceObject->DeviceQueue, Key);
  if ( v6 )
  {
    v7 = DeviceObject->DriverObject;
    DeviceObject->StartIoFlags |= 1u;
    v8 = (_IRP *)&v6[-8].Blink;
    DeviceObject->CurrentIrp = v8;
    v7->DriverStartIo(DeviceObject, v8);
    DeviceObject->StartIoFlags &= 0xFEu;
  }
}