int __userpurge FatxFileByteOffsetToCluster@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *Fcb, unsigned int FileByteOffset, unsigned int *ReturnedClusterNumber, unsigned int *ReturnedClusterRunLength)
{
  _FAT_VOLUME_EXTENSION *v9; // ebx
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // ecx
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v13; // ecx
  unsigned int v14; // eax
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v15; // edi
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v16; // esi
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // eax
  int v20; // esi
  int v21; // edx
  unsigned int v22; // edi
  int v23; // edi
  int v24; // eax
  int v25; // eax
  _FAT_FCB *v26; // eax
  bool v27; // zf
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v28; // eax
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // ecx
  unsigned int v32; // eax
  char v33; // cl
  int v34; // eax
  char v35; // dl
  unsigned __int16 *v36; // eax
  signed int v37; // esi
  unsigned __int16 v38; // ax
  unsigned int v39; // edx
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v40; // eax
  unsigned int v41; // edx
  int v42; // ecx
  int v43; // ecx
  unsigned int v44; // eax
  unsigned __int8 v45; // al
  unsigned int v46; // eax
  int *v47; // edi
  _KEVENT *Event; // [esp+Ch] [ebp-2Ch]
  unsigned int LastPhysicalClusterNumber; // [esp+10h] [ebp-28h]
  unsigned int CacheBufferFatByteOffset; // [esp+14h] [ebp-24h]
  unsigned int RequestedFileClusterNumber; // [esp+18h] [ebp-20h]
  unsigned int StartingPhysicalClusterNumber; // [esp+1Ch] [ebp-1Ch]
  _FAT_FCB_CLUSTER_CACHE_ENTRY *ClusterCache; // [esp+20h] [ebp-18h]
  unsigned int StartingFileClusterNumber; // [esp+24h] [ebp-14h]
  void *CacheBuffer; // [esp+28h] [ebp-10h]
  _FAT_FCB_CLUSTER_CACHE_ENTRY *NearestCacheEntry; // [esp+2Ch] [ebp-Ch]
  unsigned int ClusterRunLength; // [esp+30h] [ebp-8h]
  char v59; // [esp+36h] [ebp-2h]
  unsigned __int8 v60; // [esp+37h] [ebp-1h]
  int ClusterCacheIndex; // [esp+40h] [ebp+8h]
  unsigned __int8 ClusterCacheIndex_3; // [esp+43h] [ebp+Bh]
  bool HaveEmptyClusterCacheEntries_3; // [esp+4Fh] [ebp+17h]

  v9 = VolumeExtension;
  if ( VolumeExtension->VolumeMutex.LockCount < 0 )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      a3,
      "ExDbgIsReadWriteLockLocked(&VolumeExtension->VolumeMutex)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x2E8u,
      0);
  if ( Fcb->Flags & 1 )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x2EFu,
      0);
  Event = (_KEVENT *)&VolumeExtension->ClusterCacheMutex;
  RtlEnterCriticalSection(&VolumeExtension->ClusterCacheMutex);
  if ( VolumeExtension->FatByteOffset & 0xFFF )
    RtlAssert(
      v10,
      v11,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "BYTE_OFFSET(VolumeExtension->FatByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x2FFu,
      0);
  v12 = Fcb->AllocationSize;
  if ( v12 != -1 && FileByteOffset >= v12 )
    goto LABEL_59;
  v27 = (Fcb->Flags & 2) == 0;
  v59 = Fcb->Flags & 2;
  v13 = Fcb->Directory.ClusterCache;
  if ( v27 )
    v13 = Fcb->File.ClusterCache;
  ClusterCache = v13;
  v14 = FileByteOffset >> VolumeExtension->ClusterShift;
  v15 = 0;
  HaveEmptyClusterCacheEntries_3 = 0;
  NearestCacheEntry = 0;
  RequestedFileClusterNumber = v14;
  v60 = Fcb->ClusterCacheLruHead;
  ClusterCacheIndex_3 = v60;
  while ( 1 )
  {
    v16 = &v13[ClusterCacheIndex_3];
    v17 = v16->ClusterRunLength;
    if ( !v17 )
      break;
    v18 = *((_DWORD *)v16 + 1) & 0xFFFFFF;
    if ( RequestedFileClusterNumber >= v18 )
    {
      if ( RequestedFileClusterNumber < v18 + v17 )
        goto MoveAndMatchCurrentCacheEntry;
      v15 = NearestCacheEntry;
      if ( !NearestCacheEntry || v18 > (*((_DWORD *)NearestCacheEntry + 1) & 0xFFFFFFu) )
      {
        v15 = &v13[ClusterCacheIndex_3];
        NearestCacheEntry = &v13[ClusterCacheIndex_3];
      }
    }
    ClusterCacheIndex_3 = *((_BYTE *)v16 + 3);
    if ( *((_BYTE *)v16 + 3) == v60 )
      goto LABEL_21;
  }
  HaveEmptyClusterCacheEntries_3 = 1;
