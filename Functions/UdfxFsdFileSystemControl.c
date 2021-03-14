int *__stdcall UdfxFsdFileSystemControl(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int *v2; // edi

  if ( *(_DWORD *)(Irp->Tail.Overlay.PacketType + 16) == 589856 )
    v2 = (int *)DeviceObject->DriverObject->DriverDismountVolume(DeviceObject);
  else
    v2 = (int *)-1073741808;
  Irp->IoStatus.Information = 0;
  Irp->IoStatus.Status = (int)v2;
  IofCompleteRequest(Irp, 0, v2);
  return v2;
}