void __userpurge FatxMoveClusterCacheEntryToTail(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *Fcb, _FAT_FCB_CLUSTER_CACHE_ENTRY *ClusterCache, unsigned int ClusterCacheIndex)
{
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v6; // esi
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v7; // eax

  if ( ClusterCacheIndex == (unsigned __int8)Fcb->ClusterCacheLruHead )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Fcb,
      "ClusterCacheIndex != Fcb->ClusterCacheLruHead",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x232u,
      0);
  v6 = &ClusterCache[(unsigned __int8)Fcb->ClusterCacheLruHead];
  v7 = &ClusterCache[ClusterCacheIndex];
  *((_BYTE *)&ClusterCache[*((unsigned __int8 *)v7 + 7)] + 3) = *((_BYTE *)v7 + 3);
  *((_BYTE *)&ClusterCache[*((unsigned __int8 *)v7 + 3)] + 7) = *((_BYTE *)v7 + 7);
  *((_BYTE *)v7 + 3) = Fcb->ClusterCacheLruHead;
  *((_BYTE *)v7 + 7) = *((_BYTE *)v6 + 7);
  *((_BYTE *)&ClusterCache[*((unsigned __int8 *)v6 + 7)] + 3) = ClusterCacheIndex;
  *((_BYTE *)v6 + 7) = ClusterCacheIndex;
}