int __fastcall KePulseEvent(int a1, int a2, _KEVENT *Event, int Increment, char Wait)
{
  KIRQL v5; // al
  int v6; // edi
  char v7; // bl
  _KTHREAD *v8; // eax

  if ( Event->Header.Type && Event->Header.Type != 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "(Event)->Header.Type == NotificationEvent || (Event)->Header.Type == SynchronizationEvent",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x7Au,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0x7Bu,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = Event->Header.SignalState;
  v7 = v5;
  if ( !v6 && !IsListEmpty(&Event->Header.WaitListHead) )
  {
    Event->Header.SignalState = 1;
    KiWaitTest(Event, Increment);
  }
  Event->Header.SignalState = 0;
  if ( Wait )
  {
    v8 = thread;
    thread->WaitIrql = v7;
    v8->WaitNext = Wait;
  }
  else
  {
    KiUnlockDispatcherDatabase(v7);
  }
  return v6;
}