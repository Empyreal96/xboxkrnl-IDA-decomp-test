PSINGLE_LIST_ENTRY __fastcall ___00011(PSLIST_HEADER ListHead, PSINGLE_LIST_ENTRY ListEntry)
{
  return InterlockedPushEntrySList(ListHead, ListEntry);
}