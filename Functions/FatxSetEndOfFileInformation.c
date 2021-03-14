int *__fastcall FatxSetEndOfFileInformation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FILE_OBJECT *FileObject, _FILE_END_OF_FILE_INFORMATION *EndOfFileInformation)
{
  _FAT_FCB *v6; // esi
  int *result; // eax
  int *v8; // edi
  unsigned int v9; // ebx

  v6 = (_FAT_FCB *)FileObject->FsContext;
  if ( v6->Flags & 3 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      (int)v6,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x3A2u,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      (int)v6,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x3A3u,
      0);
  if ( v6->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      (int)v6,
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x3A4u,
      0);
  if ( EndOfFileInformation->EndOfFile.HighPart )
    return (int *)-1073741697;
  v8 = (int *)EndOfFileInformation->EndOfFile.LowPart;
  v9 = v6->FileSize;
  if ( EndOfFileInformation->EndOfFile.LowPart == v9 )
    return 0;
  if ( (unsigned int)v8 > v9 )
  {
    result = FatxSetAllocationSize(a2, a1, v8, VolumeExtension, Irp, v6, (unsigned int)v8, 0, 1);
    if ( (signed int)result < 0 )
      return result;
    if ( v6->FileSize != v9 )
      RtlAssert(
        a2,
        a1,
        v8,
        (int)v6,
        "FileFcb->FileSize == OriginalFileSize",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
        0x3CAu,
        0);
  }
  v6->FileSize = (unsigned int)v8;
  result = (int *)FatxUpdateDirectoryEntry(a2, a1, v8, VolumeExtension, Irp, v6);
  if ( (signed int)result < 0 )
    v6->FileSize = v9;
  return result;
}