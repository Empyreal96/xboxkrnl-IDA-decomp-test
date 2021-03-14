int __userpurge FscGrowCacheSize@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int NumberOfCachePages)
{
  unsigned int v5; // ebx
  int *v6; // eax
  int *v7; // edi
  int v8; // edx
  _FSCACHE_ELEMENT *v10; // esi
  char v11; // al
  unsigned int v12; // ecx
  int *v13; // edi
  unsigned int *v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // esi
  unsigned int v18; // edi
  $B7F78B33515696A32CD218B8D20F0174 *v19; // ebx
  _FSCACHE_ELEMENT *NewElementArray; // [esp+0h] [ebp-8h]
  char *CacheBuffer; // [esp+4h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0xACu,
      0);
  v5 = NumberOfCachePages;
  if ( NumberOfCachePages <= FscNumberOfCachePages )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "NumberOfCachePages > FscNumberOfCachePages",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0xAEu,
      0);
  v6 = ExAllocatePoolWithTag(a1, a2, 20 * NumberOfCachePages, 20 * NumberOfCachePages, 0x41637346u);
  v7 = v6;
  NewElementArray = (_FSCACHE_ELEMENT *)v6;
  if ( !v6 )
    return -1073741670;
  RtlFillMemoryUlong(v6, 20 * NumberOfCachePages, 1819242320);
  CacheBuffer = (char *)MiAllocateMappedMemory(
                          v7,
                          &MmSystemPteRange,
                          MmFsCacheUsage,
                          2u,
                          (NumberOfCachePages - FscNumberOfCachePages) << 12,
                          MiRemoveAnyPage,
                          0);
  if ( !CacheBuffer )
  {
    ExFreePool(v7);
    return -1073741670;
  }
  v10 = FscElementArray;
  v11 = 20 * FscNumberOfCachePages;
  v12 = 20 * FscNumberOfCachePages >> 2;
  qmemcpy(v7, FscElementArray, 4 * v12);
  v14 = &v10->BlockNumber + v12;
  v13 = &v7[v12];
  v15 = v11 & 3;
  qmemcpy(v13, v14, v15);
  v17 = (int)v14 + v15;
  v16 = 0;
  v18 = FscNumberOfCachePages;
  if ( FscNumberOfCachePages < NumberOfCachePages )
  {
    v16 = (int)NewElementArray;
    v19 = &NewElementArray[FscNumberOfCachePages].8;
    do
    {
      v19[-1].0 = 0;
      v19->CacheBuffer = CacheBuffer;
      v17 = 4 * (*(_DWORD *)((((unsigned int)CacheBuffer >> 10) & 0x3FFFFC) - 0x40000000) >> 12) - 2080440320;
      if ( !(*(_BYTE *)(v17 + 2) & 1) )
        RtlAssert(
          v8,
          v16,
          (int *)v18,
          v17,
          "PageFrame->Busy.Busy != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0xE7u,
          0);
      if ( (*(_DWORD *)v17 & 0xF0000000) != 0x80000000 )
        RtlAssert(
          v8,
          v16,
          (int *)v18,
          v17,
          "PageFrame->Busy.BusyType == MmFsCacheUsage",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0xE8u,
          0);
      CacheBuffer += 4096;
      v19 += 5;
      *(_DWORD *)v17 ^= (*(_DWORD *)v17 ^ (v18++ << 17)) & 0xFFE0000;
    }
    while ( v18 < NumberOfCachePages );
    v5 = NumberOfCachePages;
  }
  if ( FscElementArray )
    ExFreePool(FscElementArray);
  FscElementArray = NewElementArray;
  FscNumberOfCachePages = v5;
  FscBuildElementLruList(v8, v16, (int *)v18, v17);
  return 0;
}