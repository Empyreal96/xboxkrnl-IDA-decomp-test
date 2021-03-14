PLIST_ENTRY __fastcall ExfInterlockedInsertHeadList(PLIST_ENTRY ListHead, PLIST_ENTRY ListEntry, PKSPIN_LOCK Lock)
{
  unsigned int v3; // et0
  _LIST_ENTRY *v4; // eax
  PLIST_ENTRY result; // eax

  v3 = __getcallerseflags();
  _disable();
  v4 = ListHead->Flink;
  ListEntry->Flink = ListHead->Flink;
  ListEntry->Blink = ListHead;
  ListHead->Flink = ListEntry;
  v4->Blink = ListEntry;
  __writeeflags(v3);
  result = (PLIST_ENTRY)((unsigned int)ListHead ^ (unsigned int)v4);
  if ( result )
    result = (PLIST_ENTRY)((unsigned int)ListHead ^ (unsigned int)result);
  return result;
}