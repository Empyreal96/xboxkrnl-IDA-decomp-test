int __userpurge UdfxFsdDeviceControl@<eax>(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _DEVICE_OBJECT **v3; // eax
  int result; // eax
  _IRP *v5; // edx

  v3 = (_DEVICE_OBJECT **)DeviceObject->DeviceExtension;
  if ( *((_BYTE *)v3 + 40) )
  {
    Irp->IoStatus.Status = -1073741202;
    IofCompleteRequest(Irp, 0, a1);
    result = -1073741202;
  }
  else
  {
    v5 = Irp;
    ++v5->CurrentLocation;
    v5->Tail.Overlay.PacketType += 36;
    result = IofCallDriver(*v3, Irp);
  }
  return result;
}