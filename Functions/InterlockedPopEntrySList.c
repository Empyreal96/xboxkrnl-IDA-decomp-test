PSINGLE_LIST_ENTRY __fastcall InterlockedPopEntrySList(PSLIST_HEADER ListHead)
{
  unsigned __int64 v2; // rax
  int v3; // ebx

  _EBP = ListHead;
  v2 = ListHead->Alignment;
  do
  {
    if ( !(_DWORD)v2 )
      break;
    v3 = *(_DWORD *)v2;
    __asm { cmpxchg8b qword ptr [ebp+0] }
  }
  while ( HIDWORD(v2) != -65535 );
  return (PSINGLE_LIST_ENTRY)v2;
}