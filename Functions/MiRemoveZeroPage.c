unsigned int __usercall MiRemoveZeroPage@<eax>(_MMPFN_BUSY_TYPE BusyType@<ecx>, _MMPTE *TargetPte@<edx>, int *a3@<edi>)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  _DWORD *v5; // esi
  void *v6; // edx
  int v7; // eax
  _MMPTE *v9; // [esp+Ch] [ebp-8h]
  _MMPFN_BUSY_TYPE v10; // [esp+10h] [ebp-4h]

  v9 = TargetPte;
  v10 = BusyType;
  if ( (signed int)BusyType >= 11 )
    RtlAssert(
      (int)TargetPte,
      BusyType,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "BusyType < MmMaximumUsage",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x451u,
      0);
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)TargetPte,
      BusyType,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\pfnsup.c",
      0x453u,
      0);
  v3 = MiRemoveAnyPageFromFreeList(BusyType, (int)TargetPte);
  v4 = v3;
  v5 = (_DWORD *)(4 * v3 - 2080440320);
  *v5 = (v3 << 12) | 0x63;
  v6 = (void *)((v3 - 0x80000) << 12);
  memset(v6, 0, 0x1000u);
  v7 = (v10 << 28) | 0x10000;
  *v5 = v7;
  if ( v10 != 2 )
    *v5 = v7 ^ (v7 ^ ((_DWORD)v9 << 16)) & 0xFFC0000;
  ++*(_DWORD *)(4 * v10 - 2147151552);
  __invlpg(v6);
  return v4;
}