int *__userpurge FatxCreateVolumeDevice@<eax>(_DEVICE_OBJECT *a1@<ecx>, int *a2@<edi>, int a3@<esi>, _DEVICE_OBJECT *TargetDeviceObject, _DISK_GEOMETRY *DiskGeometry, _PARTITION_INFORMATION *PartitionInformation, _DEVICE_OBJECT **ReturnedVolumeDeviceObject)
{
  int *result; // eax
  _DEVICE_OBJECT *v8; // eax
  unsigned int v9; // ecx
  char *v10; // esi
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+0h] [ebp-4h]

  VolumeDeviceObject = a1;
  result = IoCreateDevice(a2, a3, &FatxDriverObject, 0xACu, 0, 8u, 0, &VolumeDeviceObject);
  if ( (signed int)result >= 0 )
  {
    VolumeDeviceObject->StackSize += TargetDeviceObject->StackSize;
    v8 = VolumeDeviceObject;
    v9 = TargetDeviceObject->AlignmentRequirement;
    if ( VolumeDeviceObject->AlignmentRequirement < v9 )
    {
      VolumeDeviceObject->AlignmentRequirement = v9;
      v8 = VolumeDeviceObject;
    }
    if ( TargetDeviceObject->Flags & 0x40 )
    {
      v8->Flags |= 0x40u;
      v8 = VolumeDeviceObject;
    }
    v8->SectorSize = LOWORD(DiskGeometry->BytesPerSector);
    ObfReferenceObject(TargetDeviceObject);
    v10 = (char *)VolumeDeviceObject->DeviceExtension;
    *(_DWORD *)v10 = TargetDeviceObject;
    *(_QWORD *)(v10 + 4) = PartitionInformation->PartitionLength.QuadPart;
    *((_DWORD *)v10 + 3) = DiskGeometry->BytesPerSector;
    v10[32] = RtlFindFirstSetRightMember((void *)DiskGeometry->BytesPerSector);
    ExInitializeReadWriteLock((_ERWLOCK *)(v10 + 60));
    RtlInitializeCriticalSection((_RTL_CRITICAL_SECTION *)v10 + 4);
    v10[140] = 1;
    *((_DWORD *)v10 + 36) = 1;
    VolumeDeviceObject->Flags &= 0xFFFFFFEF;
    *ReturnedVolumeDeviceObject = VolumeDeviceObject;
    result = 0;
  }
  return result;
}