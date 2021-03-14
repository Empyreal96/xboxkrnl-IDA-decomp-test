int __userpurge FatxTruncateFileAllocation@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *FileFcb, unsigned int AllocationSize)
{
  unsigned int v7; // edi
  int result; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  int v13; // edx
  int v14; // ecx

  v7 = AllocationSize;
  if ( !AllocationSize )
    RtlAssert(
      a1,
      a2,
      (int *)AllocationSize,
      a3,
      "AllocationSize != 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6F8u,
      (char *)AllocationSize);
  if ( (VolumeExtension->BytesPerCluster - 1) & v7 )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      a3,
      "FatxByteOffsetIntoCluster(VolumeExtension, AllocationSize) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6F9u,
      0);
  if ( FileFcb->AllocationSize == -1 )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      (int)FileFcb,
      "FileFcb->AllocationSize != MAXULONG",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6FAu,
      0);
  if ( FileFcb->AllocationSize <= v7 )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      (int)FileFcb,
      "FileFcb->AllocationSize > AllocationSize",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6FBu,
      0);
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6FCu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      (int)FileFcb,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6FDu,
      0);
  if ( FileFcb->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)v7,
      (int)FileFcb,
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x6FEu,
      0);
  if ( FileFcb->AllocationSize )
  {
    if ( !FileFcb->FirstCluster )
      RtlAssert(
        a1,
        a2,
        (int *)v7,
        (int)FileFcb,
        "FileFcb->FirstCluster != FAT_CLUSTER_NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x706u,
        0);
    if ( !FileFcb->EndingCluster )
      RtlAssert(
        a1,
        a2,
        (int *)v7,
        (int)FileFcb,
        "FileFcb->EndingCluster != FAT_CLUSTER_NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x707u,
        0);
  }
  result = FatxFileByteOffsetToCluster(a1, a2, (int)FileFcb, VolumeExtension, Irp, FileFcb, v7 - 1, &AllocationSize, 0);
  if ( result == -1073741807 )
    result = -1073741566;
  if ( result >= 0 )
  {
    v11 = FileFcb->FileSize;
    if ( v11 <= v7
      || (FileFcb->FileSize = v7,
          result = FatxUpdateDirectoryEntry(v9, v10, (int *)v7, VolumeExtension, Irp, FileFcb),
          result >= 0) )
    {
      v12 = AllocationSize;
      if ( FatxFreeClusters(v9, v10, (int *)v7, VolumeExtension, Irp, AllocationSize, 1) )
      {
        FileFcb->AllocationSize = v7;
        FileFcb->EndingCluster = v12;
        LOBYTE(v14) = VolumeExtension->ClusterShift;
        FatxInvalidateClusterCache(v14, v13, FileFcb, v7 >> VolumeExtension->ClusterShift);
        result = 0;
      }
      else
      {
        result = -1073741823;
      }
    }
    else
    {
      FileFcb->FileSize = v11;
    }
  }
  return result;
}