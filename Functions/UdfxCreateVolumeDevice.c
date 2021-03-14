int *__userpurge UdfxCreateVolumeDevice@<eax>(_DEVICE_OBJECT *a1@<ecx>, int *a2@<edi>, int a3@<esi>, _DEVICE_OBJECT *TargetDeviceObject, _DISK_GEOMETRY *DiskGeometry, _DEVICE_OBJECT **ReturnedVolumeDeviceObject)
{
  int *result; // eax
  _DEVICE_OBJECT *v7; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // esi
  int v10; // edx
  int v11; // ecx
  int *v12; // eax
  int v13; // ecx
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+0h] [ebp-4h]

  VolumeDeviceObject = a1;
  result = IoCreateDevice(a2, a3, &UdfxDriverObject, 0x2Cu, 0, 3u, 0, &VolumeDeviceObject);
  if ( (signed int)result >= 0 )
  {
    VolumeDeviceObject->StackSize += TargetDeviceObject->StackSize;
    v7 = VolumeDeviceObject;
    v8 = TargetDeviceObject->AlignmentRequirement;
    if ( VolumeDeviceObject->AlignmentRequirement < v8 )
    {
      VolumeDeviceObject->AlignmentRequirement = v8;
      v7 = VolumeDeviceObject;
    }
    if ( TargetDeviceObject->Flags & 0x40 )
    {
      v7->Flags |= 0x40u;
      v7 = VolumeDeviceObject;
    }
    v7->SectorSize = 2048;
    ObfReferenceObject(TargetDeviceObject);
    v9 = VolumeDeviceObject->DeviceExtension;
    *v9 = TargetDeviceObject;
    v9[3] = 2048;
    v9[6] = DiskGeometry->Cylinders.LowPart;
    v12 = ExAllocatePoolWithTag(v10, v11, (int)v9, 0x34u, 0x63567855u);
    if ( v12 )
    {
      v9[5] = 0;
      v9[4] = v12;
      memset(v12, 0, 0x34u);
      v12[10] = (int)(v12 + 9);
      v12[9] = (int)(v12 + 9);
      *(_BYTE *)v12 = 1;
      v12[7] = 1;
      VolumeDeviceObject->Flags &= 0xFFFFFFEF;
      *ReturnedVolumeDeviceObject = VolumeDeviceObject;
      result = 0;
    }
    else
    {
      UdfxDeleteVolumeDevice(v13, 0, VolumeDeviceObject);
      result = (int *)-1073741670;
    }
  }
  return result;
}