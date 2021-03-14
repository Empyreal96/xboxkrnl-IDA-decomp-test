int __userpurge IdexDriverIrpReturnSuccess@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  Irp->IoStatus.Status = 0;
  IofCompleteRequest(Irp, 0, a1);
  return 0;
}