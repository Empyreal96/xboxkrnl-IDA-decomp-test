char __fastcall KeInsertQueueApc(int a1, int a2, _KAPC *Apc, void *SystemArgument1, void *SystemArgument2, int Increment)
{
  _KAPC *v6; // esi
  char v7; // bl
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v6 = Apc;
  v7 = 0;
  if ( Apc->Type != 18 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      (int)Apc,
      "(Apc)->Type == ApcObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0xEFu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      (int)Apc,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0xF0u,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  if ( v6->Thread->ApcState.ApcQueueable )
  {
    v6->SystemArgument1 = SystemArgument1;
    v6->SystemArgument2 = SystemArgument2;
    v7 = KiInsertQueueApc(v6, Increment);
  }
  KiUnlockDispatcherDatabase(OldIrql_3);
  return v7;
}