LABEL_21:
  if ( !v15 )
  {
    v26 = Fcb;
    v20 = Fcb->FirstCluster;
    v22 = 0;
    v12 = v20 - 1;
    v21 = 0;
    ClusterCacheIndex = 0;
    if ( v20 - 1 < v9->NumberOfClusters )
      goto LABEL_24;
    if ( v20 )
FoundInvalidClusterNumber:
      v27 = v20 == -1;
    else
      v27 = v59 == 0;
    if ( !v27 )
    {
      v37 = -1073741566;
      goto LABEL_88;
    }
    LOBYTE(v12) = v9->ClusterShift;
    v26->EndingCluster = v21;
    v26->AllocationSize = v22 << v12;
LABEL_59:
    v37 = -1073741807;
    goto LABEL_88;
  }
  v19 = v15->ClusterRunLength;
  v20 = (*(_DWORD *)v15 & 0xFFFFFF) + v19 - 1;
  v21 = *((_DWORD *)v15 + 1) & 0xFFFFFF;
  v22 = v21 + v19 - 1;
  ClusterCacheIndex = v21 + v19 - 1;
  if ( v20 - 1 >= v9->NumberOfClusters )
    RtlAssert(
      v21,
      0xFFFFFF,
      (int *)v22,
      v20,
      "FatxIsValidCluster(VolumeExtension, PhysicalClusterNumber)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x39Bu,
      0);
LABEL_24:
  CacheBuffer = 0;
  CacheBufferFatByteOffset = 0;
  ClusterRunLength = 1;
  StartingPhysicalClusterNumber = v20;
  StartingFileClusterNumber = v22;
  if ( v22 >= RequestedFileClusterNumber )
    goto LABEL_72;
  do
  {
    ++ClusterCacheIndex;
    v23 = v20 << v9->FatEntryShift;
    if ( CacheBuffer )
    {
      if ( CacheBufferFatByteOffset == (v23 & 0xFFFFF000) )
        goto LABEL_29;
      FscUnmapBuffer((int *)v23, v20, CacheBuffer);
    }
    CacheBufferFatByteOffset = v23 & 0xFFFFF000;
    v24 = FscMapBuffer(
            v21,
            (v9->FatByteOffset + (v23 & 0xFFFFF000)) >> 32,
            (int *)v23,
            v20,
            &v9->CacheExtension,
            Irp,
            v9->FatByteOffset + (v23 & 0xFFFFF000),
            0,
            &CacheBuffer);
    if ( v24 < 0 )
    {
      v37 = v24;
      goto LABEL_88;
    }
LABEL_29:
    v22 = (unsigned int)CacheBuffer + (v23 & 0xFFF);
    v25 = v20;
    LastPhysicalClusterNumber = v20;
    if ( v9->Flags & 2 )
    {
      LOWORD(v22) = *(_WORD *)v22;
      v20 = (unsigned __int16)v22;
      if ( (unsigned __int16)v22 >= 0xFFF0u )
        v20 = (signed __int16)v22;
    }
    else
    {
      v20 = *(_DWORD *)v22;
    }
    if ( v20 - 1 >= v9->NumberOfClusters )
    {
      FscUnmapBuffer((int *)v22, v20, CacheBuffer);
      v21 = LastPhysicalClusterNumber;
      v22 = ClusterCacheIndex;
      v26 = Fcb;
      goto FoundInvalidClusterNumber;
    }
    if ( v25 + 1 == v20 )
    {
      ++ClusterRunLength;
      v32 = ClusterCacheIndex;
    }
    else
    {
      v28 = NearestCacheEntry;
      if ( NearestCacheEntry )
      {
        v29 = NearestCacheEntry->ClusterRunLength;
        v30 = (*(_DWORD *)NearestCacheEntry & 0xFFFFFF) + v29 - 1;
        if ( StartingPhysicalClusterNumber != v30 )
        {
          RtlAssert(
            v29,
            v30,
            (int *)v22,
            v20,
            "StartingPhysicalClusterNumber == (NearestCacheEntry->PhysicalClusterNumber + NearestCacheEntry->ClusterRunLength - 1)",
            "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
            0x439u,
            0);
          v28 = NearestCacheEntry;
        }
        v21 = v28->ClusterRunLength;
        v31 = (*((_DWORD *)v28 + 1) & 0xFFFFFF) + v21 - 1;
        if ( StartingFileClusterNumber != v31 )
        {
          RtlAssert(
            v21,
            v31,
            (int *)v22,
            v20,
            "StartingFileClusterNumber == (NearestCacheEntry->FileClusterNumber + NearestCacheEntry->ClusterRunLength - 1)",
            "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
            0x43Bu,
            0);
          v28 = NearestCacheEntry;
        }
        v28->ClusterRunLength += ClusterRunLength - 1;
        NearestCacheEntry = 0;
      }
      else if ( HaveEmptyClusterCacheEntries_3 )
      {
        HaveEmptyClusterCacheEntries_3 = FatxFillEmptyClusterCacheEntry(
                                           Fcb,
                                           ClusterCache,
                                           StartingPhysicalClusterNumber,
                                           StartingFileClusterNumber,
                                           ClusterRunLength);
      }
      v32 = ClusterCacheIndex;
      ClusterRunLength = 1;
      StartingPhysicalClusterNumber = v20;
      StartingFileClusterNumber = ClusterCacheIndex;
    }
  }
  while ( v32 < RequestedFileClusterNumber );
  if ( CacheBuffer )
  {
    v33 = v9->FatEntryShift;
    v34 = v20 << v33;
    if ( CacheBufferFatByteOffset == ((v20 << v33) & 0xFFFFF000) )
    {
      v35 = v9->Flags & 2;
      while ( 1 )
      {
        v36 = (unsigned __int16 *)((char *)CacheBuffer + (v34 & 0xFFF));
        v22 = v20;
        if ( v35 )
        {
          v38 = *v36;
          v20 = v38;
          if ( v38 >= 0xFFF0u )
            v20 = (signed __int16)v38;
        }
        else
        {
          v20 = *(_DWORD *)v36;
        }
        if ( v22 + 1 != v20 )
          break;
        ++ClusterRunLength;
        v34 = v20 << v33;
        v22 = (v20 << v33) & 0xFFFFF000;
        if ( CacheBufferFatByteOffset != v22 )
          goto LABEL_71;
      }
      if ( v20 == -1 )
      {
        v39 = (StartingFileClusterNumber + ClusterRunLength) << v9->ClusterShift;
        Fcb->EndingCluster = v22;
        Fcb->AllocationSize = v39;
      }
      else if ( v20 - 1 < v9->NumberOfClusters && HaveEmptyClusterCacheEntries_3 )
      {
        FatxFillEmptyClusterCacheEntry(Fcb, ClusterCache, v20, ClusterRunLength + StartingFileClusterNumber, 1u);
      }
    }
LABEL_71:
    FscUnmapBuffer((int *)v22, v20, CacheBuffer);
  }
