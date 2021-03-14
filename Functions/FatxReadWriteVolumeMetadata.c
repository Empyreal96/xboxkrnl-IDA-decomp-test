int __userpurge FatxReadWriteVolumeMetadata@<eax>(int a1@<edx>, int *a2@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v4; // esi
  int v5; // edx
  int v6; // esi
  int *v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  char *v13; // esi
  char *v14; // edi
  char *v15; // edi
  char *v16; // esi
  int v17; // ecx
  char *v18; // esi
  char *v19; // edi
  char *v20; // edi
  char *v21; // esi
  int v22; // ecx
  bool WritingMetadata; // [esp+4h] [ebp-8h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+8h] [ebp-4h]

  v4 = Irp->Tail.Overlay.CurrentStackLocation;
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FatxAcquireVolumeMutexExclusive(a1, (int)Irp, a2, (int)v4, VolumeExtension);
  if ( v4->Parameters.Read.ByteOffset.LowPart >= 0xC )
  {
    v7 = (int *)v4->Parameters.Create.Options;
    if ( (unsigned int)*v7 >= 0x1000 || (v8 = v7[1], v8 > 0x1000) || (v9 = *v7 + v8, v9 > 0x1000) )
    {
      v6 = -1073741811;
    }
    else
    {
      WritingMetadata = v4->Parameters.Read.ByteOffset.HighPart == 622880;
      v6 = FscMapBuffer(
             v5,
             v9,
             v7,
             (int)v4,
             &VolumeExtension->CacheExtension,
             Irp,
             0i64,
             WritingMetadata,
             (void **)&DeviceObject);
      if ( v6 >= 0 )
      {
        v11 = v7[1];
        v12 = v11 >> 2;
        if ( WritingMetadata )
        {
          v13 = (char *)v7[2];
          v14 = (char *)DeviceObject + *v7;
          qmemcpy(v14, v13, 4 * v12);
          v16 = &v13[4 * v12];
          v15 = &v14[4 * v12];
          v17 = v11 & 3;
          qmemcpy(v15, v16, v17);
          v6 = FscWriteBuffer(
                 v10,
                 0,
                 (int)&v16[v17],
                 &VolumeExtension->CacheExtension,
                 Irp,
                 0i64,
                 0x1000u,
                 DeviceObject);
        }
        else
        {
          v18 = (char *)DeviceObject + *v7;
          v19 = (char *)v7[2];
          qmemcpy(v19, v18, 4 * v12);
          v21 = &v18[4 * v12];
          v20 = &v19[4 * v12];
          v22 = v11 & 3;
          qmemcpy(v20, v21, v22);
          FscUnmapBuffer((int *)&v20[v22], (int)&v21[v22], DeviceObject);
          v6 = 0;
        }
      }
    }
  }
  else
  {
    v6 = -1073741811;
  }
  FatxReleaseVolumeMutex(VolumeExtension);
  return v6;
}