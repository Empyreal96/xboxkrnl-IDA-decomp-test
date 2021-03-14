int __fastcall FatxSynchronousIoTail(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, char MajorFunction, _FILE_OBJECT *FileObject, unsigned int FileByteOffset, unsigned int IoLength)
{
  _FILE_OBJECT *v8; // ebx
  _FAT_FCB *v9; // esi
  int *v10; // edi
  int v11; // edx
  int v12; // ecx
  unsigned int MajorFunctiona; // [esp+1Ch] [ebp+10h]
  int status; // [esp+20h] [ebp+14h]

  v8 = FileObject;
  v9 = (_FAT_FCB *)FileObject->FsContext;
  v10 = (int *)(FileByteOffset + IoLength);
  if ( MajorFunction == 3 )
  {
    FatxAcquireVolumeMutexExclusive(a2, IoLength, v10, (int)v9, VolumeExtension);
    if ( !(v9->Flags & 8) )
    {
      KeQuerySystemTime(&v9->LastWriteTime);
      v9->Flags |= 0x40u;
    }
    MajorFunctiona = v9->FileSize;
    if ( (unsigned int)v10 > v9->FileSize )
    {
      v9->FileSize = (unsigned int)v10;
      status = FatxUpdateDirectoryEntry(v11, v12, v10, VolumeExtension, Irp, v9);
      if ( status < 0 )
      {
        v9->FileSize = MajorFunctiona;
        FatxReleaseVolumeMutex(VolumeExtension);
        return status;
      }
    }
    FatxReleaseVolumeMutex(VolumeExtension);
  }
  if ( v8->Flags & 1 )
  {
    v8->CurrentByteOffset.HighPart = 0;
    v8->CurrentByteOffset.LowPart = (unsigned int)v10;
  }
  Irp->IoStatus.Information = IoLength;
  return 0;
}