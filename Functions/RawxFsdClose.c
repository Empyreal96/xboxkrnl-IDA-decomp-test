int __stdcall RawxFsdClose(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _RAW_VOLUME_EXTENSION *v2; // esi
  int v3; // edx
  int v4; // ecx
  int v5; // edx

  v2 = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  RawxAcquireVolumeMutexExclusive((_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  if ( v2->ShareAccess.OpenCount || !v2->Dismounted )
  {
    RawxReleaseVolumeMutex(v2);
  }
  else
  {
    RawxReleaseVolumeMutex(v2);
    RawxDeleteVolumeDevice(v4, v3, DeviceObject);
  }
  Irp->IoStatus.Status = 0;
  LOBYTE(v5) = 0;
  IofCompleteRequest(Irp, v5, (int *)&DeviceObject->Type);
  return 0;
}