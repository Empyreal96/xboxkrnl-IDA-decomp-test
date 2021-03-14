int __fastcall MiRemoveDebuggerPage(_MMPFN_BUSY_TYPE BusyType, _MMPTE *TargetPte)
{
  __int16 v2; // bx
  int i; // edi
  int v4; // esi

  v2 = (signed __int16)TargetPte;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (unsigned __int16)TargetPte,
      BusyType,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x643u,
      0);
  if ( MmDeveloperKitPfnRegion.AvailablePages <= 0 )
    RtlAssert(
      (unsigned __int16)TargetPte,
      BusyType,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "MmDeveloperKitPfnRegion.AvailablePages > 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x64Au,
      0);
  if ( MmNextDefaultPageColor >= 0x20 )
    RtlAssert(
      (unsigned __int16)TargetPte,
      BusyType,
      0,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "MmNextDefaultPageColor < MM_NUMBER_OF_COLORS",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x650u,
      0);
  for ( i = MmNextDefaultPageColor; *(_WORD *)(4 * i - 2147172560) == -2; i = ((_BYTE)i + 1) & 0x1F )
    ;
  v4 = i + 16 * *(unsigned __int16 *)(4 * i - 2147172560);
  MiRemovePageFromFreeList(i + 16 * *(unsigned __int16 *)(4 * i - 2147172560), (unsigned __int16)TargetPte, (int *)i);
  MmNextDefaultPageColor = ((_BYTE)i + 1) & 0x1F;
  *(_DWORD *)(4 * v4 - 2080440320) = (v4 << 12) | 0x63;
  memset((void *)((v4 - 0x80000) << 12), 0, 0x1000u);
  *(_DWORD *)(4 * v4 - 2080440320) = (v2 & 0xFFC | 0xFFFFA001) << 16;
  ++MmAllocatedPagesByUsage[10];
  __invlpg((void *)((v4 - 0x80000) << 12));
  return v4;
}