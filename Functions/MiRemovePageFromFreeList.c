void __usercall MiRemovePageFromFreeList(unsigned int PageFrameNumber@<ecx>, int a2@<edx>, int *a3@<edi>)
{
  unsigned int v3; // esi
  _MMPFN *v4; // edi
  unsigned int v5; // eax
  int v6; // esi
  unsigned __int16 v7; // ax
  int v8; // edi
  int v9; // edi
  unsigned __int16 v10; // ax
  unsigned __int16 *v11; // esi
  unsigned __int16 *v12; // esi
  _MMPFNREGION *PfnRegion; // [esp+Ch] [ebp-10h]
  __int16 PackedPfn; // [esp+10h] [ebp-Ch]
  unsigned int Color; // [esp+14h] [ebp-8h]
  _MMPFN *PageFrame; // [esp+18h] [ebp-4h]

  v3 = PageFrameNumber;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      PageFrameNumber,
      a3,
      PageFrameNumber,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x2FCu,
      0);
  if ( v3 > MmHighestPhysicalPage )
    RtlAssert(
      a2,
      PageFrameNumber,
      a3,
      v3,
      "PageFrameNumber <= MM_HIGHEST_PHYSICAL_PAGE",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x2FEu,
      0);
  Color = v3 & 0x1F;
  v4 = (_MMPFN *)(4 * v3 - 2080440320);
  v5 = v3 >> 4;
  v6 = *(_DWORD *)(4 * (v3 >> 14) - 2147172428);
  PackedPfn = v5 & 0xFFFE;
  PageFrame = v4;
  PfnRegion = (_MMPFNREGION *)v6;
  if ( v4->Long & 1 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v4,
      v6,
      "PageFrame->Pte.Hard.Valid == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x306u,
      0);
  if ( *((_BYTE *)&v4->Pte.Hard + 2) & 1 )
    RtlAssert(
      a2,
      PageFrameNumber,
      (int *)v4,
      v6,
      "PageFrame->Busy.Busy == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x307u,
      0);
  v7 = v4->Free.PackedPfnBlink;
  if ( v7 == -2 )
  {
    v11 = (unsigned __int16 *)(v6 + 4 * Color);
    if ( *v11 != PackedPfn )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v4,
        (int)v11,
        "PfnRegion->FreePagesByColor[Color].PackedPfnFlink == PackedPfn",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x320u,
        0);
    *v11 = v4->Free.PackedPfnFlink;
  }
  else
  {
    v8 = 4 * (Color + 16 * (v7 - 32506880));
    if ( *(_BYTE *)v8 & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v8,
        v6,
        "LinkPageFrame->Pte.Hard.Valid == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x312u,
        0);
    if ( *(_BYTE *)(v8 + 2) & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v8,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x313u,
        0);
    if ( *(_WORD *)v8 != PackedPfn )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v8,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Free.PackedPfnFlink == PackedPfn",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x314u,
        0);
    *(_WORD *)v8 = PageFrame->Free.PackedPfnFlink;
    if ( *(_BYTE *)(v8 + 2) & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v8,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x318u,
        0);
    v4 = PageFrame;
  }
  if ( v4->Free.PackedPfnFlink == -2 )
  {
    v12 = &PfnRegion->FreePagesByColor[Color].PackedPfnBlink;
    if ( *v12 != PackedPfn )
      RtlAssert(
        a2,
        Color,
        (int *)v4,
        (int)v12,
        "PfnRegion->FreePagesByColor[Color].PackedPfnBlink == PackedPfn",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x33Cu,
        0);
    *v12 = v4->Free.PackedPfnBlink;
  }
  else
  {
    v9 = 4 * (Color + 16 * (v4->Free.PackedPfnFlink - 32506880));
    if ( *(_BYTE *)v9 & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v9,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Pte.Hard.Valid == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x32Eu,
        0);
    if ( *(_BYTE *)(v9 + 2) & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v9,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x32Fu,
        0);
    if ( *(_WORD *)(v9 + 2) != PackedPfn )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v9,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Free.PackedPfnBlink == PackedPfn",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x330u,
        0);
    v10 = PageFrame->Free.PackedPfnBlink;
    *(_WORD *)(v9 + 2) = v10;
    if ( v10 & 1 )
      RtlAssert(
        a2,
        PageFrameNumber,
        (int *)v9,
        (int)"LinkPageFrame->Busy.Busy == 0",
        "LinkPageFrame->Busy.Busy == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
        0x334u,
        0);
  }
  --PfnRegion->AvailablePages;
  if ( PfnRegion == &MmRetailPfnRegion || MmDeveloperKitMemoryReleased )
    --MmAvailablePages;
}