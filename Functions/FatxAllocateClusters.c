int *__userpurge FatxAllocateClusters@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, unsigned int EndingCluster, unsigned int ClustersNeeded, _FAT_CLUSTER_RUN *ClusterRuns, unsigned int *NumberOfClusterRuns, unsigned int *ReturnedEndingCluster)
{
  _FAT_VOLUME_EXTENSION *v10; // esi
  _FAT_CLUSTER_RUN *v12; // edx
  unsigned int v13; // edx
  int v14; // ecx
  int *v15; // edi
  unsigned int v16; // ebx
  int v17; // eax
  char v18; // cl
  int v19; // eax
  _FAT_CLUSTER_RUN *v20; // ebx
  unsigned int v21; // eax
  _FAT_CLUSTER_RUN *v22; // ebx
  bool v23; // zf
  unsigned int v24; // ecx
  unsigned int LastAllocatedCluster; // [esp+8h] [ebp-40h]
  unsigned int EndingClusterFatByteOffset; // [esp+Ch] [ebp-3Ch]
  int SectorMask; // [esp+10h] [ebp-38h]
  unsigned int FirstAllocatedCluster; // [esp+18h] [ebp-30h]
  int CacheBufferFatByteOffset; // [esp+1Ch] [ebp-2Ch]
  unsigned int InitialCluster; // [esp+20h] [ebp-28h]
  unsigned int SectorSize; // [esp+24h] [ebp-24h]
  unsigned int ClusterRunInitialCluster; // [esp+28h] [ebp-20h]
  unsigned int CacheBufferClustersAllocated; // [esp+2Ch] [ebp-1Ch]
  _FAT_CLUSTER_RUN *CurrentClusterRun; // [esp+30h] [ebp-18h]
  unsigned int LastSectorLastAllocatedCluster; // [esp+34h] [ebp-14h]
  unsigned int ClusterRunLength; // [esp+38h] [ebp-10h]
  void *CacheBuffer; // [esp+3Ch] [ebp-Ch]
  unsigned int ClusterNumber; // [esp+40h] [ebp-8h]
  char UsedFirstAvailableClusterHint; // [esp+46h] [ebp-2h]
  char CacheBufferDirty; // [esp+47h] [ebp-1h]
  char SkipLinkClusterChains_3; // [esp+53h] [ebp+Bh]

  v10 = VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)VolumeExtension,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0xE1u,
      0);
  SectorSize = VolumeExtension->CacheExtension.SectorSize;
  if ( VolumeExtension->FatByteOffset & 0xFFF )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)VolumeExtension,
      "BYTE_OFFSET(VolumeExtension->FatByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0xECu,
      0);
  if ( ClustersNeeded > VolumeExtension->NumberOfClustersAvailable )
    return (int *)-1073741697;
  v12 = ClusterRuns;
  memset(ClusterRuns, 0xCCu, 0x50u);
  CurrentClusterRun = ClusterRuns;
  if ( !EndingCluster )
  {
    EndingClusterFatByteOffset = -1;
LABEL_11:
    ClusterNumber = VolumeExtension->FirstAvailableClusterHint;
    goto LABEL_12;
  }
  v13 = EndingCluster << VolumeExtension->FatEntryShift;
  ClusterNumber = EndingCluster + 1;
  EndingClusterFatByteOffset = v13;
  v12 = (_FAT_CLUSTER_RUN *)(VolumeExtension->NumberOfClusters + 1);
  if ( (_FAT_CLUSTER_RUN *)(EndingCluster + 1) == v12 )
    goto LABEL_11;
