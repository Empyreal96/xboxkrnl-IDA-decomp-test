void __stdcall FscInvalidateIdleBlocks()
{
  KIRQL v0; // al
  _DWORD *v1; // edx
  _LIST_ENTRY *v2; // ecx
  _LIST_ENTRY *v3; // ebx
  int v4; // esi
  bool v5; // zf
  int v6; // eax
  int v7; // ecx
  char OldIrql; // [esp+Bh] [ebp-1h]

  v0 = KeRaiseIrqlToDpcLevel();
  v3 = FscLruList.Blink;
  OldIrql = v0;
  while ( v3 != &FscLruList )
  {
    v4 = (int)&v3[-2].Blink;
    v5 = v3[-1].Flink == 0;
    v3 = v3->Blink;
    if ( v5 )
      break;
    v6 = *(_DWORD *)(v4 + 8);
    if ( !(_BYTE)v6 )
    {
      if ( v6 & 0x400 )
        RtlAssert(
          (int)v1,
          (int)v2,
          (int *)&FscLruList,
          v4,
          "!Element->DeletePending",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x8DEu,
          0);
      *(_DWORD *)(v4 + 4) = 0;
      v1 = *(_DWORD **)(v4 + 16);
      v7 = *(_DWORD *)(v4 + 12);
      *v1 = v7;
      *(_DWORD *)(v7 + 4) = v1;
      v2 = FscLruList.Flink;
      *(_DWORD *)(v4 + 12) = FscLruList.Flink;
      *(_DWORD *)(v4 + 16) = &FscLruList;
      v2->Blink = (_LIST_ENTRY *)(v4 + 12);
      FscLruList.Flink = (_LIST_ENTRY *)(v4 + 12);
      if ( !IsListEmpty(&FscWaitingForElementEvent.Header.WaitListHead) )
        KeSetEvent((int)v2, (int)v1, &FscWaitingForElementEvent, 0, 0);
    }
  }
  KfLowerIrql(OldIrql);
}