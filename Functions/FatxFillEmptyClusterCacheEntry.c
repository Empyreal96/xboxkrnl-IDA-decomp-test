bool __stdcall FatxFillEmptyClusterCacheEntry(_FAT_FCB *Fcb, _FAT_FCB_CLUSTER_CACHE_ENTRY *ClusterCache, unsigned int PhysicalClusterNumber, unsigned int FileClusterNumber, unsigned int ClusterRunLength)
{
  int v5; // eax
  _FAT_FCB_CLUSTER_CACHE_ENTRY *v6; // eax

  v5 = (unsigned __int8)Fcb->ClusterCacheLruHead;
  while ( 1 )
  {
    v6 = &ClusterCache[v5];
    if ( !v6->ClusterRunLength )
      break;
    v5 = *((unsigned __int8 *)v6 + 3);
    if ( v5 == (unsigned __int8)Fcb->ClusterCacheLruHead )
      return 0;
  }
  *(_DWORD *)v6 ^= (PhysicalClusterNumber ^ *(_DWORD *)v6) & 0xFFFFFF;
  *((_DWORD *)v6 + 1) ^= (FileClusterNumber ^ *((_DWORD *)v6 + 1)) & 0xFFFFFF;
  v6->ClusterRunLength = ClusterRunLength;
  return ClusterCache[*((unsigned __int8 *)v6 + 3)].ClusterRunLength == 0;
}