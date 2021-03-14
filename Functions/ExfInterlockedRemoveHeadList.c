PLIST_ENTRY __fastcall ExfInterlockedRemoveHeadList(PLIST_ENTRY ListHead, PKSPIN_LOCK Lock)
{
  unsigned int v2; // et0
  PLIST_ENTRY result; // eax
  _LIST_ENTRY *v4; // edx
  unsigned int v5; // [esp-4h] [ebp-4h]

  v2 = __getcallerseflags();
  v5 = v2;
  _disable();
  result = ListHead->Flink;
  if ( IsListEmpty(ListHead) )
  {
    __writeeflags(v5);
    result = 0;
  }
  else
  {
    v4 = result->Flink;
    ListHead->Flink = result->Flink;
    v4->Blink = ListHead;
    result->Flink = (_LIST_ENTRY *)-1159868161;
    result->Blink = (_LIST_ENTRY *)-1159868161;
    __writeeflags(v5);
  }
  return result;
}