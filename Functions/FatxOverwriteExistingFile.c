int *__userpurge FatxOverwriteExistingFile@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *FileFcb, char FileAttributes, unsigned int AllocationSize)
{
  _FAT_FCB *v8; // esi
  unsigned int v10; // eax
  int *v11; // edi
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  _LARGE_INTEGER OriginalLastWriteTime; // [esp+4h] [ebp-14h]
  _FAT_TIME_STAMP OriginalLastAccessTime; // [esp+Ch] [ebp-Ch]
  _FAT_TIME_STAMP OriginalCreationTime; // [esp+10h] [ebp-8h]
  unsigned int OriginalFileSize; // [esp+14h] [ebp-4h]
  char OriginalFileAttributes_3; // [esp+2Bh] [ebp+13h]
  int *status; // [esp+2Ch] [ebp+14h]

  v8 = FileFcb;
  if ( FileFcb->Flags & 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x326u,
      0);
  if ( FileAttributes & 0x10 )
    return (int *)-1073741811;
  if ( FileFcb->ReferenceCount >= 2 )
    return (int *)-1073741757;
  FatxAcquireFileMutexExclusive(a1, a2, a3, FileFcb);
  OriginalFileAttributes_3 = FileFcb->FileAttributes;
  v10 = v8->FileSize;
  v8->FileSize = 0;
  OriginalFileSize = v10;
  v11 = (int *)&v8->LastWriteTime;
  OriginalLastWriteTime = v8->LastWriteTime;
  OriginalCreationTime.0 = ($60B929E8D4B0E90B702564B8125143A2)v8->CreationTime;
  OriginalLastAccessTime.0 = ($60B929E8D4B0E90B702564B8125143A2)v8->LastAccessTime;
  v8->FileAttributes = FileAttributes;
  v8->Flags = v8->Flags & 0xF7 | 0x40;
  KeQuerySystemTime(&v8->LastWriteTime);
  FatxTimeToFatTimestamp(&v8->LastWriteTime, &v8->CreationTime);
  v8->LastAccessTime.AsULONG = v8->CreationTime.AsULONG;
  status = FatxSetAllocationSize(v12, v13, (int *)&v8->LastWriteTime, VolumeExtension, Irp, v8, AllocationSize, 1, 0);
  if ( (signed int)status < 0 )
    goto LABEL_15;
  if ( v8->Flags & 0x40 )
    status = (int *)FatxUpdateDirectoryEntry(v14, v15, v11, VolumeExtension, Irp, v8);
  if ( (signed int)status < 0 )
  {
LABEL_15:
    v8->FileAttributes = OriginalFileAttributes_3;
    v8->FileSize = OriginalFileSize;
    *(_LARGE_INTEGER *)v11 = OriginalLastWriteTime;
    v8->CreationTime = OriginalCreationTime;
    v8->LastAccessTime = OriginalLastAccessTime;
  }
  FatxReleaseFileMutex(v14, v15, v11, v8);
  return status;
}