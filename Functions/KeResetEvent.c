int __fastcall KeResetEvent(int a1, int a2, _KEVENT *Event)
{
  KIRQL v3; // al
  int v4; // edi

  if ( Event->Header.Type && Event->Header.Type != 1 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "(Event)->Header.Type == NotificationEvent || (Event)->Header.Type == SynchronizationEvent",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0xC5u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      (int)Event,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\eventobj.c",
      0xC6u,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = Event->Header.SignalState;
  Event->Header.SignalState = 0;
  KiUnlockDispatcherDatabase(v3);
  return v4;
}