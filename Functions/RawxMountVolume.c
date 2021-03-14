int *__userpurge RawxMountVolume@<eax>(int *a1@<edi>, _DEVICE_OBJECT *TargetDeviceObject)
{
  int v2; // edx
  int v3; // ecx
  void *v4; // ecx
  int *v5; // edi
  _DEVICE_OBJECT *v6; // eax
  unsigned int v7; // ecx
  char *v8; // eax
  _DISK_GEOMETRY DiskGeometry; // [esp+Ch] [ebp-1Ch]
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+24h] [ebp-4h]

  VolumeDeviceObject = 0;
  RawxAcquireGlobalMutexExclusive();
  IoSynchronousDeviceIoControlRequest(
    v3,
    v2,
    TargetDeviceObject->DeviceType != 2 ? 458752 : 147532,
    TargetDeviceObject,
    0,
    0,
    &DiskGeometry,
    0x18u,
    0,
    0);
  v5 = IoCreateDevice(a1, (int)TargetDeviceObject, &RawxDriverObject, 0x40u, 0, 8u, 0, &VolumeDeviceObject);
  if ( (signed int)v5 >= 0 )
  {
    VolumeDeviceObject->StackSize += TargetDeviceObject->StackSize;
    v6 = VolumeDeviceObject;
    v7 = TargetDeviceObject->AlignmentRequirement;
    if ( VolumeDeviceObject->AlignmentRequirement < v7 )
    {
      VolumeDeviceObject->AlignmentRequirement = v7;
      v6 = VolumeDeviceObject;
    }
    if ( TargetDeviceObject->Flags & 4 )
    {
      v6->Flags |= 4u;
      v6 = VolumeDeviceObject;
    }
    if ( TargetDeviceObject->Flags & 0x40 )
    {
      v6->Flags |= 0x40u;
      v6 = VolumeDeviceObject;
    }
    v6->SectorSize = TargetDeviceObject->SectorSize;
    ObfReferenceObject(TargetDeviceObject);
    v8 = (char *)VolumeDeviceObject->DeviceExtension;
    *(_DWORD *)v8 = TargetDeviceObject;
    ExInitializeReadWriteLock((_ERWLOCK *)(v8 + 12));
    VolumeDeviceObject->Flags &= 0xFFFFFFEF;
    TargetDeviceObject->MountedOrSelfDevice = VolumeDeviceObject;
    v5 = 0;
  }
  RawxReleaseGlobalMutex(v4);
  return v5;
}