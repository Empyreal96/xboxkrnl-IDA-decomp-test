int __stdcall GdfxMountVolume(_DEVICE_OBJECT *TargetDeviceObject)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  _DEVICE_OBJECT *v6; // ecx
  int v7; // ebx
  int v8; // edx
  int *v9; // eax
  _DEVICE_OBJECT *v10; // edi
  _DISK_GEOMETRY DiskGeometry; // [esp+8h] [ebp-20h]
  _IRP *Irp; // [esp+20h] [ebp-8h]
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+24h] [ebp-4h]

  VolumeDeviceObject = 0;
  RtlEnterCriticalSectionAndRegion(&GdfxGlobalMutex);
  IoSynchronousDeviceIoControlRequest(v2, v1, 0x24080u, TargetDeviceObject, 0, 0, 0, 0, 0, 0);
  v7 = IoSynchronousDeviceIoControlRequest(v4, v3, 0x2404Cu, TargetDeviceObject, 0, 0, &DiskGeometry, 0x18u, 0, 0);
  if ( v7 >= 0 )
  {
    if ( DiskGeometry.Cylinders.HighPart )
      RtlAssert(
        v5,
        (int)v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0,
        "DiskGeometry.Cylinders.HighPart == 0",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0x194u,
        0);
    if ( DiskGeometry.TracksPerCylinder != 1 )
      RtlAssert(
        v5,
        (int)v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0,
        "DiskGeometry.TracksPerCylinder == 1",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0x195u,
        0);
    if ( DiskGeometry.SectorsPerTrack != 1 )
      RtlAssert(
        v5,
        (int)v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0,
        "DiskGeometry.SectorsPerTrack == 1",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0x196u,
        0);
    if ( DiskGeometry.BytesPerSector != 2048 )
      RtlAssert(
        v5,
        (int)v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0,
        "DiskGeometry.BytesPerSector == GDF_CD_SECTOR_SIZE",
        "d:\\xbox-apr03\\private\\ntos\\gdfx\\mountvol.c",
        0x197u,
        0);
    Irp = IoAllocateIrp((int)v6, v5, TargetDeviceObject->StackSize);
    if ( Irp )
    {
      v9 = GdfxCreateVolumeDevice(
             v6,
             (int *)&TargetDeviceObject->Type,
             0,
             TargetDeviceObject,
             &DiskGeometry,
             &VolumeDeviceObject);
      v10 = VolumeDeviceObject;
      v7 = (int)v9;
      if ( (signed int)v9 >= 0 )
      {
        v7 = GdfxProcessVolumeDescriptor(v8, (int)v6, (int *)&VolumeDeviceObject->Type, 0, VolumeDeviceObject, Irp);
        if ( v7 >= 0 )
        {
          TargetDeviceObject->MountedOrSelfDevice = v10;
          v10 = 0;
          v7 = 0;
        }
      }
      if ( v10 )
        GdfxDeleteVolumeDevice((int)v6, v8, v10);
    }
    else
    {
      v7 = -1073741670;
    }
    if ( Irp )
      IoFreeIrp((int)v6, v8, Irp);
  }
  RtlLeaveCriticalSectionAndRegion(v6, (_KEVENT *)&GdfxGlobalMutex);
  return v7;
}