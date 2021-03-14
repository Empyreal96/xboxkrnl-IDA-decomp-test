int __fastcall FatxOpenTargetDirectory(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb, unsigned int FileExists, char NoReferenceCount)
{
  _IO_STACK_LOCATION *v7; // eax
  unsigned int v8; // ebx
  _FILE_OBJECT *v9; // esi
  int result; // eax
  unsigned __int16 ShareAccess; // [esp+Ch] [ebp-4h]

  v7 = Irp->Tail.Overlay.CurrentStackLocation;
  v8 = v7->Parameters.Create.DesiredAccess;
  v9 = v7->FileObject;
  ShareAccess = v7->Parameters.Create.ShareAccess;
  if ( !DirectoryFcb )
    return -1073741566;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a2,
      v7->Parameters.Create.ShareAccess,
      (int *)&DirectoryFcb->Flags,
      (int)v9,
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x1EAu,
      0);
  if ( DirectoryFcb->ShareAccess.OpenCount )
  {
    result = IoCheckShareAccess(
               (int *)&DirectoryFcb->Flags,
               (int)v9,
               v8,
               ShareAccess,
               v9,
               &DirectoryFcb->ShareAccess,
               1);
    if ( result < 0 )
      return result;
  }
  else
  {
    IoSetShareAccess((int *)&DirectoryFcb->Flags, (int)v9, v8, ShareAccess, v9, &DirectoryFcb->ShareAccess);
  }
  if ( !NoReferenceCount )
    ++DirectoryFcb->ReferenceCount;
  v9->FsContext2 = 0;
  v9->FsContext = DirectoryFcb;
  ++VolumeExtension->FileObjectCount;
  Irp->IoStatus.Information = FileExists;
  return 0;
}