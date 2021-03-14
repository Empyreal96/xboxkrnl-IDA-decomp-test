int __userpurge FscMapEmptyBuffer@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FSCACHE_EXTENSION *CacheExtension, unsigned __int64 ByteOffset, void **CacheBuffer)
{
  _FSCACHE_EXTENSION *v7; // edi
  int v8; // edx
  int v9; // ecx
  _FSCACHE_ELEMENT *v10; // eax
  int v11; // edx
  int v12; // ecx
  _FSCACHE_ELEMENT *v13; // esi
  int v14; // edx
  int v15; // ecx
  signed int v16; // esi
  bool v17; // zf
  _LIST_ENTRY *v18; // ecx
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]
  unsigned int BlockNumber_4; // [esp+1Ch] [ebp+10h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x44Au,
      0);
  v7 = CacheExtension;
  if ( ByteOffset >= CacheExtension->PartitionLength.QuadPart )
    RtlAssert(
      a1,
      a2,
      (int *)CacheExtension,
      SHIDWORD(ByteOffset),
      "ByteOffset < (ULONGLONG)CacheExtension->PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x44Bu,
      0);
  if ( ByteOffset & 0xFFF )
    RtlAssert(
      a1,
      a2,
      (int *)CacheExtension,
      SHIDWORD(ByteOffset),
      "BYTE_OFFSET(ByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x44Cu,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  BlockNumber_4 = ByteOffset >> 12;
  v10 = FscLookupElement(v9, v8, v7, BlockNumber_4);
  v13 = v10;
  if ( v10 )
  {
    if ( *((_BYTE *)&v10->0 + 1) & 1 )
      RtlAssert(
        v11,
        v12,
        (int *)v7,
        (int)v10,
        "!Element->ReadInProgress",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x459u,
        0);
    ++*(_BYTE *)&v13->0;
LABEL_18:
    FscSetCacheBufferProtection(v13->CacheBuffer, 1, (int *)v7);
    memset((void *)(*(_DWORD *)&v13->0 & 0xFFFFF000), 0xFFu, 0x1000u);
    *CacheBuffer = (void *)(*(_DWORD *)&v13->0 & 0xFFFFF000);
    v16 = 0;
    goto LABEL_19;
  }
  v13 = FscAllocateElement(v11, v12, 0);
  if ( v13 )
  {
    v13->0 = ($E339EC3434257F768F3203BB3C26A88D)1;
    v17 = (*((_BYTE *)&v13->0 + 1) & 1) == 0;
    v13->BlockNumber = BlockNumber_4;
    v13->CacheExtension = v7;
    if ( !v17 )
      RtlAssert(
        v14,
        v15,
        (int *)v7,
        (int)v13,
        "!Element->ReadInProgress",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x486u,
        0);
    if ( *((_BYTE *)&v13->0 + 1) & 2 )
      RtlAssert(
        v14,
        v15,
        (int *)v7,
        (int)v13,
        "!Element->ReadWaiters",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x487u,
        0);
    v18 = FscLruList.Blink;
    v13->ListEntry.Flink = &FscLruList;
    v13->ListEntry.Blink = v18;
    v18->Flink = &v13->ListEntry;
    FscLruList.Blink = &v13->ListEntry;
    goto LABEL_18;
  }
  v16 = -1073741801;
LABEL_19:
  KfLowerIrql(OldIrql_3);
  return v16;
}