LABEL_12:
  v14 = ClusterNumber;
  LastSectorLastAllocatedCluster = EndingCluster;
  UsedFirstAvailableClusterHint = ClusterNumber == VolumeExtension->FirstAvailableClusterHint;
  InitialCluster = 0;
  SkipLinkClusterChains_3 = 0;
  ClusterRunInitialCluster = 0;
  ClusterRunLength = 0;
  v15 = 0;
  FirstAllocatedCluster = 0;
  LastAllocatedCluster = 0;
  CacheBufferDirty = 0;
  CacheBuffer = 0;
  CacheBufferFatByteOffset = 0;
  CacheBufferClustersAllocated = 0;
  SectorMask = ~(SectorSize - 1);
  while ( 1 )
  {
    if ( ClusterNumber - 1 >= v10->NumberOfClusters )
      RtlAssert(
        (int)v12,
        v14,
        v15,
        (int)v10,
        "FatxIsValidCluster(VolumeExtension, ClusterNumber)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
        0x12Au,
        0);
    v16 = ClusterNumber << v10->FatEntryShift;
    v17 = v16 & SectorMask;
    if ( CacheBuffer )
    {
      v14 = CacheBufferFatByteOffset;
      if ( CacheBufferFatByteOffset == v17 )
        goto LABEL_37;
      if ( CacheBufferDirty )
      {
        v15 = (int *)FscWriteBuffer(
                       (int)v12,
                       LODWORD(v10->FatByteOffset) + CacheBufferFatByteOffset,
                       (int)v10,
                       &v10->CacheExtension,
                       Irp,
                       v10->FatByteOffset + (unsigned int)CacheBufferFatByteOffset,
                       SectorSize,
                       CacheBuffer);
        if ( (signed int)v15 < 0 )
          goto LABEL_73;
        v10->NumberOfClustersAvailable -= CacheBufferClustersAllocated;
        if ( LastSectorLastAllocatedCluster )
        {
          if ( !SkipLinkClusterChains_3 )
          {
            v15 = (int *)FatxLinkClusterChains(
                           v18,
                           (int)v12,
                           v10,
                           Irp,
                           LastSectorLastAllocatedCluster,
                           FirstAllocatedCluster);
            if ( (signed int)v15 < 0 )
              goto LABEL_73;
          }
        }
        LastSectorLastAllocatedCluster = LastAllocatedCluster;
      }
      else
      {
        FscUnmapBuffer(v15, (int)v10, CacheBuffer);
      }
      CacheBufferClustersAllocated = 0;
      v17 = v16 & SectorMask;
      CacheBufferDirty = 0;
    }
    v15 = (int *)FscMapBuffer(
                   (int)v12,
                   (v10->FatByteOffset + (unsigned int)v17) >> 32,
                   v15,
                   (int)v10,
                   &v10->CacheExtension,
                   Irp,
                   v10->FatByteOffset + (unsigned int)v17,
                   1,
                   &CacheBuffer);
    if ( (signed int)v15 < 0 )
      goto LABEL_73;
    v14 = LastSectorLastAllocatedCluster;
    CacheBufferFatByteOffset = v16 & SectorMask;
    if ( LastSectorLastAllocatedCluster
      && LastSectorLastAllocatedCluster == EndingCluster
      && (v14 = EndingClusterFatByteOffset & SectorMask, (EndingClusterFatByteOffset & SectorMask) == (v16 & SectorMask)) )
    {
      v15 = (int *)((char *)CacheBuffer + ((SectorSize - 1) & EndingClusterFatByteOffset));
      SkipLinkClusterChains_3 = 1;
      if ( v10->Flags & 2 )
      {
        LOWORD(v19) = *(_WORD *)v15;
        if ( *(_WORD *)v15 >= 0xFFF0u )
          v19 = (signed __int16)v19;
        else
          v19 = (unsigned __int16)v19;
      }
      else
      {
        v19 = *v15;
      }
      if ( v19 != -1 )
        RtlAssert(
          (int)v12,
          v14,
          v15,
          (int)v10,
          "FatxReadFatEntry(VolumeExtension, LastFatEntry) == FAT_CLUSTER_LAST",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
          0x193u,
          0);
    }
    else
    {
      v15 = 0;
      SkipLinkClusterChains_3 = 0;
    }
LABEL_37:
    v20 = (_FAT_CLUSTER_RUN *)((char *)CacheBuffer + ((SectorSize - 1) & v16));
    LOBYTE(v14) = v10->Flags & 2;
    v12 = v20;
    if ( (_BYTE)v14 )
    {
      LOWORD(v21) = v20->PhysicalClusterNumber;
      v21 = LOWORD(v20->PhysicalClusterNumber) >= 0xFFF0u ? (signed __int16)v21 : (unsigned __int16)v21;
    }
    else
    {
      v21 = v20->PhysicalClusterNumber;
    }
    if ( !v21 )
    {
      if ( (_BYTE)v14 )
        LOWORD(v20->PhysicalClusterNumber) = -1;
      else
        v20->PhysicalClusterNumber = -1;
      ++CacheBufferClustersAllocated;
      CacheBufferDirty = 1;
      if ( v15 )
      {
        if ( v10->Flags & 2 )
          *(_WORD *)v15 = ClusterNumber;
        else
          *v15 = ClusterNumber;
      }
      else
      {
        FirstAllocatedCluster = ClusterNumber;
      }
      if ( InitialCluster )
      {
        v22 = CurrentClusterRun;
        v14 = ClusterNumber;
        if ( ClusterRunInitialCluster + ClusterRunLength != ClusterNumber )
        {
          if ( CurrentClusterRun < &ClusterRuns[10] )
          {
            CurrentClusterRun->PhysicalClusterNumber = ClusterRunInitialCluster;
            CurrentClusterRun->ClusterRunLength = ClusterRunLength;
            v22 = CurrentClusterRun + 1;
            ++CurrentClusterRun;
          }
          ClusterRunLength = 0;
          ClusterRunInitialCluster = v14;
        }
      }
      else
      {
        InitialCluster = ClusterNumber;
        ClusterRunInitialCluster = ClusterNumber;
        if ( ClusterRunLength )
        {
          RtlAssert(
            (int)v20,
            v14,
            v15,
            (int)v10,
            "ClusterRunLength == 0",
            "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
            0x1DFu,
            0);
          v12 = v20;
        }
        v22 = CurrentClusterRun;
      }
      ++ClusterRunLength;
      v23 = ClustersNeeded-- == 1;
      v15 = (int *)v12;
      LastAllocatedCluster = ClusterNumber;
      if ( v23 )
        break;
    }
    if ( ++ClusterNumber == v10->NumberOfClusters + 1 )
    {
      if ( UsedFirstAvailableClusterHint )
      {
        DbgPrint(v15, "FATX: FAT table is corrupt.\n");
        FscDiscardBuffer(v15, (int)v10, CacheBuffer);
        v15 = (int *)-1073741774;
LABEL_73:
        if ( LastSectorLastAllocatedCluster != EndingCluster )
        {
          if ( EndingCluster )
          {
            FatxFreeClusters((int)v12, v18, v15, v10, Irp, EndingCluster, 1);
          }
          else if ( InitialCluster )
          {
            FatxFreeClusters((int)v12, v18, v15, v10, Irp, InitialCluster, 0);
          }
        }
        return v15;
      }
      ClusterNumber = v10->FirstAvailableClusterHint;
      UsedFirstAvailableClusterHint = 1;
    }
  }
  v15 = (int *)FscWriteBuffer(
                 (int)v12,
                 (v10->FatByteOffset + (unsigned int)CacheBufferFatByteOffset) >> 32,
                 (int)v10,
                 &v10->CacheExtension,
                 Irp,
                 v10->FatByteOffset + (unsigned int)CacheBufferFatByteOffset,
                 SectorSize,
                 CacheBuffer);
  if ( (signed int)v15 < 0 )
    goto LABEL_73;
  if ( UsedFirstAvailableClusterHint )
    v10->FirstAvailableClusterHint = ClusterNumber + 1;
  v10->NumberOfClustersAvailable -= CacheBufferClustersAllocated;
  if ( LastSectorLastAllocatedCluster )
  {
    if ( !SkipLinkClusterChains_3 )
    {
      v15 = (int *)FatxLinkClusterChains(v18, (int)v12, v10, Irp, LastSectorLastAllocatedCluster, FirstAllocatedCluster);
      if ( (signed int)v15 < 0 )
        goto LABEL_73;
    }
  }
  if ( v22 < &ClusterRuns[10] )
  {
    v22->PhysicalClusterNumber = ClusterRunInitialCluster;
    v22->ClusterRunLength = ClusterRunLength;
    ++v22;
  }
  v24 = ClusterNumber;
  *NumberOfClusterRuns = v22 - ClusterRuns;
  *ReturnedEndingCluster = v24;
  return 0;
}