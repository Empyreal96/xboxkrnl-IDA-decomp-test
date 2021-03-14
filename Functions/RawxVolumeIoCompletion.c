int __stdcall RawxVolumeIoCompletion(_DEVICE_OBJECT *DeviceObject, _IRP *Irp, void *Context)
{
  void *v3; // esi
  _IO_STACK_LOCATION *v4; // ecx
  _FILE_OBJECT *v5; // edx

  v3 = DeviceObject->DeviceExtension;
  v4 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( Irp->PendingReturned )
    *(_BYTE *)(Irp->Tail.Overlay.PacketType + 3) |= 1u;
  if ( (v4->MajorFunction == 2 || v4->MajorFunction == 3) && Irp->IoStatus.Status >= 0 )
  {
    v5 = v4->FileObject;
    if ( v5->Flags & 1 )
      v5->CurrentByteOffset.QuadPart = v4->Parameters.Read.ByteOffset.QuadPart + Irp->IoStatus.Information;
  }
  ExReleaseReadWriteLock((int)v3 + 12);
  return 0;
}