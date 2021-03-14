void __fastcall MiInsertPageInFreeList(unsigned int PageFrameNumber, char InsertAtHeadList)
{
  unsigned int v2; // esi
  int *v3; // edi
  _MMPFNREGION *v4; // esi
  int v5; // esi
  int v6; // ecx
  _MMPFNREGION *PfnRegion; // [esp+Ch] [ebp-10h]
  int Color; // [esp+10h] [ebp-Ch]
  int PackedPfn; // [esp+14h] [ebp-8h]
  char v10; // [esp+18h] [ebp-4h]

  v10 = InsertAtHeadList;
  v2 = PageFrameNumber;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      InsertAtHeadList,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      PageFrameNumber,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x243u,
      0);
  if ( v2 > MmHighestPhysicalPage )
    RtlAssert(
      InsertAtHeadList,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v2,
      "PageFrameNumber <= MM_HIGHEST_PHYSICAL_PAGE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x245u,
      0);
  Color = v2 & 0x1F;
  PackedPfn = (v2 >> 4) & 0xFFFE;
  if ( ((v2 >> 4) & 0xFFFE) == -2 )
    RtlAssert(
      InsertAtHeadList,
      PageFrameNumber,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v2,
      "PackedPfn != MM_PACKED_PFN_NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x24Fu,
      0);
  v3 = (int *)(4 * v2 - 2080440320);
  v4 = *(_MMPFNREGION **)(4 * (v2 >> 14) - 2147172428);
  PfnRegion = v4;
  v5 = (int)&v4->FreePagesByColor[Color];
  v6 = *(_DWORD *)v5;
  *v3 = *(_DWORD *)v5;
  if ( *(_WORD *)v5 == -2 )
  {
    if ( *(_WORD *)v3 != -2 )
      RtlAssert(
        InsertAtHeadList,
        v6,
        v3,
        v5,
        "PageFrame->Free.PackedPfnFlink == MM_PACKED_PFN_NULL",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x281u,
        0);
    if ( *((_WORD *)v3 + 1) != -2 )
      RtlAssert(
        InsertAtHeadList,
        v6,
        v3,
        v5,
        "PageFrame->Free.PackedPfnBlink == MM_PACKED_PFN_NULL",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x282u,
        0);
    *(_WORD *)(v5 + 2) = PackedPfn;
    *(_WORD *)v5 = PackedPfn;
  }
  else
  {
    LOWORD(v6) = PackedPfn;
    if ( v10 )
    {
      *((_WORD *)v3 + 1) = -2;
      *(_WORD *)v5 = PackedPfn;
      v5 = 4 * (Color + 16 * (*(unsigned __int16 *)v3 - 32506880));
      if ( *(_WORD *)(4 * (Color + 16 * (*(unsigned __int16 *)v3 - 32506880)) + 2) != -2 )
        RtlAssert(
          InsertAtHeadList,
          v6,
          v3,
          v5,
          "OldLinkPageFrame->Free.PackedPfnBlink == MM_PACKED_PFN_NULL",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x269u,
          0);
      *(_WORD *)(v5 + 2) = PackedPfn;
    }
    else
    {
      *(_WORD *)v3 = -2;
      *(_WORD *)(v5 + 2) = PackedPfn;
      v5 = 4 * (Color + 16 * (*((unsigned __int16 *)v3 + 1) - 32506880));
      if ( *(_WORD *)v5 != -2 )
        RtlAssert(
          InsertAtHeadList,
          v6,
          v3,
          v5,
          "OldLinkPageFrame->Free.PackedPfnFlink == MM_PACKED_PFN_NULL",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
          0x274u,
          0);
      *(_WORD *)v5 = PackedPfn;
    }
    if ( *(_BYTE *)(v5 + 2) & 1 )
      RtlAssert(
        InsertAtHeadList,
        v6,
        v3,
        v5,
        "OldLinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x278u,
        0);
  }
  if ( *(_BYTE *)v3 & 1 )
    RtlAssert(
      InsertAtHeadList,
      v6,
      v3,
      v5,
      "PageFrame->Pte.Hard.Valid == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x28Du,
      0);
  if ( *((_BYTE *)v3 + 2) & 1 )
    RtlAssert(
      InsertAtHeadList,
      v6,
      v3,
      v5,
      "PageFrame->Busy.Busy == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x28Eu,
      0);
  ++PfnRegion->AvailablePages;
  if ( PfnRegion == &MmRetailPfnRegion || MmDeveloperKitMemoryReleased )
    ++MmAvailablePages;
}