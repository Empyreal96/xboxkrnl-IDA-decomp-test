_FSCACHE_ELEMENT *__fastcall FscLookupElement(int a1, int a2, _FSCACHE_EXTENSION *CacheExtension, unsigned int BlockNumber)
{
  _LIST_ENTRY *i; // esi
  int v5; // esi
  _DWORD *v6; // ecx
  _DWORD *v8; // edx
  int v9; // ecx
  _LIST_ENTRY *v10; // ecx

  for ( i = FscLruList.Blink; ; i = *(_LIST_ENTRY **)(v5 + 16) )
  {
    if ( i == &FscLruList )
      return 0;
    v5 = (int)&i[-2].Blink;
    if ( *(_DWORD *)v5 == BlockNumber && *(_FSCACHE_EXTENSION **)(v5 + 4) == CacheExtension )
      break;
    if ( !*(_DWORD *)(v5 + 4) )
      return 0;
    v6 = *(_DWORD **)(v5 + 16);
    if ( *v6 != v5 + 12 )
      RtlAssert(
        a2,
        (int)v6,
        (int *)&FscLruList,
        v5,
        "Element->ListEntry.Blink->Flink == &Element->ListEntry",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x253u,
        0);
  }
  v8 = *(_DWORD **)(v5 + 16);
  v9 = *(_DWORD *)(v5 + 12);
  *v8 = v9;
  *(_DWORD *)(v9 + 4) = v8;
  v10 = FscLruList.Blink;
  *(_DWORD *)(v5 + 12) = &FscLruList;
  *(_DWORD *)(v5 + 16) = v10;
  v10->Flink = (_LIST_ENTRY *)(v5 + 12);
  FscLruList.Blink = (_LIST_ENTRY *)(v5 + 12);
  return (_FSCACHE_ELEMENT *)v5;
}