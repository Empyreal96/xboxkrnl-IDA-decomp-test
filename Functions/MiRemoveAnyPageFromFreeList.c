unsigned int __fastcall MiRemoveAnyPageFromFreeList(int a1, int a2)
{
  _MMPFNREGION *v2; // ebx
  unsigned int v3; // esi
  int v4; // eax
  unsigned __int16 v5; // ax
  unsigned int result; // eax
  int v7; // ecx
  int v8; // esi
  unsigned __int16 PackedPfn; // [esp+Ch] [ebp-Ch]
  unsigned int Color; // [esp+10h] [ebp-8h]
  unsigned int PageFrameNumber; // [esp+14h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x37Cu,
      0);
  if ( MmAvailablePages <= 0 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "MmAvailablePages > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x383u,
      0);
  v2 = &MmRetailPfnRegion;
  if ( !MmRetailPfnRegion.AvailablePages )
  {
    v2 = &MmDeveloperKitPfnRegion;
    if ( !MmDeveloperKitMemoryReleased )
      RtlAssert(
        a2,
        a1,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0,
        "MmDeveloperKitMemoryReleased",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x38Eu,
        0);
  }
  if ( v2->AvailablePages <= 0 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "PfnRegion->AvailablePages > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x392u,
      0);
  if ( MmNextDefaultPageColor >= 0x20 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0,
      "MmNextDefaultPageColor < MM_NUMBER_OF_COLORS",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x398u,
      0);
  v3 = MmNextDefaultPageColor;
  Color = MmNextDefaultPageColor;
  if ( v2->FreePagesByColor[MmNextDefaultPageColor].PackedPfnFlink == -2 )
  {
    do
    {
      v4 = ((_BYTE)v3 + 1) & 0x1F;
      Color = ((_BYTE)v3 + 1) & 0x1F;
      v3 = ((_BYTE)v3 + 1) & 0x1F;
    }
    while ( v2->FreePagesByColor[v4].PackedPfnFlink == -2 );
  }
  v5 = v2->FreePagesByColor[v3].PackedPfnFlink;
  PackedPfn = v5;
  result = v3 + 16 * v5;
  PageFrameNumber = result;
  if ( result > MmHighestPhysicalPage )
  {
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v3,
      "PageFrameNumber <= MM_HIGHEST_PHYSICAL_PAGE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x3A3u,
      0);
    result = PageFrameNumber;
  }
  v7 = result >> 14;
  if ( *(_MMPFNREGION **)(4 * (result >> 14) - 2147172428) != v2 )
  {
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v3,
      "MI_PFN_REGION(PageFrameNumber) == PfnRegion",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x3A4u,
      0);
    result = PageFrameNumber;
  }
  if ( *(_BYTE *)(4 * result - 2080440320) & 1 )
  {
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v3,
      "PageFrame->Pte.Hard.Valid == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x3A8u,
      0);
    result = PageFrameNumber;
  }
  if ( *(_BYTE *)(4 * result - 2080440318) & 1 )
  {
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v3,
      "PageFrame->Busy.Busy == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x3A9u,
      0);
    result = PageFrameNumber;
  }
  LOWORD(v7) = *(_WORD *)(4 * result - 2080440320);
  if ( (_WORD)v7 == -2 )
  {
    LOWORD(v7) = PackedPfn;
    if ( v2->FreePagesByColor[v3].PackedPfnBlink != PackedPfn )
    {
      RtlAssert(
        a2,
        v7,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        v3,
        "PfnRegion->FreePagesByColor[Color].PackedPfnBlink == PackedPfn",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x3BFu,
        0);
      result = PageFrameNumber;
    }
    v2->FreePagesByColor[v3].PackedPfnBlink = -2;
  }
  else
  {
    v8 = 4 * (Color + 16 * ((unsigned __int16)v7 - 32506880));
    if ( *(_BYTE *)(4 * (Color + 16 * ((unsigned __int16)v7 - 32506880)) + 2) & 1 )
      RtlAssert(
        a2,
        v7,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        v8,
        "NewLinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x3B3u,
        0);
    v7 = Color;
    if ( *(_WORD *)(v8 + 2) != v2->FreePagesByColor[Color].PackedPfnFlink )
      RtlAssert(
        a2,
        Color,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        v8,
        "NewLinkPageFrame->Free.PackedPfnBlink == PfnRegion->FreePagesByColor[Color].PackedPfnFlink",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x3B6u,
        0);
    result = PageFrameNumber;
    *(_WORD *)(v8 + 2) = -2;
    v3 = Color;
  }
  if ( *(_WORD *)(4 * result - 2080440318) != -2 )
  {
    RtlAssert(
      a2,
      v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      v3,
      "PageFrame->Free.PackedPfnBlink == MM_PACKED_PFN_NULL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x3C3u,
      0);
    result = PageFrameNumber;
  }
  v2->FreePagesByColor[v3].PackedPfnFlink = *(_WORD *)(4 * result - 2080440320);
  --v2->AvailablePages;
  MmNextDefaultPageColor = ((_BYTE)v3 + 1) & 0x1F;
  if ( v2 == &MmRetailPfnRegion || MmDeveloperKitMemoryReleased )
    --MmAvailablePages;
  return result;
}