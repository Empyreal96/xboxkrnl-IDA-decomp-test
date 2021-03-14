_FSCACHE_ELEMENT *__usercall FscAllocateElement@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
  _LIST_ENTRY *i; // esi
  int v4; // esi
  _KTHREAD *v5; // esi
  _FSCACHE_ELEMENT *result; // eax
  int v7; // eax
  _DWORD *v8; // ecx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x275u,
      0);
LABEL_10:
  if ( FscNumberOfCachePages )
  {
    for ( i = FscLruList.Flink; ; i = *(_LIST_ENTRY **)(v4 + 12) )
    {
      if ( i == &FscLruList )
      {
        v5 = thread;
        if ( (_BYTE)dword_8004C5D0 != 2 )
          RtlAssert(
            a1,
            a2,
            (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            (int)thread,
            "KeGetCurrentIrql() == DISPATCH_LEVEL",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x29Fu,
            0);
        v5->WaitIrql = 1;
        v5->WaitNext = 1;
        KeWaitForSingleObject(a2, a1, &FscWaitingForElementEvent, 0, 0, 0, 0);
        KeRaiseIrqlToDpcLevel();
        goto LABEL_10;
      }
      v4 = (int)&i[-2].Blink;
      if ( !*(_BYTE *)(v4 + 8) )
        break;
    }
    v7 = *(_DWORD *)(v4 + 12);
    v8 = *(_DWORD **)(v4 + 16);
    *v8 = v7;
    *(_DWORD *)(v7 + 4) = v8;
    if ( *(_BYTE *)(((*(_DWORD *)(v4 + 8) >> 10) & 0x3FFFFC) - 0x40000000) & 2 )
      RtlAssert(
        a1,
        (int)v8,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        v4,
        "MiGetPteAddress(Element->CacheBuffer)->Hard.Write == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x293u,
        0);
    result = (_FSCACHE_ELEMENT *)v4;
  }
  else
  {
    DbgPrint(
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      "FSCACHE: cache page required by file system, but cache size is zero.\n");
    result = 0;
  }
  return result;
}