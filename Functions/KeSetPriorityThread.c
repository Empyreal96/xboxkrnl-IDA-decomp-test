int *__fastcall KeSetPriorityThread(int a1, int a2, _KTHREAD *Thread, int Priority)
{
  _KTHREAD *v4; // esi
  KIRQL v5; // al
  int *v6; // edi
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v4 = Thread;
  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x46Bu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x46Cu,
      0);
  if ( !Priority && Thread->BasePriority || Priority > 31 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "((Priority != 0) || (Thread->BasePriority == 0)) && (Priority <= HIGH_PRIORITY)",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x46Eu,
      0);
  if ( dword_8004C604 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeIsExecutingDpc() == FALSE",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x470u,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = (int *)Thread->Priority;
  OldIrql_3 = v5;
  v4->Quantum = v4->ApcState.Process->ThreadQuantum;
  v4->DecrementCount = 0;
  v4->PriorityDecrement = 0;
  KiSetPriorityThread(v4, Priority, v6);
  KiUnlockDispatcherDatabase(OldIrql_3);
  return v6;
}