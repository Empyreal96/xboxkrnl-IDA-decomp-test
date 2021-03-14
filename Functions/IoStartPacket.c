void __stdcall IoStartPacket(_DEVICE_OBJECT *DeviceObject, _IRP *Irp, unsigned int *Key)
{
  _LIST_ENTRY *v3; // edx
  int v4; // ecx
  KIRQL v5; // bl
  char v6; // al
  _DRIVER_OBJECT *v7; // eax
  _LIST_ENTRY *v8; // edx
  int v9; // ecx

  v5 = KeRaiseIrqlToDpcLevel();
  if ( Key )
    v6 = KeInsertByKeyDeviceQueue(v4, v3, &DeviceObject->DeviceQueue, &Irp->Tail.Overlay.DeviceQueueEntry, *Key);
  else
    v6 = KeInsertDeviceQueue(v4, v3, &DeviceObject->DeviceQueue, &Irp->Tail.Overlay.DeviceQueueEntry);
  if ( !v6 )
  {
    v7 = DeviceObject->DriverObject;
    DeviceObject->StartIoFlags |= 1u;
    DeviceObject->CurrentIrp = Irp;
    v7->DriverStartIo(DeviceObject, Irp);
    DeviceObject->StartIoFlags &= 0xFEu;
    if ( DeviceObject->StartIoFlags & 2 )
      IopStartNextPacketDeferred(v8, v9, (int)DeviceObject, DeviceObject);
  }
  KfLowerIrql(v5);
}