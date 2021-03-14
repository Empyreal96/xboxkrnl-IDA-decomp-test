int __userpurge FscShrinkCacheSize@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int NumberOfCachePages)
{
  int *v5; // edi
  int *v6; // eax
  unsigned int v8; // esi
  unsigned int v9; // edi
  _FSCACHE_ELEMENT *v10; // eax
  bool v11; // zf
  _KTHREAD *v12; // esi
  _FSCACHE_ELEMENT *v13; // eax
  $E339EC3434257F768F3203BB3C26A88D v14; // ecx
  int *v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  _FSCACHE_ELEMENT *NewElementArray; // [esp+Ch] [ebp-14h]
  int v21; // [esp+10h] [ebp-10h]
  _FSCACHE_ELEMENT *v22; // [esp+14h] [ebp-Ch]
  unsigned int NewIndex; // [esp+18h] [ebp-8h]
  unsigned int NewIndexa; // [esp+18h] [ebp-8h]
  unsigned int Index; // [esp+1Ch] [ebp-4h]
  unsigned int Indexa; // [esp+1Ch] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x121u,
      0);
  v5 = (int *)NumberOfCachePages;
  if ( NumberOfCachePages >= FscNumberOfCachePages )
    RtlAssert(
      a1,
      a2,
      (int *)NumberOfCachePages,
      a4,
      "NumberOfCachePages < FscNumberOfCachePages",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x123u,
      0);
  if ( NumberOfCachePages )
  {
    v6 = ExAllocatePoolWithTag(a1, a2, 20 * NumberOfCachePages, 20 * NumberOfCachePages, 0x41637346u);
    NewElementArray = (_FSCACHE_ELEMENT *)v6;
    if ( !v6 )
      return -1073741670;
    RtlFillMemoryUlong(v6, 20 * NumberOfCachePages, 1819242320);
  }
  else
  {
    NewElementArray = 0;
  }
  NewIndex = FscNumberOfCachePages - NumberOfCachePages;
  while ( 1 )
  {
    v8 = FscNumberOfCachePages;
    Index = FscNumberOfCachePages;
    if ( FscNumberOfCachePages > 0 )
      break;
LABEL_19:
    if ( !NewIndex )
      goto LABEL_24;
    v12 = thread;
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        a1,
        a2,
        v5,
        (int)thread,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x174u,
        0);
    v12->WaitIrql = 0;
    v12->WaitNext = 1;
    KeWaitForSingleObject(a2, a1, &FscWaitingForElementEvent, 0, 0, 0, 0);
    KeRaiseIrqlToDpcLevel();
  }
  v9 = FscNumberOfCachePages;
  while ( 1 )
  {
    v10 = &FscElementArray[v9 - 1];
    a2 = (int)v10->CacheBuffer;
    if ( (_BYTE)a2 )
      goto LABEL_17;
    a1 = 1024;
    if ( a2 & 0x400 )
      goto LABEL_17;
    v8 = (unsigned int)v10->ListEntry.Blink;
    v11 = NewIndex-- == 1;
    v10->0 = ($E339EC3434257F768F3203BB3C26A88D)(a2 | 0x400);
    a2 = (int)&v10->ListEntry;
    a1 = (int)v10->ListEntry.Flink;
    v10->CacheExtension = 0;
    *(_DWORD *)v8 = a1;
    *(_DWORD *)(a1 + 4) = v8;
    v10->ListEntry.Blink = &v10->ListEntry;
    *(_DWORD *)a2 = a2;
    if ( v11 )
      break;
    v8 = Index;
LABEL_17:
    --v8;
    --v9;
    Index = v8;
    if ( v8 <= 0 )
    {
      v5 = (int *)NumberOfCachePages;
      goto LABEL_19;
    }
  }
  v5 = (int *)NumberOfCachePages;
LABEL_24:
  NewIndexa = 0;
  Indexa = 0;
  if ( FscNumberOfCachePages > 0 )
  {
    v21 = 0;
    v22 = NewElementArray;
    do
    {
      v13 = &FscElementArray[v21];
      v14 = FscElementArray[v21].0;
      if ( *((_BYTE *)&v14 + 1) & 4 )
      {
        MiFreeMappedMemory(
          *(_DWORD *)&v14 & 0xFFFFF000,
          a1,
          &MmSystemPteRange,
          (void *)(*(_DWORD *)&v14 & 0xFFFFF000),
          0x1000u);
      }
      else
      {
        qmemcpy(v22, v13, sizeof(_FSCACHE_ELEMENT));
        v15 = (int *)&v22[1];
        a2 = 0;
        v8 = 4 * (*(_DWORD *)(((*(_DWORD *)&v13->0 >> 10) & 0x3FFFFC) - 0x40000000) >> 12) - 2080440320;
        if ( !(*(_BYTE *)(v8 + 2) & 1) )
          RtlAssert(
            a1,
            0,
            v15,
            v8,
            "PageFrame->Busy.Busy != 0",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x1A4u,
            0);
        if ( (*(_DWORD *)v8 & 0xF0000000) != 0x80000000 )
          RtlAssert(
            a1,
            a2,
            v15,
            v8,
            "PageFrame->Busy.BusyType == MmFsCacheUsage",
            "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
            0x1A5u,
            0);
        v5 = (int *)NumberOfCachePages;
        *(_DWORD *)v8 ^= (*(_DWORD *)v8 ^ (NewIndexa++ << 17)) & 0xFFE0000;
        ++v22;
      }
      ++Indexa;
      ++v21;
    }
    while ( Indexa < FscNumberOfCachePages );
  }
  if ( (int *)NewIndexa != v5 )
    RtlAssert(
      a1,
      a2,
      v5,
      v8,
      "NewIndex == NumberOfCachePages",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x1ADu,
      0);
  ExFreePool(FscElementArray);
  FscElementArray = NewElementArray;
  FscNumberOfCachePages = (unsigned int)v5;
  FscBuildElementLruList(v16, v17, v5, v8);
  while ( !IsListEmpty(&FscWaitingForElementEvent.Header.WaitListHead) )
    KeSetEvent(v19, v18, &FscWaitingForElementEvent, 0, 0);
  return 0;
}