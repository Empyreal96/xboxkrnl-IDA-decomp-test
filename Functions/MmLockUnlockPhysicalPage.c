void __userpurge MmLockUnlockPhysicalPage(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int PhysicalAddress, char UnlockPage)
{
  int v5; // edx
  int v6; // ecx
  _BYTE *v7; // esi
  char OldIrql; // [esp+Bh] [ebp-1h]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      a3,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
      0x3B3u,
      0);
  OldIrql = KeRaiseIrqlToDpcLevel();
  v7 = (_BYTE *)(4 * (PhysicalAddress >> 12) - 2080440320);
  if ( !(*v7 & 1) && PhysicalAddress >> 12 <= MmHighestPhysicalPage )
  {
    if ( *v7 & 1 )
      RtlAssert(
        v5,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        (int)v7,
        "PageFrame->Pte.Hard.Valid == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x3C5u,
        0);
    if ( !(v7[2] & 1) )
      RtlAssert(
        v5,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        (int)v7,
        "PageFrame->Busy.Busy != 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x3C6u,
        0);
    if ( !(*(_DWORD *)v7 & 0xF0000000) )
      RtlAssert(
        v5,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        (int)v7,
        "PageFrame->Busy.BusyType != MmUnknownUsage",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x3C7u,
        0);
    if ( (*(_DWORD *)v7 & 0xF0000000) >= 0xB0000000 )
      RtlAssert(
        v5,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        (int)v7,
        "PageFrame->Busy.BusyType < MmMaximumUsage",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
        0x3C8u,
        0);
    if ( UnlockPage )
    {
      if ( !*(_WORD *)v7 )
        RtlAssert(
          v5,
          v6,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          (int)v7,
          "PageFrame->Busy.LockCount != 0",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x3CBu,
          0);
      *(_WORD *)v7 -= 2;
    }
    else
    {
      if ( (*(_DWORD *)v7 & 0xFFFF) == 65534 )
        RtlAssert(
          v5,
          v6,
          (int *)"d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          (int)v7,
          "PageFrame->Busy.LockCount != MI_LOCK_COUNT_MAXIMUM",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c",
          0x3CEu,
          0);
      *(_WORD *)v7 += 2;
    }
  }
  KfLowerIrql(OldIrql);
}