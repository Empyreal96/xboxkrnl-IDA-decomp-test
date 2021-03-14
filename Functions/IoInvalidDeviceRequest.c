int __userpurge IoInvalidDeviceRequest@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  Irp->IoStatus.Status = -1073741808;
  IofCompleteRequest(Irp, 0, a1);
  return -1073741808;
}