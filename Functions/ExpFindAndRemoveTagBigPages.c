unsigned int __stdcall ExpFindAndRemoveTagBigPages(void *Va)
{
  int *v1; // edi
  unsigned int v2; // esi
  signed int v3; // ebx
  int v4; // edx
  _POOL_TRACKER_BIG_PAGES *v5; // eax
  unsigned int v6; // esi
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v1 = (int *)Va;
  v2 = PoolBigPageTableHash & ((unsigned int)Va >> 12);
  v3 = 1;
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v5 = PoolBigPageTable;
  while ( 1 )
  {
    do
    {
      if ( PoolBigPageTable[v2].Va == v1 )
      {
        if ( (signed int)v1 >= 0 )
        {
          RtlAssert(v4, 3 * v2, v1, v2, "(LONG_PTR)Va < 0", "d:\\xbox-apr03\\private\\ntos\\ex\\pool.c", 0x5D8u, 0);
          v5 = PoolBigPageTable;
        }
        HIBYTE(v5[v2].Va) &= 0x7Fu;
        v6 = PoolBigPageTable[v2].Key;
        goto LABEL_9;
      }
      ++v2;
    }
    while ( v2 < PoolBigPageTableSize );
    if ( !v3 )
      break;
    v2 = 0;
    v3 = 0;
  }
  if ( !FirstPrint )
  {
    DbgPrint(v1, "POOL:unable to find big page slot %lx\n", v1);
    FirstPrint = 1;
  }
  v6 = 541542722;
LABEL_9:
  KfLowerIrql(OldIrql_3);
  return v6;
}