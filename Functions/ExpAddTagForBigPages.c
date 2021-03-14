signed int __stdcall ExpAddTagForBigPages(void *Va, unsigned int Key, unsigned int NumberOfPages)
{
  unsigned int v3; // esi
  signed int v4; // ebx
  int v5; // edx
  unsigned int v6; // esi
  _POOL_TRACKER_BIG_PAGES *v7; // eax
  _POOL_TRACKER_BIG_PAGES *v8; // ebx
  _POOL_TRACKER_BIG_PAGES *v9; // edi
  _POOL_TRACKER_BIG_PAGES *OldTable; // ST1C_4
  int v11; // edx
  int v12; // ecx
  signed int v13; // esi
  int v14; // ecx
  _POOL_TRACKER_BIG_PAGES *v15; // esi
  char OldIrql; // [esp+1Bh] [ebp-1h]

  while ( 2 )
  {
    v3 = PoolBigPageTableHash & ((unsigned int)Va >> 12);
    v4 = 1;
    OldIrql = KeRaiseIrqlToDpcLevel();
    while ( 1 )
    {
      do
      {
        v5 = 3 * v3;
        if ( (_DWORD)PoolBigPageTable[v3].Va >= 0 )
        {
          v14 = 3 * v3;
          v15 = &PoolBigPageTable[v3];
          if ( (signed int)Va >= 0 )
            RtlAssert(v5, v14, 0, (int)v15, "(LONG_PTR)Va < 0", "d:\\xbox-apr03\\private\\ntos\\ex\\pool.c", 0x5AEu, 0);
          v15->Key = Key;
          v15->Va = Va;
          v15->NumberOfPages = NumberOfPages;
          v13 = 1;
          goto LABEL_15;
        }
        ++v3;
      }
      while ( v3 < PoolBigPageTableSize );
      if ( !v4 )
        break;
      v3 = 0;
      v4 = 0;
    }
    v6 = 12 * PoolBigPageTableSize;
    if ( 24 * PoolBigPageTableSize > 12 * PoolBigPageTableSize )
    {
      v7 = (_POOL_TRACKER_BIG_PAGES *)MmDbgAllocateMemory(0, 24 * PoolBigPageTableSize, 4u);
      v8 = v7;
      if ( v7 )
      {
        v9 = PoolBigPageTable;
        OldTable = PoolBigPageTable;
        DbgPrint(
          (int *)PoolBigPageTable,
          "POOL:grew big table (%p, %p, %p)\n",
          PoolBigPageTable,
          PoolBigPageTableSize,
          v7);
        qmemcpy(v8, v9, v6);
        memset(&v8[PoolBigPageTableSize], 0, v6);
        PoolBigPageTableSize *= 2;
        PoolBigPageTable = v8;
        PoolBigPageTableHash = PoolBigPageTableSize - 1;
        KfLowerIrql(OldIrql);
        MmDbgFreeMemory(v12, v11, OldTable, 0);
        continue;
      }
    }
    break;
  }
  if ( !FirstPrint )
  {
    DbgPrint(0, "POOL:unable to insert big page slot %lx\n", Key);
    FirstPrint = 1;
  }
  v13 = 0;
LABEL_15:
  KfLowerIrql(OldIrql);
  return v13;
}