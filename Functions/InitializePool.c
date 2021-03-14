unsigned int *__usercall InitializePool@<eax>(int *a1@<edi>)
{
  _POOL_TRACKER_TABLE *v1; // eax
  char v2; // dl
  unsigned int v3; // ecx
  unsigned int *v4; // edi
  int v5; // ecx
  _POOL_TRACKER_BIG_PAGES *v6; // eax
  unsigned int v7; // eax
  signed int v8; // edx
  unsigned int *result; // eax
  signed int v10; // ecx

  ExpTaggedPoolLock = 0;
  PoolTrackTableSize = 1025;
  PoolTrackTableMask = 1023;
  v1 = (_POOL_TRACKER_TABLE *)MmDbgAllocateMemory(a1, 0x4010u, 4u);
  v2 = 16 * PoolTrackTableSize;
  v3 = 16 * PoolTrackTableSize >> 2;
  PoolTrackTable = v1;
  memset(v1, 0, 4 * v3);
  v4 = &v1->Key + v3;
  v5 = v2 & 3;
  memset(v4, 0, v5);
  PoolBigPageTableSize = 4096;
  PoolBigPageTableHash = 4095;
  v6 = (_POOL_TRACKER_BIG_PAGES *)MmDbgAllocateMemory((int *)((char *)v4 + v5), 0xC000u, 4u);
  PoolBigPageTable = v6;
  memset(v6, 0, 12 * PoolBigPageTableSize);
  NonPagedPoolDescriptor.RunningAllocs = 0;
  NonPagedPoolDescriptor.RunningDeAllocs = 0;
  NonPagedPoolDescriptor.TotalPages = 0;
  NonPagedPoolDescriptor.TotalBigPages = 0;
  v7 = (unsigned int)NonPagedPoolDescriptor.ListHeads;
  v8 = 128;
  do
  {
    *(_DWORD *)(v7 + 4) = v7 | 1;
    *(_DWORD *)v7 = v7 | 1;
    v7 += 8;
    --v8;
  }
  while ( v8 );
  result = &ExpSmallNPagedPoolLookasideLists[0].TotalAllocates;
  v10 = 8;
  do
  {
    *(result - 3) = 0;
    *(result - 2) = 0;
    *((_WORD *)result - 2) = 2;
    *result = 0;
    result[1] = 0;
    result += 6;
    --v10;
  }
  while ( v10 );
  return result;
}