void __fastcall FatxInvalidateClusterCache(int a1, int a2, _FAT_FCB *FileFcb, unsigned int FileClusterNumber)
{
  _FAT_FCB *v4; // edi
  unsigned int v5; // esi
  int v6; // eax
  int v7; // ecx
  unsigned __int8 v8; // bl
  unsigned int v9; // edx
  unsigned int StartingClusterCacheLruHead; // [esp+Ch] [ebp-4h]
  unsigned int ClusterCacheIndex; // [esp+18h] [ebp+8h]

  v4 = FileFcb;
  if ( FileFcb->Flags & 1 )
    RtlAssert(
      a2,
      a1,
      (int *)&FileFcb->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x620u,
      0);
  if ( FileFcb->File.FileMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      a1,
      (int *)&FileFcb->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FileFcb->File.FileMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x62Au,
      0);
  v5 = (unsigned __int8)FileFcb->ClusterCacheLruHead;
  StartingClusterCacheLruHead = (unsigned __int8)FileFcb->ClusterCacheLruHead;
  do
  {
    v6 = (int)&v4->Directory + 12 * v5 + 56;
    v7 = *(_DWORD *)(v6 + 8);
    v8 = *(_BYTE *)(v6 + 3);
    ClusterCacheIndex = v5;
    v5 = v8;
    if ( !v7 )
      break;
    v9 = *(_DWORD *)(v6 + 4) & 0xFFFFFF;
    if ( FileClusterNumber > v9 )
    {
      if ( FileClusterNumber < v9 + v7 )
        *(_DWORD *)(v6 + 8) = FileClusterNumber - v9;
    }
    else
    {
      *(_DWORD *)(v6 + 8) = 0;
      if ( ClusterCacheIndex == (unsigned __int8)v4->ClusterCacheLruHead )
        v4->ClusterCacheLruHead = v8;
      else
        FatxMoveClusterCacheEntryToTail(v9, v7, (int *)&v4->Flags, v4, v4->File.ClusterCache, ClusterCacheIndex);
    }
  }
  while ( v8 != StartingClusterCacheLruHead );
}