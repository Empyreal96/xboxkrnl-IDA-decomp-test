void __fastcall FatxAppendClusterRunsToClusterCache(int a1, int a2, _FAT_FCB *Fcb, unsigned int FileClusterNumber, _FAT_CLUSTER_RUN *ClusterRuns, unsigned int NumberOfClusterRuns)
{
  _FAT_FCB *v6; // esi
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v7; // eax
  unsigned int v8; // edi
  int v9; // eax
  int v10; // esi
  _FAT_CLUSTER_RUN *v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  _FAT_CLUSTER_RUN *v15; // ecx
  unsigned int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // esi
  _FAT_FCB_CLUSTER_CACHE_ENTRY *ClusterCache; // [esp+Ch] [ebp-4h]
  unsigned int ClusterCacheIndex; // [esp+1Ch] [ebp+Ch]
  unsigned int ClusterCacheIndexa; // [esp+1Ch] [ebp+Ch]

  v6 = Fcb;
  if ( Fcb->Flags & 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x560u,
      0);
  if ( Fcb->AllocationSize == -1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "Fcb->AllocationSize != MAXULONG",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x561u,
      0);
  if ( NumberOfClusterRuns < 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      (int)Fcb,
      "NumberOfClusterRuns >= 1",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x562u,
      0);
  v7 = Fcb->Directory.ClusterCache;
  if ( !(Fcb->Flags & 2) )
    v7 = Fcb->File.ClusterCache;
  v8 = FileClusterNumber;
  ClusterCache = v7;
  if ( FileClusterNumber )
  {
    v9 = (unsigned __int8)Fcb->ClusterCacheLruHead;
    ClusterCacheIndex = (unsigned __int8)Fcb->ClusterCacheLruHead;
    do
    {
      v10 = (int)&ClusterCache[v9];
      if ( !*(_DWORD *)(v10 + 8) )
        break;
      if ( (*(_DWORD *)(v10 + 4) & 0xFFFFFFu) >= v8 )
        RtlAssert(
          a2,
          (int)ClusterCache,
          (int *)v8,
          v10,
          "ClusterCacheEntry->FileClusterNumber < FileClusterNumber",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0x58Eu,
          0);
      if ( *(_DWORD *)(v10 + 8) + (*(_DWORD *)(v10 + 4) & 0xFFFFFF) == v8 )
      {
        v11 = ClusterRuns;
        v12 = *(_DWORD *)v10 & 0xFFFFFF;
        v13 = v12 + *(_DWORD *)(v10 + 8);
        if ( v13 != ClusterRuns->PhysicalClusterNumber )
          goto LABEL_22;
        v14 = *(_DWORD *)(v10 + 4);
        ClusterRuns->PhysicalClusterNumber = v12;
        ClusterRuns->ClusterRunLength += *(_DWORD *)(v10 + 8);
        v8 = v14 & 0xFFFFFF;
        if ( ClusterCacheIndex == (unsigned __int8)Fcb->ClusterCacheLruHead )
        {
          Fcb->ClusterCacheLruHead = *(_BYTE *)(v10 + 3);
          goto LABEL_22;
        }
        FatxMoveClusterCacheEntryToTail((int)ClusterRuns, v13, (int *)v8, Fcb, ClusterCache, ClusterCacheIndex);
        break;
      }
      v9 = *(unsigned __int8 *)(v10 + 3);
      ClusterCacheIndex = *(unsigned __int8 *)(v10 + 3);
    }
    while ( v9 != (unsigned __int8)Fcb->ClusterCacheLruHead );
    v11 = ClusterRuns;
LABEL_22:
    v6 = Fcb;
  }
  else
  {
    v11 = ClusterRuns;
  }
  v15 = &v11[NumberOfClusterRuns - 1];
  v16 = (unsigned int)&v11[NumberOfClusterRuns - 1];
  do
  {
    v8 += *(_DWORD *)(v16 + 4);
    v16 -= 8;
  }
  while ( v16 >= (unsigned int)v11 );
  v17 = (int)&ClusterCache[(unsigned __int8)v6->ClusterCacheLruHead];
  do
  {
    v18 = *(unsigned __int8 *)(v17 + 7);
    v8 -= v15->ClusterRunLength;
    ClusterCacheIndexa = v18;
    v17 = (int)&ClusterCache[v18];
    v19 = v15->PhysicalClusterNumber ^ *(_DWORD *)v17;
    --v15;
    *(_DWORD *)v17 ^= v19 & 0xFFFFFF;
    *(_DWORD *)(v17 + 4) ^= (v8 ^ *(_DWORD *)(v17 + 4)) & 0xFFFFFF;
    *(_DWORD *)(v17 + 8) = v15[1].ClusterRunLength;
  }
  while ( v15 >= v11 );
  Fcb->ClusterCacheLruHead = ClusterCacheIndexa;
}