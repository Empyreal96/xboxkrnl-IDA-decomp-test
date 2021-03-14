PSINGLE_LIST_ENTRY __fastcall InterlockedPushEntrySList(PSLIST_HEADER ListHead, PSINGLE_LIST_ENTRY ListEntry)
{
  PSINGLE_LIST_ENTRY v3; // ebx
  unsigned __int64 v4; // rax

  _EBP = ListHead;
  v3 = ListEntry;
  v4 = ListHead->Alignment;
  do
  {
    v3->Next = (_SINGLE_LIST_ENTRY *)v4;
    __asm { cmpxchg8b qword ptr [ebp+0] }
  }
  while ( HIDWORD(v4) != -65537 );
  return (PSINGLE_LIST_ENTRY)v4;
}