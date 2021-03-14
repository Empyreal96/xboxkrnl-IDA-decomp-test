void __fastcall MiReleasePageOwnership(unsigned int PageFrameNumber, int a2)
{
  unsigned int v2; // edi
  int v3; // edi
  unsigned int v4; // [esp+8h] [ebp-4h]

  v2 = PageFrameNumber;
  v4 = PageFrameNumber;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)PageFrameNumber,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5D5u,
      0);
  if ( v2 > MmHighestPhysicalPage )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v2,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrameNumber <= MM_HIGHEST_PHYSICAL_PAGE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5D7u,
      0);
  v3 = 4 * v2 - 2080440320;
  if ( *(_BYTE *)v3 & 1 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrame->Pte.Hard.Valid == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5DBu,
      0);
  if ( !(*(_BYTE *)(v3 + 2) & 1) )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrame->Busy.Busy != 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5DCu,
      0);
  if ( !(*(_DWORD *)v3 & 0xF0000000) )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrame->Busy.BusyType != MmUnknownUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5DDu,
      0);
  if ( (*(_DWORD *)v3 & 0xF0000000) >= 0xB0000000 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrame->Busy.BusyType < MmMaximumUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5DEu,
      0);
  if ( *(_WORD *)v3 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "PageFrame->Busy.LockCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x5E5u,
      0);
  --*(_DWORD *)(4 * (*(_DWORD *)v3 >> 28) - 2147151552);
  MiInsertPageInFreeList(v4, 1);
}