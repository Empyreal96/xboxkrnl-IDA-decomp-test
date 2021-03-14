int __fastcall FatxDeleteFileAllocation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *FileFcb)
{
  _FAT_FCB *v5; // esi
  unsigned int v6; // ebx
  int result; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  char v11; // cl
  _FAT_FCB *FileFcba; // [esp+1Ch] [ebp+10h]

  v5 = FileFcb;
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a2,
      a1,
      0,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x68Du,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      0,
      (int)FileFcb,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x68Eu,
      0);
  if ( FileFcb->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      0,
      (int)FileFcb,
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x68Fu,
      0);
  FileFcba = (_FAT_FCB *)FileFcb->FirstCluster;
  if ( v5->FirstCluster || v5->FileSize )
  {
    v6 = v5->FileSize;
    v5->FirstCluster = 0;
    v5->FileSize = 0;
    result = FatxUpdateDirectoryEntry(a2, a1, 0, VolumeExtension, Irp, v5);
    if ( result < 0 )
    {
      v5->FirstCluster = (unsigned int)FileFcba;
      v5->FileSize = v6;
      return result;
    }
    FatxInvalidateClusterCache(v9, v8, v5, 0);
    FatxFreeClusters(v10, v11, 0, VolumeExtension, Irp, (unsigned int)FileFcba, 0);
    v5->AllocationSize = 0;
    v5->EndingCluster = 0;
  }
  else
  {
    if ( v5->AllocationSize )
      RtlAssert(
        a2,
        a1,
        0,
        (int)v5,
        "FileFcb->AllocationSize == 0",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x698u,
        0);
    if ( v5->EndingCluster )
      RtlAssert(
        a2,
        a1,
        0,
        (int)v5,
        "FileFcb->EndingCluster == FAT_CLUSTER_NULL",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x699u,
        0);
  }
  return 0;
}