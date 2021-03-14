int *__stdcall UdfxMountVolume(_DEVICE_OBJECT *TargetDeviceObject)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  _DEVICE_OBJECT *v4; // ecx
  int *v5; // esi
  int v6; // edx
  _UDF_VOLUME_EXTENSION *v7; // edi
  _DISK_GEOMETRY DiskGeometry; // [esp+Ch] [ebp-48h]
  LONGAD IcbRoot; // [esp+24h] [ebp-30h]
  LONGAD FileSetDescriptorExtent; // [esp+34h] [ebp-20h]
  EXTENTAD MainVolumeDescriptorSequenceExtent; // [esp+44h] [ebp-10h]
  _IRP *Irp; // [esp+4Ch] [ebp-8h]
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+50h] [ebp-4h]

  VolumeDeviceObject = 0;
  RtlEnterCriticalSectionAndRegion(&UdfxGlobalMutex);
  v5 = (int *)IoSynchronousDeviceIoControlRequest(
                v2,
                v1,
                0x2404Cu,
                TargetDeviceObject,
                0,
                0,
                &DiskGeometry,
                0x18u,
                0,
                0);
  if ( (signed int)v5 >= 0 )
  {
    if ( DiskGeometry.Cylinders.HighPart )
      RtlAssert(
        v3,
        (int)v4,
        (int *)&TargetDeviceObject->Type,
        (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        "DiskGeometry.Cylinders.HighPart == 0",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        0x4F3u,
        0);
    if ( DiskGeometry.TracksPerCylinder != 1 )
      RtlAssert(
        v3,
        (int)v4,
        (int *)&TargetDeviceObject->Type,
        (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        "DiskGeometry.TracksPerCylinder == 1",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        0x4F4u,
        0);
    if ( DiskGeometry.SectorsPerTrack != 1 )
      RtlAssert(
        v3,
        (int)v4,
        (int *)&TargetDeviceObject->Type,
        (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        "DiskGeometry.SectorsPerTrack == 1",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        0x4F5u,
        0);
    if ( DiskGeometry.BytesPerSector != 2048 )
      RtlAssert(
        v3,
        (int)v4,
        (int *)&TargetDeviceObject->Type,
        (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        "DiskGeometry.BytesPerSector == UDF_CD_SECTOR_SIZE",
        "d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
        0x4F6u,
        0);
    Irp = IoAllocateIrp((int)v4, v3, TargetDeviceObject->StackSize);
    if ( Irp )
    {
      v5 = UdfxCreateVolumeDevice(
             v4,
             (int *)&TargetDeviceObject->Type,
             (int)"d:\\xbox-apr03\\private\\ntos\\udfx\\mountvol.c",
             TargetDeviceObject,
             &DiskGeometry,
             &VolumeDeviceObject);
      if ( (signed int)v5 >= 0 )
      {
        v7 = (_UDF_VOLUME_EXTENSION *)VolumeDeviceObject->DeviceExtension;
        v5 = (int *)UdfxRecognizeVolume(
                      v6,
                      (int)v4,
                      (int)v5,
                      (_UDF_VOLUME_EXTENSION *)VolumeDeviceObject->DeviceExtension);
        if ( (signed int)v5 >= 0 )
        {
          v5 = (int *)UdfxProcessAnchorVolumeDescriptor(v6, (int)v4, (int)v5, v7, &MainVolumeDescriptorSequenceExtent);
          if ( (signed int)v5 >= 0 )
          {
            v5 = (int *)UdfxProcessVolumeDescriptorSequence(
                          (int)v4,
                          v6,
                          v7,
                          &MainVolumeDescriptorSequenceExtent,
                          &FileSetDescriptorExtent);
            if ( (signed int)v5 >= 0 )
            {
              v5 = (int *)UdfxProcessFileSetDescriptor((int)v4, v6, v7, &FileSetDescriptorExtent, &IcbRoot);
              if ( (signed int)v5 >= 0 )
              {
                v5 = (int *)UdfxCreateFcbFromFileEntry((int)v4, v6, v7, Irp, &IcbRoot, 0, 0, &v7->RootDirectoryFcb);
                if ( (signed int)v5 >= 0 )
                {
                  v7->RootDirectoryFcb->Flags |= 4u;
                  v4 = TargetDeviceObject;
                  v5 = 0;
                  TargetDeviceObject->MountedOrSelfDevice = VolumeDeviceObject;
                  VolumeDeviceObject = 0;
                }
              }
            }
          }
        }
      }
      if ( VolumeDeviceObject )
        UdfxDeleteVolumeDevice((int)v4, v6, VolumeDeviceObject);
    }
    else
    {
      v5 = (int *)-1073741670;
    }
    if ( Irp )
      IoFreeIrp((int)v4, v6, Irp);
  }
  RtlLeaveCriticalSectionAndRegion(v4, (_KEVENT *)&UdfxGlobalMutex);
  return v5;
}