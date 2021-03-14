unsigned int __fastcall FatxLinkClusterChains(char a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, unsigned int LinkClusterNumber, unsigned int StartingClusterNumber)
{
  _FAT_VOLUME_EXTENSION *v6; // esi
  unsigned int v7; // edi
  char v8; // cl
  unsigned int v9; // edi
  unsigned __int64 v10; // kr00_8
  unsigned __int64 v11; // ST08_8
  int v12; // edx
  char v13; // cl
  bool v14; // zf
  _FAT_VOLUME_EXTENSION *v15; // ecx
  _DEVICE_OBJECT *v16; // eax

  v6 = VolumeExtension;
  v7 = LinkClusterNumber;
  if ( LinkClusterNumber - 1 >= VolumeExtension->NumberOfClusters )
    RtlAssert(
      a2,
      a1,
      (int *)LinkClusterNumber,
      (int)VolumeExtension,
      "FatxIsValidCluster(VolumeExtension, LinkClusterNumber)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x6Du,
      0);
  if ( StartingClusterNumber - 1 >= v6->NumberOfClusters )
    RtlAssert(
      a2,
      a1,
      (int *)v7,
      (int)v6,
      "FatxIsValidCluster(VolumeExtension, StartingClusterNumber)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x6Eu,
      0);
  if ( v6->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)v7,
      (int)v6,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x6Fu,
      0);
  v8 = v6->FatEntryShift;
  v9 = v7 << v8;
  v10 = v6->FatByteOffset + v9;
  HIDWORD(v11) = HIDWORD(v6->FatByteOffset) + __CFADD__(v6->FatByteOffset, v9);
  LODWORD(v11) = v10;
  LinkClusterNumber = FscMapBuffer(
                        a2,
                        v8,
                        (int *)v10,
                        (int)v6,
                        &v6->CacheExtension,
                        Irp,
                        v11,
                        1,
                        (void **)&VolumeExtension);
  if ( (LinkClusterNumber & 0x80000000) != 0 )
    goto LABEL_23;
  v14 = (v6->Flags & 2) == 0;
  v15 = VolumeExtension;
  LinkClusterNumber = (unsigned int)VolumeExtension;
  if ( v14 )
  {
    v16 = VolumeExtension->CacheExtension.TargetDeviceObject;
  }
  else
  {
    LOWORD(v16) = VolumeExtension->CacheExtension.TargetDeviceObject;
    if ( LOWORD(VolumeExtension->CacheExtension.TargetDeviceObject) >= 0xFFF0u )
      v16 = (_DEVICE_OBJECT *)(signed __int16)v16;
    else
      v16 = (_DEVICE_OBJECT *)(unsigned __int16)v16;
  }
  if ( v16 != (_DEVICE_OBJECT *)-1 )
  {
    RtlAssert(
      v12,
      (unsigned __int8)VolumeExtension,
      (int *)v10,
      (int)v6,
      "FatxReadFatEntry(VolumeExtension, FatEntry) == FAT_CLUSTER_LAST",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x84u,
      0);
    v15 = (_FAT_VOLUME_EXTENSION *)LinkClusterNumber;
  }
  if ( v6->Flags & 2 )
    LOWORD(v15->CacheExtension.TargetDeviceObject) = StartingClusterNumber;
  else
    v15->CacheExtension.TargetDeviceObject = (_DEVICE_OBJECT *)StartingClusterNumber;
  LOBYTE(v15) = v6->FatEntryShift;
  LinkClusterNumber = FscWriteBuffer(
                        v12,
                        (int)v15,
                        (int)v6,
                        &v6->CacheExtension,
                        Irp,
                        v10,
                        1 << v6->FatEntryShift,
                        VolumeExtension);
  if ( (LinkClusterNumber & 0x80000000) != 0 )
LABEL_23:
    FatxFreeClusters(v12, v13, (int *)v10, v6, Irp, StartingClusterNumber, 0);
  return LinkClusterNumber;
}