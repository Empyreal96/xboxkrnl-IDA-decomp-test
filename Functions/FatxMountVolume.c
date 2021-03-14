int *__stdcall FatxMountVolume(_DEVICE_OBJECT *TargetDeviceObject)
{
  int v1; // edx
  int v2; // ecx
  int v3; // edx
  _DEVICE_OBJECT *v4; // ecx
  int *v5; // edi
  int v6; // edx
  int v7; // edx
  int *v8; // eax
  _DEVICE_OBJECT *v9; // esi
  _PARTITION_INFORMATION PartitionInformation; // [esp+Ch] [ebp-40h]
  _DISK_GEOMETRY DiskGeometry; // [esp+2Ch] [ebp-20h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+44h] [ebp-8h]
  _IRP *Irp; // [esp+48h] [ebp-4h]

  VolumeExtension = 0;
  FatxAcquireGlobalMutexExclusive();
  v5 = (int *)IoSynchronousDeviceIoControlRequest(
                v2,
                v1,
                0x70000u,
                TargetDeviceObject,
                0,
                0,
                &DiskGeometry,
                0x18u,
                0,
                0);
  if ( (signed int)v5 >= 0 )
  {
    v5 = (int *)IoSynchronousDeviceIoControlRequest(
                  (int)v4,
                  v3,
                  0x74004u,
                  TargetDeviceObject,
                  0,
                  0,
                  &PartitionInformation,
                  0x20u,
                  0,
                  0);
    if ( (signed int)v5 >= 0 )
    {
      Irp = IoAllocateIrp((int)v4, v6, TargetDeviceObject->StackSize);
      if ( Irp )
      {
        v8 = FatxCreateVolumeDevice(
               v4,
               v5,
               (int)TargetDeviceObject,
               TargetDeviceObject,
               &DiskGeometry,
               &PartitionInformation,
               (_DEVICE_OBJECT **)&VolumeExtension);
        v9 = (_DEVICE_OBJECT *)VolumeExtension;
        v5 = v8;
        if ( (signed int)v8 >= 0 )
        {
          VolumeExtension = (_FAT_VOLUME_EXTENSION *)VolumeExtension->NumberOfClusters;
          v5 = (int *)FatxProcessBootSector(v7, v8, v9, Irp, &PartitionInformation.PartitionLength);
          if ( (signed int)v5 >= 0 )
          {
            v5 = (int *)FatxInitializeAllocationSupport(v7, (int)v4, (int)v9, VolumeExtension, Irp);
            if ( (signed int)v5 >= 0 )
            {
              TargetDeviceObject->MountedOrSelfDevice = v9;
              v9 = 0;
              v5 = 0;
            }
          }
        }
        if ( v9 )
          FatxDeleteVolumeDevice((int)v4, v7, v9);
      }
      else
      {
        v5 = (int *)-1073741670;
      }
      if ( Irp )
        IoFreeIrp((int)v4, v7, Irp);
    }
  }
  FatxReleaseGlobalMutex(v4);
  return v5;
}