int *__userpurge GdfxCreateVolumeDevice@<eax>(_DEVICE_OBJECT *a1@<ecx>, int *a2@<edi>, int a3@<esi>, _DEVICE_OBJECT *TargetDeviceObject, _DISK_GEOMETRY *DiskGeometry, _DEVICE_OBJECT **ReturnedVolumeDeviceObject)
{
  int *result; // eax
  _DEVICE_OBJECT *v7; // eax
  unsigned int v8; // ecx
  _DWORD *v9; // esi
  int v10; // ecx
  int v11; // edx
  int *v12; // eax
  int v13; // ecx
  int v14; // edx
  int *v15; // eax
  _DEVICE_OBJECT *VolumeDeviceObject; // [esp+0h] [ebp-4h]

  VolumeDeviceObject = a1;
  result = IoCreateDevice(a2, a3, &GdfxDriverObject, 0x2Cu, 0, 3u, 0, &VolumeDeviceObject);
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
    v10 = (unsigned __int64)DiskGeometry->Cylinders.LowPart >> 21;
    v9[1] = DiskGeometry->Cylinders.LowPart << 11;
    v9[2] = v10;
    v12 = ExAllocatePoolWithTag(v11, v10, (int)v9, 0x24u, 0x63567847u);
    v14 = (int)v12;
    if ( !v12 )
      goto LABEL_12;
    v9[4] = v12;
    memset(v12, 0, 0x24u);
    *((_BYTE *)v12 + 32) = 1;
    v12[2] = 1;
    v12[5] = (int)(v12 + 4);
    v12[4] = (int)(v12 + 4);
    v15 = ExAllocatePoolWithTag((int)v12, 0, (int)v9, 0x24u, 0x63527847u);
    v14 = (int)v15;
    if ( v15 )
    {
      v9[5] = v15;
      memset(v15, 0, 0x24u);
      v15[5] = (int)(v15 + 4);
      v15[4] = (int)(v15 + 4);
      v15[7] = (int)(v15 + 6);
      v15[6] = (int)(v15 + 6);
      *((_BYTE *)v15 + 32) = 6;
      v15[2] = 1;
      VolumeDeviceObject->Flags &= 0xFFFFFFEF;
      *ReturnedVolumeDeviceObject = VolumeDeviceObject;
      result = 0;
    }
    else
    {
LABEL_12:
      GdfxDeleteVolumeDevice(v13, v14, VolumeDeviceObject);
      result = (int *)-1073741670;
    }
  }
  return result;
}