char __userpurge KeRemoveQueueApc@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KAPC *Apc)
{
  _KAPC *v4; // esi
  _KTHREAD *v5; // edi
  int v6; // edx
  _LIST_ENTRY *v7; // ecx
  _LIST_ENTRY *v8; // eax
  int *v10; // [esp-4h] [ebp-10h]
  char Inserted; // [esp+Bh] [ebp-1h]
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v4 = Apc;
  if ( Apc->Type != 18 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Apc,
      "(Apc)->Type == ApcObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0x130u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Apc,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0x131u,
      0);
  v10 = a3;
  v5 = Apc->Thread;
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v6,
      (int)v7,
      (int *)&v5->Header.Type,
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0x13Au,
      0);
  Inserted = v4->Inserted;
  if ( v4->Inserted )
  {
    v8 = v4->ApcListEntry.Flink;
    v7 = v4->ApcListEntry.Blink;
    v4->Inserted = 0;
    v7->Flink = v8;
    v8->Blink = v7;
    LOBYTE(v7) = v4->ApcMode;
    if ( v5->ApcState.ApcListHead[(char)v7].Flink == &v5->ApcState.ApcListHead[(char)v7] )
    {
      if ( (_BYTE)v7 )
        v5->ApcState.UserApcPending = 0;
      else
        v5->ApcState.KernelApcPending = 0;
    }
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v6,
      (int)v7,
      v10,
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0x157u,
      0);
  KiUnlockDispatcherDatabase(OldIrql_3);
  return Inserted;
}