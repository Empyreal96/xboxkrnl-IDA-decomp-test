int __stdcall RawxFsdCleanup(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _RAW_VOLUME_EXTENSION *v2; // esi
  int v3; // edx

  v2 = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  RawxAcquireVolumeMutexExclusive((_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  IoRemoveShareAccess(
    (int *)&Irp->Type,
    (int)v2,
    *(_FILE_OBJECT **)(Irp->Tail.Overlay.PacketType + 24),
    &v2->ShareAccess);
  RawxReleaseVolumeMutex(v2);
  Irp->IoStatus.Status = 0;
  LOBYTE(v3) = 0;
  IofCompleteRequest(Irp, v3, (int *)&Irp->Type);
  return 0;
}