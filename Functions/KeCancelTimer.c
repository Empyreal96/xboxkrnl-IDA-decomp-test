char __fastcall KeCancelTimer(int a1, int a2, _KTIMER *Timer)
{
  _KTIMER *v3; // esi
  KIRQL v4; // al
  _LIST_ENTRY *v5; // edx
  _LIST_ENTRY *v6; // edi
  char Inserted_3; // [esp+17h] [ebp+Bh]

  v3 = Timer;
  if ( Timer->Header.Type != 8 && Timer->Header.Type != 9 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      (int)Timer,
      "((Timer)->Header.Type == TimerNotificationObject) || ((Timer)->Header.Type == TimerSynchronizationObject)",
      "d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      0x75u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      (int)Timer,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      0x76u,
      0);
  v4 = KeRaiseIrqlToDpcLevel();
  Inserted_3 = Timer->Header.Inserted;
  if ( v3->Header.Inserted )
  {
    v5 = v3->TimerListEntry.Flink;
    v6 = v3->TimerListEntry.Blink;
    v3->Header.Inserted = 0;
    v6->Flink = v5;
    v5->Blink = v6;
    v3->TimerListEntry.Flink = 0;
    v3->TimerListEntry.Blink = 0;
  }
  KiUnlockDispatcherDatabase(v4);
  return Inserted_3;
}