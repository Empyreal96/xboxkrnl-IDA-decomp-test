int __stdcall IdexDiskGetPartitionInfo(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  if ( *(_DWORD *)(Irp->Tail.Overlay.PacketType + 4) < 0x20u )
    return -1073741789;
  qmemcpy(Irp->UserBuffer, (char *)DeviceObject->DeviceExtension + 4, 0x20u);
  Irp->IoStatus.Information = 32;
  return 0;
}