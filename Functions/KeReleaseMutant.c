int __fastcall KeReleaseMutant(int a1, int a2, _KMUTANT *Mutant, int Increment, char Abandoned, char Wait)
{
  _KMUTANT *v6; // esi
  KIRQL v7; // al
  _KTHREAD *v8; // edi
  _LIST_ENTRY *v9; // eax
  _LIST_ENTRY *v10; // ecx
  int OldState; // [esp+8h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v6 = Mutant;
  if ( Mutant->Header.Type != 2 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\mutntobj.c",
      (int)Mutant,
      "(Mutant)->Header.Type == MutantObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\mutntobj.c",
      0x8Fu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\mutntobj.c",
      (int)Mutant,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\mutntobj.c",
      0x90u,
      0);
  v7 = KeRaiseIrqlToDpcLevel();
  v8 = thread;
  OldIrql_3 = v7;
  OldState = v6->Header.SignalState;
  if ( Abandoned )
  {
    v6->Header.SignalState = 1;
    v6->Abandoned = 1;
  }
  else
  {
    if ( v6->OwnerThread != thread )
    {
      KiUnlockDispatcherDatabase(v7);
      ExRaiseStatus(v6->Abandoned != 0 ? 128 : -1073741754);
    }
    ++v6->Header.SignalState;
  }
  if ( v6->Header.SignalState == 1 )
  {
    if ( OldState <= 0 )
    {
      v9 = v6->MutantListEntry.Flink;
      v10 = v6->MutantListEntry.Blink;
      v10->Flink = v9;
      v9->Blink = v10;
    }
    v6->OwnerThread = 0;
    if ( v6->Header.WaitListHead.Flink != &v6->Header.WaitListHead )
      KiWaitTest(v6, Increment);
  }
  if ( Wait )
  {
    v8->WaitNext = Wait;
    v8->WaitIrql = OldIrql_3;
  }
  else
  {
    KiUnlockDispatcherDatabase(OldIrql_3);
  }
  return OldState;
}