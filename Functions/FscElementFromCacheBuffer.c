_FSCACHE_ELEMENT *__userpurge FscElementFromCacheBuffer@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *CacheBuffer)
{
  int v4; // esi
  _FSCACHE_ELEMENT *v5; // esi

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x2C2u,
      0);
  v4 = 4 * (*(_DWORD *)((((unsigned int)CacheBuffer >> 10) & 0x3FFFFC) - 0x40000000) >> 12) - 2080440320;
  if ( !(*(_BYTE *)(v4 + 2) & 1) )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      v4,
      "PageFrame->Busy.Busy != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x2CEu,
      0);
  if ( (*(_DWORD *)v4 & 0xF0000000) != 0x80000000 )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      v4,
      "PageFrame->Busy.BusyType == MmFsCacheUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x2CFu,
      0);
  v5 = &FscElementArray[(*(_DWORD *)v4 >> 17) & 0x7FF];
  if ( ((unsigned int)CacheBuffer ^ *(_DWORD *)&v5->0) & 0xFFFFF000 )
    RtlAssert(
      a1,
      (int)FscElementArray,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      (int)v5,
      "PAGE_ALIGN(Element->CacheBuffer) == PAGE_ALIGN(CacheBuffer)",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x2D3u,
      0);
  return v5;
}