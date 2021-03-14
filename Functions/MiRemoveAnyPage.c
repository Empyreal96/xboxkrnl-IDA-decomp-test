unsigned int __fastcall MiRemoveAnyPage(_MMPFN_BUSY_TYPE BusyType, _MMPTE *TargetPte)
{
  _MMPFN_BUSY_TYPE v2; // edi
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  unsigned int v6; // ebx

  v2 = BusyType;
  v3 = (int)TargetPte;
  if ( (signed int)BusyType >= 11 )
    RtlAssert(
      (int)TargetPte,
      BusyType,
      (int *)BusyType,
      (int)TargetPte,
      "BusyType < MmMaximumUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x40Bu,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)TargetPte,
      BusyType,
      (int *)v2,
      v3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x40Du,
      0);
  v6 = MiRemoveAnyPageFromFreeList(BusyType, (int)TargetPte);
  if ( v2 == 2 )
    RtlAssert(
      v4,
      v5,
      (int *)2,
      v3,
      "BusyType != MmVirtualPageTableUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x41Cu,
      0);
  *(_DWORD *)(4 * v6 - 2080440320) = ((v2 << 12) ^ v3 & 0xFFC | 1) << 16;
  ++*(_DWORD *)(4 * v2 - 2147151552);
  return v6;
}