int *__fastcall FatxInitializeDirectoryCluster(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, unsigned int ClusterNumber)
{
  int *v5; // edi
  unsigned __int64 v6; // rax
  int v7; // ecx
  unsigned int v8; // ebx
  int *v9; // edi

  v5 = (int *)(ClusterNumber - 1);
  if ( ClusterNumber - 1 >= VolumeExtension->NumberOfClusters )
    RtlAssert(
      a2,
      a1,
      v5,
      (int)VolumeExtension,
      "FatxIsValidCluster(VolumeExtension, ClusterNumber)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x2Fu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      v5,
      (int)VolumeExtension,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x30u,
      0);
  v7 = (unsigned __int8)VolumeExtension->ClusterShift;
  v6 = (unsigned __int64)(unsigned int)v5 << v7;
  v8 = (VolumeExtension->FileAreaByteOffset + v6) >> 32;
  v9 = (int *)(LODWORD(VolumeExtension->FileAreaByteOffset) + v6);
  if ( (unsigned __int16)v9 & 0xFFF )
    RtlAssert(
      SHIDWORD(v6),
      v7,
      v9,
      (int)VolumeExtension,
      "BYTE_OFFSET(PhysicalByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x3Au,
      0);
  return FscWriteFFs(
           SHIDWORD(v6),
           v7,
           (int)VolumeExtension,
           &VolumeExtension->CacheExtension,
           Irp,
           __PAIR__(v8, (unsigned int)v9),
           VolumeExtension->BytesPerCluster);
}