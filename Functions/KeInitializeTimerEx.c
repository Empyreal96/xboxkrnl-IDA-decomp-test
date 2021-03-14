void __stdcall KeInitializeTimerEx(_KTIMER *Timer, _TIMER_TYPE Type)
{
  _KTIMER *v2; // eax

  v2 = Timer;
  Timer->Header.Type = Type + 8;
  Timer->Header.Inserted = 0;
  Timer->Header.Size = 10;
  Timer->Header.SignalState = 0;
  Timer->TimerListEntry.Flink = 0;
  Timer->TimerListEntry.Blink = 0;
  v2->Header.WaitListHead.Blink = &v2->Header.WaitListHead;
  v2->Header.WaitListHead.Flink = &v2->Header.WaitListHead;
  Timer->DueTime.QuadPart = 0i64;
  Timer->Period = 0;
}