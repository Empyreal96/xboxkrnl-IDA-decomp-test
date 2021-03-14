int __userpurge FatxFindNextDirectoryEntry@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb, unsigned int DirectoryByteOffset, _STRING *TemplateFileName, _DIRENT *ReturnedDirectoryEntry, unsigned int *ReturnedDirectoryByteOffset)
{
  _FAT_VOLUME_EXTENSION *v10; // edi
  int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  unsigned __int8 *v15; // esi
  unsigned int v16; // eax
  unsigned __int8 *v17; // ebx
  unsigned __int8 v18; // al
  __int16 v19; // dx
  int v20; // edx
  int v21; // ecx
  int v23; // [esp-4h] [ebp-28h]
  _STRING DirectoryEntryFileName; // [esp+8h] [ebp-1Ch]
  unsigned __int64 PhysicalByteOffset; // [esp+10h] [ebp-14h]
  int FileNameLengthLimit; // [esp+18h] [ebp-Ch]
  unsigned int ClusterNumber; // [esp+1Ch] [ebp-8h]
  void *CacheBuffer; // [esp+20h] [ebp-4h]
  unsigned int ClusterBytesRemaining; // [esp+2Ch] [ebp+8h]

  v10 = VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      a3,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\dirctrl.c",
      0x49u,
      0);
  CacheBuffer = 0;
  if ( DirectoryByteOffset >= VolumeExtension->BytesPerCluster )
  {
    v11 = FatxFileByteOffsetToCluster(
            a1,
            (int)&ClusterNumber,
            a3,
            VolumeExtension,
            Irp,
            DirectoryFcb,
            DirectoryByteOffset,
            &ClusterNumber,
            0);
    if ( v11 < 0 )
      goto CleanupAndExit_11;
  }
  else
  {
    ClusterNumber = DirectoryFcb->FirstCluster;
    if ( ClusterNumber - 1 >= VolumeExtension->NumberOfClusters )
    {
      DbgPrint((int *)VolumeExtension, "FATX: invalid starting cluster for directory\n");
      v11 = -1073741566;
      goto CleanupAndExit_11;
    }
  }
  FileNameLengthLimit = 249 - (unsigned __int8)DirectoryFcb->PathNameLength;
  if ( FileNameLengthLimit <= 42 )
  {
    if ( FileNameLengthLimit <= 0 )
    {
      v11 = -1073741807;
      goto CleanupAndExit_11;
    }
  }
  else
  {
    FileNameLengthLimit = 42;
  }
  v23 = a3;
LABEL_10:
  v12 = v10->BytesPerCluster;
  v13 = DirectoryByteOffset & (v12 - 1);
  v14 = v10->FileAreaByteOffset + v13 + ((unsigned __int64)(ClusterNumber - 1) << v10->ClusterShift);
  v15 = (unsigned __int8 *)(v12 - v13);
  PhysicalByteOffset = v10->FileAreaByteOffset + v13 + ((unsigned __int64)(ClusterNumber - 1) << v10->ClusterShift);
  ClusterBytesRemaining = (unsigned int)v15;
  while ( 2 )
  {
    v11 = FscMapBuffer(
            SHIDWORD(v14),
            (int)&CacheBuffer,
            (int *)v10,
            (int)v15,
            &v10->CacheExtension,
            Irp,
            v14,
            0,
            &CacheBuffer);
    if ( v11 >= 0 )
    {
      v16 = 4096 - (PhysicalByteOffset & 0xFFF);
      if ( v16 >= ClusterBytesRemaining )
      {
        v16 = ClusterBytesRemaining;
        ClusterBytesRemaining = 0;
      }
      else
      {
        ClusterBytesRemaining -= v16;
        PhysicalByteOffset += v16;
      }
      v17 = (unsigned __int8 *)CacheBuffer;
      v15 = (unsigned __int8 *)CacheBuffer + v16;
      do
      {
        v18 = *v17;
        if ( !*v17 || v18 == -1 )
        {
          v11 = -1073741807;
          goto LABEL_33;
        }
        DirectoryEntryFileName.Length = v18;
        DirectoryEntryFileName.Buffer = (char *)(v17 + 2);
        if ( *v17 <= (unsigned int)FileNameLengthLimit
          && !(v17[1] & 0xC8)
          && FatxIsValidFatFileName(&DirectoryEntryFileName)
          && (!TemplateFileName->Buffer
           || IoIsNameInExpression(
                v19,
                (int)&DirectoryEntryFileName,
                (int *)v10,
                TemplateFileName,
                &DirectoryEntryFileName)) )
        {
          qmemcpy(ReturnedDirectoryEntry, v17, sizeof(_DIRENT));
          v10 = (_FAT_VOLUME_EXTENSION *)&ReturnedDirectoryEntry[1];
          *ReturnedDirectoryByteOffset = DirectoryByteOffset;
          v11 = 0;
          goto LABEL_33;
        }
        DirectoryByteOffset += 64;
        v17 += 64;
      }
      while ( v17 < v15 );
      FscUnmapBuffer((int *)v10, (int)v15, CacheBuffer);
      CacheBuffer = 0;
      if ( ClusterBytesRemaining )
      {
        v14 = PhysicalByteOffset;
        continue;
      }
      v11 = FatxFileByteOffsetToCluster(
              v20,
              v21,
              (int)v15,
              v10,
              Irp,
              DirectoryFcb,
              DirectoryByteOffset,
              &ClusterNumber,
              0);
      if ( v11 >= 0 )
      {
        if ( DirectoryByteOffset < 0x40000 )
          goto LABEL_10;
        v11 = -1073741566;
      }
    }
    break;
  }
LABEL_33:
  a3 = v23;
CleanupAndExit_11:
  if ( CacheBuffer )
    FscUnmapBuffer((int *)v10, a3, CacheBuffer);
  return v11;
}