void __stdcall ExpInsertPoolTracker(unsigned int Key, unsigned int Size)
{
  int v2; // esi
  KIRQL v3; // al
  _POOL_TRACKER_TABLE *v4; // ecx
  int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edi
  int *v11; // edi
  _POOL_TRACKER_TABLE *v12; // ebx
  unsigned int v13; // eax
  int v14; // ecx
  _POOL_TRACKER_TABLE *v15; // esi
  unsigned int v16; // edx
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  _POOL_TRACKER_TABLE *v21; // edi
  unsigned int *v22; // esi
  int v23; // edx
  int v24; // ecx
  _POOL_TRACKER_TABLE *OldTable; // [esp+14h] [ebp-18h]
  unsigned int NewSize; // [esp+18h] [ebp-14h]
  unsigned int OriginalHash; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+20h] [ebp-Ch]
  unsigned int OriginalKey; // [esp+24h] [ebp-8h]
  char OldIrql; // [esp+2Bh] [ebp-1h]

  v2 = 40543 * (HIBYTE(Key) ^ 4 * (BYTE2(Key) ^ 4 * (BYTE1(Key) ^ 4 * (unsigned __int8)Key))) >> 2;
retry:
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = PoolTrackTable;
  OldIrql = v3;
  v5 = v2;
  v6 = PoolTrackTableSize;
  v7 = PoolTrackTableMask & v5;
  v8 = v7;
  while ( 1 )
  {
    v9 = PoolTrackTable[v7].Key;
    if ( v9 == Key || !v9 && v7 != PoolTrackTableSize - 1 )
      break;
    v7 = PoolTrackTableMask & (v7 + 1);
    if ( v7 == v8 )
    {
      v10 = 2 * PoolTrackTableSize - 1;
      NewSize = v10;
      v11 = (int *)(16 * v10);
      if ( (unsigned int)v11 <= 16 * PoolTrackTableSize || PoolTrackTable[PoolTrackTableSize - 1].Key )
        goto overflow;
      v12 = (_POOL_TRACKER_TABLE *)MmDbgAllocateMemory(v11, (unsigned int)v11, 4u);
      if ( !v12 )
      {
LABEL_18:
        v4 = PoolTrackTable;
        v6 = PoolTrackTableSize;
overflow:
        v20 = v6 - 1;
        v4[v20].Key = 1818654287;
        goto EntryFound;
      }
      OldTable = PoolTrackTable;
      DbgPrint(v11, "POOL:grew track table (%p, %p, %p)\n", PoolTrackTable, PoolTrackTableSize, v12);
      memset(v12, 0, (unsigned int)v11);
      v13 = NewSize;
      v14 = NewSize - 2;
      OriginalHash = 0;
      if ( PoolTrackTableSize )
      {
        v28 = 0;
        do
        {
          v15 = &PoolTrackTable[v28];
          v16 = PoolTrackTable[v28].Key;
          OriginalKey = PoolTrackTable[v28].Key;
          if ( v16 )
          {
            v17 = v14 & (40543
                       * (HIBYTE(OriginalKey) ^ 4
                                              * (BYTE2(OriginalKey) ^ 4
                                                                    * (BYTE1(OriginalKey) ^ 4 * (unsigned __int8)v16))) >> 2);
            while ( v12[v17].Key || v17 == v13 - 1 )
            {
              v17 = v14 & (v17 + 1);
              if ( v17 == (v14 & (40543
                                * (HIBYTE(OriginalKey) ^ 4
                                                       * (BYTE2(OriginalKey) ^ 4
                                                                             * (BYTE1(OriginalKey) ^ 4 * (unsigned __int8)v16))) >> 2)) )
              {
                DbgPrint(
                  (int *)v17,
                  "POOL:rehash of track table failed (%p, %p, %p %p)\n",
                  OldTable,
                  PoolTrackTableSize,
                  v12,
                  OriginalKey);
                MmDbgFreeMemory(v19, v18, v12, 0);
                goto LABEL_18;
              }
            }
            v13 = NewSize;
            v21 = &v12[v17];
            v21->Key = v15->Key;
            v22 = &v15->NonPagedAllocs;
            v21 = (_POOL_TRACKER_TABLE *)((char *)v21 + 4);
            v21->Key = *v22;
            ++v22;
            v21 = (_POOL_TRACKER_TABLE *)((char *)v21 + 4);
            v21->Key = *v22;
            v21->NonPagedAllocs = v22[1];
          }
          ++OriginalHash;
          ++v28;
        }
        while ( OriginalHash < PoolTrackTableSize );
      }
      PoolTrackTableMask = NewSize - 2;
      PoolTrackTable = v12;
      PoolTrackTableSize = v13;
      KfLowerIrql(OldIrql);
      MmDbgFreeMemory(v24, v23, OldTable, 0);
      v2 = 40543 * (HIBYTE(Key) ^ 4 * (BYTE2(Key) ^ 4 * (BYTE1(Key) ^ 4 * (unsigned __int8)Key))) >> 2;
      goto retry;
    }
  }
  v20 = v7;
  PoolTrackTable[v20].Key = Key;
EntryFound:
  ++PoolTrackTable[v20].NonPagedAllocs;
  PoolTrackTable[v20].NonPagedBytes += Size;
  KfLowerIrql(OldIrql);
}