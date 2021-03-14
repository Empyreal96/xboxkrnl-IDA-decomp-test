char __fastcall KeSetTimerEx(int a1, int a2, _KTIMER *Timer, _LARGE_INTEGER DueTime, int Period, _KDPC *Dpc)
{
  _KTIMER *v6; // esi
  int v7; // edx
  _LIST_ENTRY *v8; // eax
  _LIST_ENTRY *v9; // ecx
  int v10; // edx
  signed __int64 v11; // rax
  signed __int64 v12; // kr00_8
  char Inserted; // [esp+Fh] [ebp-1h]
  KIRQL OldIrql_3; // [esp+1Bh] [ebp+Bh]

  v6 = Timer;
  if ( Timer->Header.Type != 8 && Timer->Header.Type != 9 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      (int)Timer,
      "((Timer)->Header.Type == TimerNotificationObject) || ((Timer)->Header.Type == TimerSynchronizationObject)",
      "d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      0xE2u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      (int)Timer,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\timerobj.c",
      0xE3u,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  Inserted = v6->Header.Inserted;
  if ( v6->Header.Inserted )
  {
    v8 = v6->TimerListEntry.Flink;
    v9 = v6->TimerListEntry.Blink;
    v6->Header.Inserted = 0;
    v9->Flink = v8;
    v8->Blink = v9;
    v6->TimerListEntry.Flink = 0;
    v6->TimerListEntry.Blink = 0;
  }
  v6->Header.SignalState = 0;
  v6->Dpc = Dpc;
  v6->Period = Period;
  if ( !KiInsertTreeTimer(v6, v7, DueTime) )
  {
    if ( v6->Header.WaitListHead.Flink != &v6->Header.WaitListHead )
      KiWaitTest(v6, 0);
    if ( Dpc )
    {
      while ( KeSystemTime.High1Time != KeSystemTime.High2Time )
        _mm_pause();
      KeInsertQueueDpc(
        v10,
        KeSystemTime.LowPart,
        (int *)&Dpc->Type,
        v6->Dpc,
        (void *)KeSystemTime.LowPart,
        (void *)KeSystemTime.High1Time);
    }
    if ( Period )
    {
      v11 = -10000i64 * v6->Period;
      v12 = -10000i64 * v6->Period;
      while ( !KiInsertTreeTimer(v6, SHIDWORD(v11), (_LARGE_INTEGER)v12) )
        ;
    }
  }
  KiUnlockDispatcherDatabase(OldIrql_3);
  return Inserted;
}