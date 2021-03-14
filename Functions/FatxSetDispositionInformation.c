int __fastcall FatxSetDispositionInformation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FILE_OBJECT *FileObject, _FILE_DISPOSITION_INFORMATION *DispositionInformation)
{
  _FAT_FCB *v6; // esi
  int result; // eax

  v6 = (_FAT_FCB *)FileObject->FsContext;
  if ( v6->Flags & 1 )
    RtlAssert(
      a2,
      a1,
      (int *)&FileObject->Type,
      (int)v6,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x34Cu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)&FileObject->Type,
      (int)v6,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x34Du,
      0);
  if ( !DispositionInformation->DeleteFile )
  {
    v6->Flags &= 0xEFu;
    *((_BYTE *)FileObject + 2) &= 0xFEu;
    return 0;
  }
  if ( v6->FileAttributes & 1 )
    return -1073741535;
  if ( !(v6->Flags & 2)
    || (result = FatxIsDirectoryEmpty(a2, a1, (int *)&FileObject->Type, VolumeExtension, Irp, v6)) == 0
    || result == -1073741566 )
  {
    v6->Flags |= 0x10u;
    *((_BYTE *)FileObject + 2) |= 1u;
    return 0;
  }
  return result;
}