LABEL_72:
  v40 = NearestCacheEntry;
  if ( NearestCacheEntry )
  {
    v41 = NearestCacheEntry->ClusterRunLength;
    v42 = (*(_DWORD *)NearestCacheEntry & 0xFFFFFF) + v41 - 1;
    if ( StartingPhysicalClusterNumber != v42 )
    {
      RtlAssert(
        v41,
        v42,
        (int *)v22,
        v20,
        "StartingPhysicalClusterNumber == (NearestCacheEntry->PhysicalClusterNumber + NearestCacheEntry->ClusterRunLength - 1)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x4C0u,
        0);
      v40 = NearestCacheEntry;
    }
    v43 = *((_DWORD *)v40 + 1) & 0xFFFFFF;
    if ( StartingFileClusterNumber != v43 + v40->ClusterRunLength - 1 )
      RtlAssert(
        v41,
        v43,
        (int *)v22,
        v20,
        "StartingFileClusterNumber == (NearestCacheEntry->FileClusterNumber + NearestCacheEntry->ClusterRunLength - 1)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x4C2u,
        0);
    v16 = NearestCacheEntry;
    v16->ClusterRunLength += ClusterRunLength - 1;
    ClusterCacheIndex_3 = v16 - ClusterCache;
  }
  else
  {
    ClusterCacheIndex_3 = *((_BYTE *)&ClusterCache[(unsigned __int8)Fcb->ClusterCacheLruHead] + 7);
    v16 = &ClusterCache[ClusterCacheIndex_3];
    *(_DWORD *)v16 ^= (StartingPhysicalClusterNumber ^ *(_DWORD *)v16) & 0xFFFFFF;
    v44 = ClusterRunLength;
    *((_DWORD *)v16 + 1) ^= (StartingFileClusterNumber ^ *((_DWORD *)v16 + 1)) & 0xFFFFFF;
    v16->ClusterRunLength = v44;
  }
MoveAndMatchCurrentCacheEntry:
  v45 = Fcb->ClusterCacheLruHead;
  if ( ClusterCacheIndex_3 != v45 )
  {
    if ( ClusterCacheIndex_3 != *((_BYTE *)&ClusterCache[v45] + 7) )
      FatxMoveClusterCacheEntryToTail(
        3 * v45,
        ClusterCacheIndex_3,
        (int *)&Fcb->Flags,
        Fcb,
        ClusterCache,
        ClusterCacheIndex_3);
    Fcb->ClusterCacheLruHead = ClusterCacheIndex_3;
  }
  v12 = 0xFFFFFF;
  v46 = RequestedFileClusterNumber + (*(_DWORD *)v16 & 0xFFFFFF) - (*((_DWORD *)v16 + 1) & 0xFFFFFF);
  *ReturnedClusterNumber = v46;
  if ( ReturnedClusterRunLength )
  {
    v47 = (int *)(v16->ClusterRunLength + (*(_DWORD *)v16 & 0xFFFFFF) - v46);
    if ( (unsigned int)v47 < 1 )
      RtlAssert(
        (int)ReturnedClusterNumber,
        0xFFFFFF,
        v47,
        (int)v16,
        "ClusterRunLength >= 1",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x36Bu,
        0);
    *ReturnedClusterRunLength = (unsigned int)v47;
  }
  v37 = 0;
LABEL_88:
  RtlLeaveCriticalSection((void *)v12, Event);
  return v37;
}