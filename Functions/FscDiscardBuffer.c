void __userpurge FscDiscardBuffer(int *a1@<edi>, int a2@<esi>, void *CacheBuffer)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  _FSCACHE_ELEMENT *v7; // esi
  $E339EC3434257F768F3203BB3C26A88D v8; // eax
  _LIST_ENTRY *v9; // edx
  _LIST_ENTRY *v10; // ecx
  _LIST_ENTRY *v11; // ecx
  char OldIrql; // [esp+Fh] [ebp-1h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  FscSetCacheBufferProtection(CacheBuffer, 0, a1);
  v7 = FscElementFromCacheBuffer(v3, v4, a2, CacheBuffer);
  if ( *((_BYTE *)&v7->0 + 1) & 4 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)v7,
      "!Element->DeletePending",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x587u,
      0);
  if ( v7->0 != 1 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)v7,
      "Element->UsageCount == 1",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x588u,
      0);
  *(_WORD *)&v7->0 &= 0xF000u;
  v8 = v7->0;
  v7->CacheExtension = 0;
  if ( v8 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)v7,
      "Element->UsageCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x596u,
      0);
  v9 = v7->ListEntry.Blink;
  v10 = v7->ListEntry.Flink;
  v9->Flink = v10;
  v10->Blink = v9;
  v11 = FscLruList.Flink;
  v7->ListEntry.Flink = FscLruList.Flink;
  v7->ListEntry.Blink = &FscLruList;
  v11->Blink = &v7->ListEntry;
  FscLruList.Flink = &v7->ListEntry;
  if ( !IsListEmpty(&FscWaitingForElementEvent.Header.WaitListHead) )
    KeSetEvent((int)v11, (int)v9, &FscWaitingForElementEvent, 0, 0);
  KfLowerIrql(OldIrql);
}