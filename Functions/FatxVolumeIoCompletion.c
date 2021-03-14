int __fastcall FatxVolumeIoCompletion(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, void *Context)
{
  _IO_STACK_LOCATION *v5; // edi
  _FILE_OBJECT *v6; // eax
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+10h] [ebp+8h]

  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  if ( Irp->PendingReturned )
    v5->Control |= 1u;
  if ( (v5->MajorFunction == 2 || v5->MajorFunction == 3) && Irp->IoStatus.Status >= 0 )
  {
    if ( !Irp->IoStatus.Information )
      RtlAssert(
        a2,
        a1,
        (int *)&v5->MajorFunction,
        (int)Irp,
        "Irp->IoStatus.Information > 0",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
        0x50u,
        0);
    if ( (VolumeExtension->CacheExtension.SectorSize - 1) & Irp->IoStatus.Information )
      RtlAssert(
        a2,
        a1,
        (int *)&v5->MajorFunction,
        (int)Irp,
        "FatxIsSectorAligned(VolumeExtension, Irp->IoStatus.Information)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
        0x51u,
        0);
    v6 = v5->FileObject;
    if ( v6->Flags & 1 )
      v6->CurrentByteOffset.QuadPart = Irp->IoStatus.Information + v5->Parameters.Read.ByteOffset.QuadPart;
  }
  FatxDpcReleaseVolumeMutex(VolumeExtension);
  return 0;
}