unsigned int __fastcall KiInsertTreeTimer(_KTIMER *Timer, int a2, _LARGE_INTEGER Interval)
{
  bool v3; // zf
  int v4; // esi
  unsigned __int64 v6; // kr00_8

  v3 = Timer->Period == 0;
  Timer->Header.Inserted = 1;
  Timer->Header.Absolute = 0;
  if ( v3 )
    Timer->Header.SignalState = 0;
  v4 = Interval.HighPart;
  if ( Interval.HighPart >= 0 )
  {
    while ( KeSystemTime.High1Time != KeSystemTime.High2Time )
      _mm_pause();
    if ( (((unsigned __int64)(*(_QWORD *)&KeSystemTime.LowPart - Interval.QuadPart) >> 32) & 0x80000000) == 0i64 )
    {
      Timer->Header.SignalState = 1;
      Timer->Header.Inserted = 0;
      return 0;
    }
    v6 = *(_QWORD *)&KeSystemTime.LowPart - Interval.QuadPart;
    v4 = v6 >> 32;
    Interval.LowPart = v6;
    Timer->Header.Absolute = 1;
  }
  while ( KeInterruptTime.High1Time != KeInterruptTime.High2Time )
    _mm_pause();
  return KiInsertTimerTable(
           Timer,
           (_LARGE_INTEGER)__PAIR__(v4, Interval.LowPart),
           *(_LARGE_INTEGER *)&KeInterruptTime.LowPart);
}