int __userpurge FatxDeleteFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb, unsigned int DirectoryByteOffset)
{
  _FAT_FCB *v7; // ebx
  int *v8; // edi
  _FAT_FCB *v9; // ST08_4
  _IRP *v10; // ebx
  int result; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  unsigned int v16; // esi
  int v17; // edx
  char v18; // cl
  unsigned __int64 PhysicalByteOffset; // [esp+Ch] [ebp-8h]

  v7 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x91Eu,
      0);
  v8 = (int *)VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x91Fu,
      0);
  v9 = v7;
  v10 = Irp;
  result = FatxFileByteOffsetToPhysicalByteOffset(
             a1,
             a2,
             v8,
             (_FAT_VOLUME_EXTENSION *)v8,
             Irp,
             v9,
             DirectoryByteOffset,
             0,
             &PhysicalByteOffset,
             (unsigned int *)&VolumeExtension);
  if ( result >= 0 )
  {
    result = FscMapBuffer(
               v12,
               v13,
               v8,
               (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
               (_FSCACHE_EXTENSION *)v8,
               v10,
               PhysicalByteOffset,
               1,
               (void **)&DirectoryFcb);
    if ( result >= 0 )
    {
      v16 = DirectoryFcb->DirectoryByteOffset;
      DirectoryFcb->Flags = -27;
      result = FscWriteBuffer(v14, v15, v16, (_FSCACHE_EXTENSION *)v8, v10, PhysicalByteOffset, 0x40u, DirectoryFcb);
      if ( result >= 0 )
      {
        FatxFreeClusters(v17, v18, v8, (_FAT_VOLUME_EXTENSION *)v8, v10, v16, 0);
        result = 0;
      }
    }
  }
  return result;
}