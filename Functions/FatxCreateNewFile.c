int *__userpurge FatxCreateNewFile@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *DirectoryFcb, _STRING *ElementName, unsigned int EmptyDirectoryByteOffset, char FileAttributes, unsigned int AllocationSize, _DIRENT *DirectoryEntry, _FAT_FCB **ReturnedFcb)
{
  _STRING *v12; // esi
  _FAT_VOLUME_EXTENSION *v13; // edi
  int *result; // eax
  int v15; // edx
  int v16; // ecx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ecx
  int *v20; // ebx
  int v21; // ecx
  _FAT_TIME_STAMP v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  _FAT_CLUSTER_RUN ClusterRuns[10]; // [esp+Ch] [ebp-64h]
  _LARGE_INTEGER CreationTime; // [esp+5Ch] [ebp-14h]
  unsigned int NumberOfClusterRuns; // [esp+64h] [ebp-Ch]
  unsigned int EndingCluster; // [esp+68h] [ebp-8h]
  _FAT_FCB *Fcb; // [esp+6Ch] [ebp-4h]
  int *FirstCluster; // [esp+84h] [ebp+14h]

  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      (int *)&DirectoryFcb->Flags,
      a3,
      "FatxIsFlagSet(DirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x24Fu,
      0);
  v12 = ElementName;
  if ( !ElementName->Length )
    RtlAssert(
      a1,
      a2,
      (int *)&DirectoryFcb->Flags,
      (int)ElementName,
      "ElementName->Length != 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x250u,
      0);
  if ( ElementName->Length > 0x2Au )
    RtlAssert(
      a1,
      a2,
      (int *)&DirectoryFcb->Flags,
      (int)ElementName,
      "ElementName->Length <= FAT_FILE_NAME_LENGTH",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x251u,
      0);
  if ( EmptyDirectoryByteOffset != -1 )
  {
    v13 = VolumeExtension;
    goto LABEL_13;
  }
  if ( DirectoryFcb->AllocationSize == -1 )
    RtlAssert(
      a1,
      a2,
      (int *)&DirectoryFcb->Flags,
      (int)ElementName,
      "DirectoryFcb->AllocationSize != MAXULONG",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x25Fu,
      0);
  v13 = VolumeExtension;
  EmptyDirectoryByteOffset = DirectoryFcb->AllocationSize;
  result = FatxExtendDirectoryAllocation(a2, a1, VolumeExtension, Irp, DirectoryFcb);
  if ( (signed int)result >= 0 )
  {
LABEL_13:
    if ( FileAttributes & 0x10 )
    {
      result = FatxAllocateClusters(
                 0,
                 a2,
                 (int *)v13,
                 v13,
                 Irp,
                 0,
                 1u,
                 ClusterRuns,
                 &NumberOfClusterRuns,
                 &EndingCluster);
      if ( (signed int)result < 0 )
        return result;
      if ( NumberOfClusterRuns != 1 )
        RtlAssert(
          v15,
          v16,
          (int *)v13,
          (int)ElementName,
          "NumberOfClusterRuns == 1",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
          0x285u,
          0);
      v17 = ClusterRuns[0].PhysicalClusterNumber;
      if ( EndingCluster != ClusterRuns[0].PhysicalClusterNumber )
      {
        RtlAssert(
          v15,
          v16,
          (int *)v13,
          (int)ElementName,
          "EndingCluster == ClusterRuns[0].PhysicalClusterNumber",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
          0x286u,
          0);
        v17 = ClusterRuns[0].PhysicalClusterNumber;
      }
      FirstCluster = (int *)v17;
      AllocationSize = v13->BytesPerCluster;
      v20 = FatxInitializeDirectoryCluster(AllocationSize, v15, v13, Irp, v17);
      if ( (signed int)v20 < 0 )
        goto LABEL_39;
    }
    else if ( AllocationSize )
    {
      v21 = ~(v13->BytesPerCluster - 1) & (v13->BytesPerCluster + AllocationSize - 1);
      AllocationSize = ~(v13->BytesPerCluster - 1) & (v13->BytesPerCluster + AllocationSize - 1);
      LOBYTE(v21) = v13->ClusterShift;
      result = FatxAllocateClusters(
                 0,
                 v21,
                 (int *)v13,
                 v13,
                 Irp,
                 0,
                 AllocationSize >> v13->ClusterShift,
                 ClusterRuns,
                 &NumberOfClusterRuns,
                 &EndingCluster);
      if ( (signed int)result < 0 )
        return result;
      FirstCluster = (int *)ClusterRuns[0].PhysicalClusterNumber;
    }
    else
    {
      FirstCluster = 0;
      EndingCluster = 0;
      NumberOfClusterRuns = 0;
    }
    memset(DirectoryEntry, 0, sizeof(_DIRENT));
    DirectoryEntry->FileNameLength = v12->Length;
    qmemcpy(DirectoryEntry->FileName, v12->Buffer, v12->Length);
    DirectoryEntry->FileAttributes = FileAttributes;
    DirectoryEntry->FirstCluster = (unsigned int)FirstCluster;
    KeQuerySystemTime(&CreationTime);
    FatxTimeToFatTimestamp(&CreationTime, &DirectoryEntry->CreationTime);
    v22.0 = ($60B929E8D4B0E90B702564B8125143A2)DirectoryEntry->CreationTime;
    DirectoryEntry->LastWriteTime.AsULONG = DirectoryEntry->CreationTime.AsULONG;
    DirectoryEntry->LastAccessTime = v22;
    v20 = (int *)FatxCreateFcb(
                   v24,
                   v23,
                   DirectoryFcb,
                   (unsigned int)FirstCluster,
                   DirectoryEntry,
                   EmptyDirectoryByteOffset,
                   &Fcb);
    if ( (signed int)v20 >= 0 )
    {
      v20 = (int *)FatxUpdateDirectoryEntry(v18, v19, FirstCluster, VolumeExtension, Irp, Fcb);
      if ( (signed int)v20 >= 0 )
      {
        if ( AllocationSize )
        {
          if ( Fcb->AllocationSize != -1 )
            RtlAssert(
              v18,
              v25,
              (int *)AllocationSize,
              0,
              "Fcb->AllocationSize == MAXULONG",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
              0x2E5u,
              0);
          Fcb->AllocationSize = AllocationSize;
          v26 = EndingCluster;
          Fcb->EndingCluster = EndingCluster;
          FatxAppendClusterRunsToClusterCache(v26, v18, Fcb, 0, ClusterRuns, NumberOfClusterRuns);
        }
        else
        {
          if ( Fcb->AllocationSize )
            RtlAssert(
              v18,
              v25,
              (int *)AllocationSize,
              0,
              "Fcb->AllocationSize == 0",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
              0x2EEu,
              0);
          if ( Fcb->EndingCluster )
            RtlAssert(
              v18,
              v25,
              (int *)AllocationSize,
              0,
              "Fcb->EndingCluster == FAT_CLUSTER_NULL",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
              0x2EFu,
              0);
        }
        LOBYTE(v19) = (_BYTE)Fcb;
        *ReturnedFcb = Fcb;
        v20 = 0;
      }
      else
      {
        FatxDereferenceFcb(v18, v25, FirstCluster, Fcb);
      }
      if ( (signed int)v20 >= 0 )
        goto LABEL_40;
    }
    v13 = VolumeExtension;
LABEL_39:
    FatxFreeClusters(v18, v19, (int *)v13, v13, Irp, (unsigned int)FirstCluster, 0);
LABEL_40:
    result = v20;
  }
  return result;
}