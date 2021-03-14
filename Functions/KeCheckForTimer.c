void *__stdcall KeCheckForTimer(void *BlockStart, unsigned int BlockSize)
{
  char *v2; // esi
  char *v3; // ebx
  _LIST_ENTRY *v4; // eax
  _LIST_ENTRY *v5; // edi
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]
  unsigned int BlockSizea; // [esp+18h] [ebp+Ch]

  v2 = (char *)BlockStart;
  v3 = (char *)BlockStart + BlockSize;
  BlockSizea = 0;
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v4 = KiTimerTableListHead;
  do
  {
    v5 = v4->Flink;
    while ( v5 != v4 )
    {
      v6 = (unsigned int)&v5[-3];
      v5 = v5->Flink;
      if ( v6 > (unsigned int)(v2 - 40) && v6 < (unsigned int)v3 )
        KeBugCheckEx(0xC7u, 0, v6, (unsigned int)v2, (unsigned int)v3);
      v7 = *(_DWORD *)(v6 + 32);
      if ( v7 )
      {
        if ( v7 > (unsigned int)(v2 - 28) && v7 < (unsigned int)v3 )
          KeBugCheckEx(0xC7u, 1u, v7, (unsigned int)v2, (unsigned int)v3);
        v8 = *(_DWORD *)(v7 + 12);
        if ( v8 >= (unsigned int)v2 && v8 < (unsigned int)v3 )
          KeBugCheckEx(0xC7u, 2u, v8, (unsigned int)v2, (unsigned int)v3);
      }
    }
    BlockSizea += 8;
    ++v4;
  }
  while ( BlockSizea < 0x100 );
  KiUnlockDispatcherDatabase(OldIrql_3);
  return 0;
}