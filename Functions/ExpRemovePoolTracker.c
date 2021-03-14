void __stdcall ExpRemovePoolTracker(unsigned int Key, unsigned int Size)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  char OldIrql; // [esp+Fh] [ebp-1h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  v2 = PoolTrackTableMask & (40543 * (HIBYTE(Key) ^ 4 * (BYTE2(Key) ^ 4 * (BYTE1(Key) ^ 4 * (unsigned __int8)Key))) >> 2);
  while ( 1 )
  {
    v3 = PoolTrackTable[v2].Key;
    if ( v3 == Key )
      goto EntryFound_0;
    if ( !v3 && v2 != PoolTrackTableSize - 1 )
      break;
    v2 = PoolTrackTableMask & (v2 + 1);
    if ( v2 == (PoolTrackTableMask & (40543
                                    * (HIBYTE(Key) ^ 4 * (BYTE2(Key) ^ 4 * (BYTE1(Key) ^ 4 * (unsigned __int8)Key))) >> 2)) )
    {
      v2 = PoolTrackTableSize - 1;
EntryFound_0:
      v4 = v2;
      PoolTrackTable[v4].NonPagedBytes -= Size;
      ++PoolTrackTable[v4].NonPagedFrees;
      goto LABEL_8;
    }
  }
  DbgPrint((int *)(PoolTrackTableSize - 1), "POOL: Unable to find tracker %lx, table corrupted\n", Key);
LABEL_8:
  KfLowerIrql(OldIrql);
}