int __fastcall FatxMarkDirectoryEntryDeleted(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *Fcb)
{
  _FAT_FCB *v5; // esi
  _FAT_VOLUME_EXTENSION *v6; // ebx
  _FAT_FCB *v7; // eax
  int result; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  unsigned __int64 PhysicalByteOffset; // [esp+Ch] [ebp-8h]

  v5 = Fcb;
  if ( Fcb->Flags & 5 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME | FAT_FCB_ROOT_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x1D9u,
      0);
  v6 = VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)v5,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x1DAu,
      0);
  v7 = v5->ParentFcb;
  if ( !v7 )
    return -1073741566;
  result = FatxFileByteOffsetToPhysicalByteOffset(
             a2,
             (int)&PhysicalByteOffset,
             (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
             v6,
             Irp,
             v7,
             v5->DirectoryByteOffset,
             0,
             &PhysicalByteOffset,
             (unsigned int *)&VolumeExtension);
  if ( result >= 0 )
  {
    result = FscMapBuffer(
               v9,
               v10,
               (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
               (int)v5,
               &v6->CacheExtension,
               Irp,
               PhysicalByteOffset,
               1,
               (void **)&Fcb);
    if ( result >= 0 )
    {
      Fcb->Flags = -27;
      result = FscWriteBuffer(v11, v12, (int)v5, &v6->CacheExtension, Irp, PhysicalByteOffset, 0x40u, Fcb);
    }
  }
  return result;
}