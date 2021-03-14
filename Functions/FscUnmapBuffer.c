void __userpurge FscUnmapBuffer(int *a1@<edi>, int a2@<esi>, void *CacheBuffer)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  _FSCACHE_ELEMENT *v7; // esi
  $E339EC3434257F768F3203BB3C26A88D v8; // eax
  char OldIrql; // [esp+1h] [ebp-1h]

  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( *(_BYTE *)((((unsigned int)CacheBuffer >> 10) & 0x3FFFFC) - 0x40000000) & 2 )
    FscSetCacheBufferProtection(CacheBuffer, 0, a1);
  v7 = FscElementFromCacheBuffer(v3, v4, a2, CacheBuffer);
  if ( !(*(_DWORD *)&v7->0 & 0xFF) )
    RtlAssert(
      v5,
      v6,
      a1,
      (int)v7,
      "Element->UsageCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x544u,
      0);
  --*(_BYTE *)&v7->0;
  v8 = v7->0;
  if ( !*(_BYTE *)&v8 )
  {
    v7->0 = ($E339EC3434257F768F3203BB3C26A88D)(*(_DWORD *)&v8 & 0xFFFFF000);
    if ( !IsListEmpty(&FscWaitingForElementEvent.Header.WaitListHead) )
      KeSetEvent(v6, v5, &FscWaitingForElementEvent, 0, 0);
  }
  KfLowerIrql(OldIrql);
}