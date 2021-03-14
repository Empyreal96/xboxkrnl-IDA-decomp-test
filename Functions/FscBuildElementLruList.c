struct _LIST_ENTRY *__usercall FscBuildElementLruList@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  struct _LIST_ENTRY *result; // eax
  unsigned int v5; // esi
  _LIST_ENTRY *v6; // edx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
      0x66u,
      0);
  result = (struct _LIST_ENTRY *)FscElementArray;
  InitializeListHead(&FscLruList);
  if ( FscNumberOfCachePages )
  {
    result = &FscElementArray->ListEntry;
    v5 = FscNumberOfCachePages;
    do
    {
      if ( result[-1].Flink )
      {
        v6 = FscLruList.Blink;
        result->Flink = &FscLruList;
        result->Blink = v6;
        v6->Flink = result;
        FscLruList.Blink = result;
      }
      else
      {
        InsertHeadList(&FscLruList, result);
      }
      result = (struct _LIST_ENTRY *)((char *)result + 20);
      --v5;
    }
    while ( v5 );
  }
  return result;
}