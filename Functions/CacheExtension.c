void __stdcall FscInvalidateBlocks(_FSCACHE_EXTENSION *CacheExtension, unsigned int BlockNumber, unsigned int EndingBlockNumber)
{
  KIRQL v3; // al
  _DWORD *v4; // edx
  _LIST_ENTRY *v5; // ecx
  _LIST_ENTRY *v6; // ebx
  int v7; // esi
  _FSCACHE_EXTENSION *v8; // eax
  int v9; // eax
  int v10; // ecx
  char OldIrql; // [esp+Bh] [ebp-1h]

  v3 = KeRaiseIrqlToDpcLevel();
  v6 = FscLruList.Blink;
  OldIrql = v3;
  while ( v6 != &FscLruList )
  {
    v7 = (int)&v6[-2].Blink;
    v8 = (_FSCACHE_EXTENSION *)v6[-1].Flink;
    v6 = v6->Blink;
    if ( !v8 )
      break;
    if ( v8 == CacheExtension && *(_DWORD *)v7 >= BlockNumber && *(_DWORD *)v7 <= EndingBlockNumber )
    {
      v9 = *(_DWORD *)(v7 + 8);
      if ( !(_BYTE)v9 )
      {
        if ( v9 & 0x400 )
          RtlAssert(
            (int)v4,
            (int)v5,
            (int *)&FscLruList,
            v7,
            "!Element->DeletePending",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x84Eu,
            0);
        if ( *(_BYTE *)(v7 + 8) )
          RtlAssert(
            (int)v4,
            (int)v5,
            (int *)&FscLruList,
            v7,
            "Element->UsageCount == 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x84Fu,
            0);
        *(_DWORD *)(v7 + 4) = 0;
        v4 = *(_DWORD **)(v7 + 16);
        v10 = *(_DWORD *)(v7 + 12);
        *v4 = v10;
        *(_DWORD *)(v10 + 4) = v4;
        v5 = FscLruList.Flink;
        *(_DWORD *)(v7 + 12) = FscLruList.Flink;
        *(_DWORD *)(v7 + 16) = &FscLruList;
        v5->Blink = (_LIST_ENTRY *)(v7 + 12);
        FscLruList.Flink = (_LIST_ENTRY *)(v7 + 12);
        if ( !IsListEmpty(&FscWaitingForElementEvent.Header.WaitListHead) )
          KeSetEvent((int)v5, (int)v4, &FscWaitingForElementEvent, 0, 0);
      }
    }
  }
  KfLowerIrql(OldIrql);
}