unsigned int __fastcall KiReinsertTreeTimer(_KTIMER *Timer, int a2, _ULARGE_INTEGER DueTime)
{
  bool v3; // zf

  v3 = Timer->Period == 0;
  Timer->Header.Inserted = 1;
  if ( v3 )
    Timer->Header.SignalState = 0;
  while ( KeInterruptTime.High1Time != KeInterruptTime.High2Time )
    _mm_pause();
  if ( (((*(_QWORD *)&KeInterruptTime.LowPart - DueTime.QuadPart) >> 32) & 0x80000000) != 0i64 )
    return KiInsertTimerTable(
             Timer,
             (_LARGE_INTEGER)(*(_QWORD *)&KeInterruptTime.LowPart - DueTime.QuadPart),
             *(_LARGE_INTEGER *)&KeInterruptTime.LowPart);
  Timer->Header.SignalState = 1;
  Timer->Header.Inserted = 0;
  return 0;
}