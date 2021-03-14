_LIST_ENTRY *__stdcall KiInitSystem()
{
  _LIST_ENTRY *v0; // eax
  signed int v1; // ecx
  _LIST_ENTRY *v2; // eax
  signed int v3; // ecx
  _LIST_ENTRY *result; // eax

  v0 = KiDispatcherReadyListHead;
  v1 = 32;
  do
  {
    v0->Blink = v0;
    v0->Flink = v0;
    ++v0;
    --v1;
  }
  while ( v1 );
  KeInitializeDpc(&KiTimerExpireDpc, (void (__stdcall *)(_KDPC *, void *, void *, void *))KiTimerExpiration, 0);
  v2 = KiTimerTableListHead;
  v3 = 32;
  do
  {
    v2->Blink = v2;
    v2->Flink = v2;
    ++v2;
    --v3;
  }
  while ( v3 );
  result = &KiWaitInListHead;
  InitializeListHead(&KiWaitInListHead);
  return result;
}