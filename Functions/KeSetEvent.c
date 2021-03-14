int __fastcall KeSetEvent(int a1, int a2, _KEVENT *Event, int Increment, char Wait)
{
  _KEVENT *v5; // esi
  KIRQL v6; // al
  int v7; // edi
  _LIST_ENTRY *v8; // ecx
  _KTHREAD *v9; // eax
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v5 = Event;
  if ( Event->Header.Type && Event->Header.Type != 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "(Event)->Header.Type == NotificationEvent || (Event)->Header.Type == SynchronizationEvent",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x10Au,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x10Bu,
      0);
  v6 = KeRaiseIrqlToDpcLevel();
  v7 = Event->Header.SignalState;
  OldIrql_3 = v6;
  v8 = v5->Header.WaitListHead.Flink;
  if ( v8 == &v5->Header.WaitListHead )
  {
    v5->Header.SignalState = 1;
  }
  else if ( v5->Header.Type && HIWORD(v8[2].Blink) == 1 )
  {
    KiUnwaitThread((_KTHREAD *)v8[1].Flink, LOWORD(v8[2].Blink), Increment);
  }
  else if ( !v7 )
  {
    v5->Header.SignalState = 1;
    KiWaitTest(v5, Increment);
  }
  if ( Wait )
  {
    v9 = thread;
    thread->WaitNext = Wait;
    v9->WaitIrql = OldIrql_3;
  }
  else
  {
    KiUnlockDispatcherDatabase(OldIrql_3);
  }
  return v7;
}