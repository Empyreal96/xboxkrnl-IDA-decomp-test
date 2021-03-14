int *__userpurge FatxSetAllocationSize@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *FileFcb, unsigned int AllocationSize, char OverwritingFile, char DisableTruncation)
{
  _FAT_FCB *v9; // esi
  int v10; // ecx
  int *v11; // edi
  int *result; // eax
  unsigned int v13; // eax

  v9 = FileFcb;
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x80Du,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      (int)v9,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x80Eu,
      0);
  if ( v9->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      (int)v9,
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x80Fu,
      0);
  v10 = AllocationSize;
  v11 = (int *)(~(VolumeExtension->BytesPerCluster - 1) & (VolumeExtension->BytesPerCluster + AllocationSize - 1));
  if ( !v11 )
    return (int *)FatxDeleteFileAllocation(AllocationSize, a1, VolumeExtension, Irp, v9);
  if ( v9->AllocationSize != -1 )
    goto LABEL_25;
  if ( v9->EndingCluster )
    RtlAssert(
      a1,
      AllocationSize,
      v11,
      (int)v9,
      "FileFcb->EndingCluster == FAT_CLUSTER_NULL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x825u,
      0);
  result = (int *)FatxFileByteOffsetToCluster(
                    a1,
                    v10,
                    (int)v9,
                    VolumeExtension,
                    Irp,
                    v9,
                    0xFFFFFFFF,
                    (unsigned int *)&FileFcb,
                    0);
  if ( result == (int *)-1073741807 )
    goto LABEL_25;
  if ( result == (int *)-1073741566 )
  {
    if ( !OverwritingFile )
      return result;
    result = (int *)FatxDeleteFileAllocation(v10, a1, VolumeExtension, Irp, v9);
  }
  if ( (signed int)result >= 0 )
  {
LABEL_25:
    v13 = v9->AllocationSize;
    if ( v13 >= (unsigned int)v11 )
    {
      if ( DisableTruncation || v13 <= (unsigned int)v11 )
        result = 0;
      else
        result = (int *)FatxTruncateFileAllocation(a1, v10, (int)v9, VolumeExtension, Irp, v9, (unsigned int)v11);
    }
    else
    {
      result = FatxExtendFileAllocation(v10, a1, VolumeExtension, Irp, v9, (unsigned int)v11);
    }
  }
  return result;
}