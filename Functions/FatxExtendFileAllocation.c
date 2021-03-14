int *__fastcall FatxExtendFileAllocation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *FileFcb, unsigned int AllocationSize)
{
  int *v6; // eax
  int v7; // edx
  int v8; // ecx
  int *v9; // edi
  char v10; // cl
  unsigned int v11; // eax
  unsigned int v12; // ST18_4
  _FAT_CLUSTER_RUN *v13; // ecx
  _FAT_CLUSTER_RUN ClusterRuns[10]; // [esp+Ch] [ebp-58h]
  unsigned int NumberOfClusterRuns; // [esp+5Ch] [ebp-8h]
  unsigned int EndingCluster; // [esp+60h] [ebp-4h]

  if ( !AllocationSize )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0,
      "AllocationSize != 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x78Eu,
      0);
  if ( (VolumeExtension->BytesPerCluster - 1) & AllocationSize )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      AllocationSize,
      "FatxByteOffsetIntoCluster(VolumeExtension, AllocationSize) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x78Fu,
      0);
  if ( FileFcb->AllocationSize == -1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)FileFcb,
      "FileFcb->AllocationSize != MAXULONG",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x790u,
      0);
  if ( FileFcb->AllocationSize >= AllocationSize )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)FileFcb,
      "FileFcb->AllocationSize < AllocationSize",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x791u,
      0);
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x792u,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)FileFcb,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x793u,
      0);
  if ( FileFcb->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)FileFcb,
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x794u,
      0);
  if ( FileFcb->AllocationSize )
  {
    if ( !FileFcb->FirstCluster )
      RtlAssert(
        a2,
        a1,
        (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        (int)FileFcb,
        "FileFcb->FirstCluster != FAT_CLUSTER_NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x79Cu,
        0);
    if ( !FileFcb->EndingCluster )
      RtlAssert(
        a2,
        a1,
        (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        (int)FileFcb,
        "FileFcb->EndingCluster != FAT_CLUSTER_NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x79Du,
        0);
  }
  v6 = FatxAllocateClusters(
         a2,
         (int)ClusterRuns,
         (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
         VolumeExtension,
         Irp,
         FileFcb->EndingCluster,
         (AllocationSize - FileFcb->AllocationSize) >> VolumeExtension->ClusterShift,
         ClusterRuns,
         &NumberOfClusterRuns,
         &EndingCluster);
  v9 = v6;
  if ( (signed int)v6 < 0 )
  {
    if ( v6 != (int *)-1073741697 )
    {
      FileFcb->AllocationSize = -1;
      FileFcb->EndingCluster = 0;
    }
  }
  else
  {
    if ( !FileFcb->FirstCluster )
    {
      FileFcb->FirstCluster = ClusterRuns[0].PhysicalClusterNumber;
      v9 = (int *)FatxUpdateDirectoryEntry(v7, v8, v6, VolumeExtension, Irp, FileFcb);
      if ( (signed int)v9 >= 0 )
      {
LABEL_25:
        v11 = FileFcb->AllocationSize;
        v12 = NumberOfClusterRuns;
        FileFcb->AllocationSize = AllocationSize;
        FileFcb->EndingCluster = EndingCluster;
        v13 = ClusterRuns;
        LOBYTE(v13) = VolumeExtension->ClusterShift;
        FatxAppendClusterRunsToClusterCache(
          (int)v13,
          v7,
          FileFcb,
          v11 >> VolumeExtension->ClusterShift,
          ClusterRuns,
          v12);
        return v9;
      }
      FatxFreeClusters(v7, v10, v9, VolumeExtension, Irp, FileFcb->FirstCluster, 0);
      FileFcb->FirstCluster = 0;
    }
    if ( (signed int)v9 >= 0 )
      goto LABEL_25;
  }
  return v9;
}