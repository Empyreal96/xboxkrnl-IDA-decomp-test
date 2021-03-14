int __userpurge FatxIsDirectoryEmpty@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb)
{
  _FAT_FCB *v6; // ebx
  int result; // eax
  _DIRENT DirectoryEntry; // [esp+8h] [ebp-48h]
  _STRING TemplateFileName; // [esp+48h] [ebp-8h]

  v6 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x8DFu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x8E0u,
      0);
  TemplateFileName.Buffer = 0;
  result = FatxFindNextDirectoryEntry(
             a1,
             a2,
             (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
             VolumeExtension,
             Irp,
             v6,
             0,
             &TemplateFileName,
             &DirectoryEntry,
             (unsigned int *)&DirectoryFcb);
  if ( result >= 0 )
    return -1073741567;
  if ( result == -1073741807 )
    result = 0;
  return result;
}