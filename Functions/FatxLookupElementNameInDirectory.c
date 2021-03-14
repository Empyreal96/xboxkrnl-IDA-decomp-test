int __userpurge FatxLookupElementNameInDirectory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb, _STRING *ElementName, _DIRENT *ReturnedDirectoryEntry, unsigned int *ReturnedDirectoryByteOffset, unsigned int *ReturnedEmptyDirectoryByteOffset)
{
  _FAT_FCB *v10; // esi
  _FAT_VOLUME_EXTENSION *v11; // edi
  unsigned int v12; // ebx
  int v13; // edx
  int v14; // ecx
  signed int v15; // esi
  void *v16; // eax
  unsigned __int16 v17; // cx
  bool v18; // zf
  char *v19; // esi
  unsigned int v20; // eax
  bool v21; // cf
  unsigned __int64 v22; // rax
  unsigned int v23; // ecx
  unsigned __int16 v24; // ax
  int *v26; // [esp-8h] [ebp-30h]
  _STRING DirectoryEntryFileName; // [esp+4h] [ebp-24h]
  unsigned __int64 PhysicalByteOffset; // [esp+Ch] [ebp-1Ch]
  unsigned int PhysicalRunLength; // [esp+14h] [ebp-14h]
  _DIRENT *EndingDirectoryEntry; // [esp+18h] [ebp-10h]
  unsigned int ClusterNumber; // [esp+1Ch] [ebp-Ch]
  unsigned int ClusterBytesRemaining; // [esp+20h] [ebp-8h]
  void *CacheBuffer; // [esp+24h] [ebp-4h]
  signed int EmptyDirectoryByteOffset; // [esp+30h] [ebp+8h]

  v10 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)DirectoryFcb,
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x4Au,
      0);
  v26 = a3;
  v11 = VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      (int)DirectoryFcb,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x4Bu,
      0);
  v12 = DirectoryFcb->File.FileMutex.ReadersWaitingCount;
  CacheBuffer = 0;
  EmptyDirectoryByteOffset = -1;
  if ( v12 )
  {
    v15 = FatxFileByteOffsetToPhysicalByteOffset(
            a1,
            a2,
            (int *)v11,
            v11,
            Irp,
            DirectoryFcb,
            v12,
            0,
            &PhysicalByteOffset,
            &PhysicalRunLength);
    if ( v15 < 0 )
      goto CleanupAndExit_17;
    v15 = FscMapBuffer(v13, v14, (int *)v11, v15, &v11->CacheExtension, Irp, PhysicalByteOffset, 0, &CacheBuffer);
    if ( v15 < 0 )
      goto CleanupAndExit_17;
    v16 = CacheBuffer;
    v17 = *(unsigned __int8 *)CacheBuffer;
    DirectoryEntryFileName.Buffer = (char *)CacheBuffer + 2;
    v18 = v17 == ElementName->Length;
    v19 = (char *)CacheBuffer;
    DirectoryEntryFileName.Length = v17;
    if ( v18 && v17 <= 0x2Au )
    {
      if ( RtlEqualString(&DirectoryEntryFileName, ElementName, 1) )
      {
LABEL_39:
        qmemcpy(ReturnedDirectoryEntry, v19, sizeof(_DIRENT));
        *ReturnedDirectoryByteOffset = v12;
        v15 = 0;
        goto CleanupAndExit_17;
      }
      v16 = CacheBuffer;
    }
    FscUnmapBuffer((int *)v11, (int)v19, v16);
    v12 = 0;
    CacheBuffer = 0;
    DirectoryFcb->File.FileMutex.ReadersWaitingCount = 0;
    v10 = DirectoryFcb;
  }
  v20 = v10->FirstCluster;
  v21 = v20 - 1 < v11->NumberOfClusters;
  ClusterNumber = v10->FirstCluster;
  if ( v21 )
  {
    while ( 1 )
    {
      v23 = v11->BytesPerCluster;
      v22 = v11->FileAreaByteOffset + ((unsigned __int64)(v20 - 1) << v11->ClusterShift);
      v19 = (char *)4095;
      PhysicalByteOffset = v22;
      ClusterBytesRemaining = v23;
      if ( v22 & 0xFFF )
        RtlAssert(
          SHIDWORD(v22),
          v23,
          (int *)v11,
          4095,
          "BYTE_OFFSET(PhysicalByteOffset) == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
          0xBEu,
          0);
      if ( ClusterBytesRemaining & 0xFFF )
        RtlAssert(
          SHIDWORD(v22),
          v23,
          (int *)v11,
          4095,
          "BYTE_OFFSET(ClusterBytesRemaining) == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
          0xBFu,
          0);
LABEL_20:
      v15 = FscMapBuffer(
              SHIDWORD(v22),
              v23,
              (int *)v11,
              (int)v19,
              &v11->CacheExtension,
              Irp,
              PhysicalByteOffset,
              0,
              &CacheBuffer);
      if ( v15 < 0 )
        break;
      v19 = (char *)CacheBuffer;
      EndingDirectoryEntry = (_DIRENT *)((char *)CacheBuffer + 4096);
      do
      {
        LOBYTE(v24) = *v19;
        if ( (!*v19 || (_BYTE)v24 == -1 || (_BYTE)v24 == -27) && EmptyDirectoryByteOffset == -1 )
          EmptyDirectoryByteOffset = v12;
        if ( !(_BYTE)v24 || (_BYTE)v24 == -1 )
        {
          v15 = -1073741772;
          goto CleanupAndExit_17;
        }
        v24 = (unsigned __int8)v24;
        DirectoryEntryFileName.Buffer = v19 + 2;
        v18 = (unsigned __int8)v24 == ElementName->Length;
        DirectoryEntryFileName.Length = (unsigned __int8)v24;
        if ( v18 && v24 <= 0x2Au && RtlEqualString(&DirectoryEntryFileName, ElementName, 1) )
          goto LABEL_39;
        v19 += 64;
        v12 += 64;
      }
      while ( v19 < (char *)EndingDirectoryEntry );
      FscUnmapBuffer((int *)v11, (int)v19, CacheBuffer);
      CacheBuffer = 0;
      PhysicalByteOffset += 4096i64;
      ClusterBytesRemaining -= 4096;
      if ( ClusterBytesRemaining )
        goto LABEL_20;
      v15 = FatxFileByteOffsetToCluster(SHIDWORD(v22), v23, (int)v19, v11, Irp, DirectoryFcb, v12, &ClusterNumber, 0);
      if ( v15 == -1073741807 )
        v15 = -1073741772;
      if ( v15 < 0 )
        break;
      if ( v12 >= 0x40000 )
        goto LABEL_15;
      v20 = ClusterNumber;
    }
  }
  else
  {
    DbgPrint((int *)v11, "FATX: invalid starting cluster for directory\n");
LABEL_15:
    v15 = -1073741566;
  }
CleanupAndExit_17:
  if ( CacheBuffer )
    FscUnmapBuffer(v26, v15, CacheBuffer);
  if ( v15 != -1073741772 )
    EmptyDirectoryByteOffset = -2;
  *ReturnedEmptyDirectoryByteOffset = EmptyDirectoryByteOffset;
  return v15;
}