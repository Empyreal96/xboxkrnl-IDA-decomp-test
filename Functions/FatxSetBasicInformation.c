int __fastcall FatxSetBasicInformation(int a1, int a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FILE_OBJECT *FileObject, _FILE_BASIC_INFORMATION *BasicInformation)
{
  char *v6; // esi
  bool v7; // zf
  _FILE_BASIC_INFORMATION *v8; // ebx
  _LARGE_INTEGER *v9; // edi
  int v10; // edx
  int *v11; // edi
  char v12; // al
  int v13; // ecx
  unsigned int LastWriteTime; // [esp+Ch] [ebp-14h]
  int LastWriteTime_4; // [esp+10h] [ebp-10h]
  _FAT_TIME_STAMP FatTimestamp; // [esp+14h] [ebp-Ch]
  _FAT_TIME_STAMP LastAccessTime; // [esp+18h] [ebp-8h]
  char ChangesMade; // [esp+1Fh] [ebp-1h]

  v6 = (char *)FileObject->FsContext;
  v7 = (*v6 & 1) == 0;
  ChangesMade = 0;
  if ( !v7 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      (int)v6,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x100u,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      (int)v6,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x101u,
      0);
  v8 = BasicInformation;
  if ( (BasicInformation->CreationTime.HighPart & BasicInformation->CreationTime.LowPart) != -1
    && BasicInformation->CreationTime.QuadPart )
  {
    if ( !FatxTimeToFatTimestamp(&BasicInformation->CreationTime, (_FAT_TIME_STAMP *)&FileObject) )
      return -1073741811;
    if ( FileObject != *((_FILE_OBJECT **)v6 + 15) )
      ChangesMade = 1;
  }
  else
  {
    FileObject = (_FILE_OBJECT *)*((_DWORD *)v6 + 15);
  }
  v9 = &v8->LastWriteTime;
  if ( (v8->LastWriteTime.HighPart & v8->LastWriteTime.LowPart) != -1 && v8->LastWriteTime.QuadPart )
  {
    if ( !FatxTimeToFatTimestamp(&v8->LastWriteTime, &FatTimestamp) )
      return -1073741811;
    LastWriteTime = v9->LowPart;
    LastWriteTime_4 = v8->LastWriteTime.HighPart;
    if ( v9->LowPart != *((_DWORD *)v6 + 13) || v8->LastWriteTime.HighPart != *((_DWORD *)v6 + 14) )
      ChangesMade = 1;
  }
  else
  {
    LastWriteTime = *((_DWORD *)v6 + 13);
    LastWriteTime_4 = *((_DWORD *)v6 + 14);
    if ( v9->LowPart == -1 )
      *v6 |= 8u;
  }
  v10 = v8->LastAccessTime.HighPart;
  v11 = (int *)(v10 & v8->LastAccessTime.LowPart);
  if ( v11 != (int *)-1 && v8->LastAccessTime.QuadPart )
  {
    if ( !FatxTimeToFatTimestamp(&v8->LastAccessTime, &LastAccessTime) )
      return -1073741811;
    if ( LastAccessTime.AsULONG != *((_DWORD *)v6 + 16) )
      ChangesMade = 1;
  }
  else
  {
    LastAccessTime.0 = *($60B929E8D4B0E90B702564B8125143A2 *)(v6 + 64);
  }
  if ( v8->FileAttributes )
  {
    v12 = v8->FileAttributes & 0x37;
    if ( *v6 & 2 )
    {
      v12 |= 0x10u;
      goto LABEL_29;
    }
    if ( !(v8->FileAttributes & 0x10) )
    {
LABEL_29:
      if ( v12 != v6[3] )
        ChangesMade = 1;
      goto LABEL_31;
    }
    return -1073741811;
  }
  v12 = v6[3];
LABEL_31:
  if ( !ChangesMade )
    return 0;
  *((_DWORD *)v6 + 15) = FileObject;
  *((_DWORD *)v6 + 13) = LastWriteTime;
  *((_DWORD *)v6 + 14) = LastWriteTime_4;
  v13 = LastAccessTime.AsULONG;
  *((_FAT_TIME_STAMP *)v6 + 16) = LastAccessTime;
  v6[3] = v12;
  return FatxUpdateDirectoryEntry(v10, v13, v11, VolumeExtension, Irp, (_FAT_FCB *)v6);
}