int *__fastcall FatxExtendDirectoryAllocation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb)
{
  _FAT_FCB *v5; // edi
  int v7; // edx
  int v8; // ecx
  int *v9; // ebx
  int v10; // edx
  char v11; // cl
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // ST18_4
  _FAT_CLUSTER_RUN *v15; // ecx
  _FAT_CLUSTER_RUN ClusterRuns[10]; // [esp+Ch] [ebp-54h]
  unsigned int NumberOfClusterRuns; // [esp+5Ch] [ebp-4h]

  v5 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a2,
      a1,
      (int *)&DirectoryFcb->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x86Fu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)&v5->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x870u,
      0);
  if ( !v5->AllocationSize )
    RtlAssert(
      a2,
      a1,
      (int *)&v5->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "DirectoryFcb->AllocationSize != 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x878u,
      0);
  if ( v5->AllocationSize == -1 )
    RtlAssert(
      a2,
      a1,
      (int *)&v5->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "DirectoryFcb->AllocationSize != MAXULONG",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x879u,
      0);
  if ( !v5->EndingCluster )
    RtlAssert(
      a2,
      a1,
      (int *)&v5->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "DirectoryFcb->EndingCluster != FAT_CLUSTER_NULL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x87Au,
      0);
  if ( v5->AllocationSize >= 0x40000 )
    return (int *)-1073741078;
  v9 = FatxAllocateClusters(
         a2,
         a1,
         (int *)&v5->Flags,
         VolumeExtension,
         Irp,
         0,
         1u,
         ClusterRuns,
         &NumberOfClusterRuns,
         (unsigned int *)&DirectoryFcb);
  if ( (signed int)v9 >= 0 )
  {
    if ( NumberOfClusterRuns != 1 )
      RtlAssert(
        v7,
        v8,
        (int *)&v5->Flags,
        (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        "NumberOfClusterRuns == 1",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x890u,
        0);
    if ( DirectoryFcb != (_FAT_FCB *)ClusterRuns[0].PhysicalClusterNumber )
      RtlAssert(
        v7,
        v8,
        (int *)&v5->Flags,
        (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        "EndingCluster == ClusterRuns[0].PhysicalClusterNumber",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x891u,
        0);
    v9 = FatxInitializeDirectoryCluster(v8, v7, VolumeExtension, Irp, (unsigned int)DirectoryFcb);
    if ( (signed int)v9 < 0 )
    {
      FatxFreeClusters(v10, v11, (int *)&v5->Flags, VolumeExtension, Irp, (unsigned int)DirectoryFcb, 0);
    }
    else
    {
      v9 = (int *)FatxLinkClusterChains(v11, v10, VolumeExtension, Irp, v5->EndingCluster, (unsigned int)DirectoryFcb);
      if ( (signed int)v9 >= 0 )
      {
        v13 = v5->AllocationSize;
        v14 = NumberOfClusterRuns;
        v5->AllocationSize = v13 + VolumeExtension->BytesPerCluster;
        v5->EndingCluster = (unsigned int)DirectoryFcb;
        v15 = ClusterRuns;
        LOBYTE(v15) = VolumeExtension->ClusterShift;
        FatxAppendClusterRunsToClusterCache((int)v15, v12, v5, v13 >> VolumeExtension->ClusterShift, ClusterRuns, v14);
      }
    }
  }
  return v9;
}