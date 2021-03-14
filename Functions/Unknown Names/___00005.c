PLIST_ENTRY __fastcall ___00005(PLIST_ENTRY ListHead, PLIST_ENTRY ListEntry, PKSPIN_LOCK Lock)
{
  return ExfInterlockedInsertTailList(ListHead, ListEntry, Lock);
}