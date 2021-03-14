void __fastcall KeSetEventBoostPriority(int a1, int a2, _KEVENT *Event, _KTHREAD **Thread)
{
  _KEVENT *v4; // esi
  _LIST_ENTRY *v5; // ecx
  _KTHREAD *v6; // ecx
  KIRQL OldIrql_3; // [esp+13h] [ebp+Bh]

  v4 = Event;
  if ( Event->Header.Type != 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "Event->Header.Type == SynchronizationEvent",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x17Cu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x17Du,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  v5 = v4->Header.WaitListHead.Flink;
  if ( v5 == &v4->Header.WaitListHead )
  {
    v4->Header.SignalState = 1;
  }
  else
  {
    v6 = (_KTHREAD *)v5[1].Flink;
    if ( Thread )
      *Thread = v6;
    v6->Quantum = v6->ApcState.Process->ThreadQuantum;
    KiUnwaitThread(v6, 0, 1);
  }
  KiUnlockDispatcherDatabase(OldIrql_3);
}