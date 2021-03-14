int __userpurge GdfxProcessVolumeDescriptor@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *VolumeDeviceObject, _IRP *Irp)
{
  _FSCACHE_EXTENSION *v6; // ebx
  int result; // eax
  _DEVICE_OBJECT *v8; // edx
  signed int v9; // ecx
  int *v10; // edi
  _DEVICE_OBJECT *v11; // esi
  bool v12; // zf
  signed int v13; // ecx
  _DEVICE_OBJECT **v14; // esi
  bool v15; // zf
  unsigned int v16; // esi
  unsigned int v17; // ecx
  void **v18; // eax
  int v19; // esi

  v6 = (_FSCACHE_EXTENSION *)VolumeDeviceObject->DeviceExtension;
  if ( v6[1].PartitionLength.HighPart <= 0x20u )
    return -1073741489;
  result = FscMapBuffer(a1, a2, a3, a4, v6, Irp, 0x10000ui64, 0, (void **)&VolumeDeviceObject);
  if ( result >= 0 )
  {
    v8 = VolumeDeviceObject;
    v9 = 5;
    v10 = (int *)"MICROSOFT*XBOX*MEDIA";
    v11 = VolumeDeviceObject;
    v12 = 1;
    do
    {
      if ( !v9 )
        break;
      v12 = *(_DWORD *)&v11->Type == *v10;
      v11 = (_DEVICE_OBJECT *)((char *)v11 + 4);
      ++v10;
      --v9;
    }
    while ( v12 );
    Irp = (_IRP *)VolumeDeviceObject;
    if ( !v12 )
      goto LABEL_20;
    v13 = 5;
    v10 = (int *)"MICROSOFT*XBOX*MEDIA";
    v14 = &VolumeDeviceObject[28].MountedOrSelfDevice;
    v15 = 1;
    do
    {
      if ( !v13 )
        break;
      v15 = *v14 == (_DEVICE_OBJECT *)*v10;
      ++v14;
      ++v10;
      --v13;
    }
    while ( v15 );
    if ( v15 )
    {
      v16 = VolumeDeviceObject->Flags;
      v17 = v6[1].PartitionLength.HighPart;
      if ( v16 >= v17
        || (v18 = &VolumeDeviceObject->DeviceExtension,
            v10 = (int *)(((unsigned int)VolumeDeviceObject->DeviceExtension + 2047) >> 11),
            v17 - v16 < (unsigned int)v10) )
      {
        v19 = -1073741774;
      }
      else
      {
        *(_DWORD *)v6[1].PartitionLength.LowPart = v16;
        *(_DWORD *)(v6[1].PartitionLength.LowPart + 4) = *v18;
        v6[1].SectorSize = *(_DWORD *)&v8->DeviceType;
        v6[2].TargetDeviceObject = (_DEVICE_OBJECT *)v8->SectorSize;
        v8 = VolumeDeviceObject;
        v19 = 0;
      }
    }
    else
    {
LABEL_20:
      v19 = -1073741489;
    }
    FscUnmapBuffer(v10, v19, v8);
    result = v19;
  }
  return result;
}