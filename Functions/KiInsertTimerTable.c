unsigned int __thiscall KiInsertTimerTable(_KTIMER *Timer, _LARGE_INTEGER Interval, _LARGE_INTEGER CurrentTime)
{
  _KTIMER *v3; // esi
  _LIST_ENTRY *v4; // ecx
  _LIST_ENTRY *v5; // eax
  unsigned int v6; // edx
  _LIST_ENTRY *v7; // edx
  _LIST_ENTRY *v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // edx
  _LIST_ENTRY *v11; // edi
  bool v12; // cf
  bool v13; // zf
  _LIST_ENTRY *v14; // edx
  unsigned int v16; // edi
  bool v17; // cf
  _LIST_ENTRY *v18; // ecx
  _LIST_ENTRY *v19; // edx
  unsigned int SearchCount_4; // [esp+20h] [ebp+14h]

  v3 = Timer;
  v4 = (_LIST_ENTRY *)(8 * KiComputeTimerTableIndex(Interval.QuadPart, CurrentTime.QuadPart, (int)Timer) - 2147152128);
  v5 = v4->Blink;
  v6 = 0;
  if ( v5 == v4 )
  {
LABEL_2:
    v7 = v4->Flink;
    v8 = &v3->TimerListEntry;
    v3->TimerListEntry.Flink = v4->Flink;
    v3->TimerListEntry.Blink = v4;
    v7->Blink = &v3->TimerListEntry;
    v4->Flink = &v3->TimerListEntry;
    while ( KeInterruptTime.High1Time != KeInterruptTime.High2Time )
      _mm_pause();
    v16 = v3->DueTime.HighPart;
    v17 = v16 < KeInterruptTime.High1Time;
    if ( v16 == KeInterruptTime.High1Time )
    {
      if ( v3->DueTime.LowPart <= KeInterruptTime.LowPart )
        goto LABEL_19;
      v17 = v16 < KeInterruptTime.High1Time;
    }
    if ( !v17 )
      return (unsigned __int8)v3->Header.Inserted;
LABEL_19:
    v18 = v8->Flink;
    v19 = v3->TimerListEntry.Blink;
    v3->Header.Inserted = 0;
    v19->Flink = v18;
    v18->Blink = v19;
    v8->Flink = 0;
    v3->TimerListEntry.Blink = 0;
    v3->Header.SignalState = 1;
    return (unsigned __int8)v3->Header.Inserted;
  }
  while ( 1 )
  {
    v9 = v6 + 1;
    SearchCount_4 = v9;
    if ( v9 > KiMaximumSearchCount )
      KiMaximumSearchCount = v9;
    v10 = v3->DueTime.HighPart;
    v11 = v5[-1].Blink;
    v12 = v10 < (unsigned int)v11;
    v13 = v10 == (_DWORD)v11;
    if ( (_LIST_ENTRY *)v10 == v11 )
    {
      if ( (_LIST_ENTRY *)v3->DueTime.LowPart >= v5[-1].Flink )
        break;
      v12 = v10 < (unsigned int)v11;
      v13 = v10 == (_DWORD)v11;
    }
    if ( !v12 && !v13 )
      break;
    v5 = v5->Blink;
    if ( v5 == v4 )
      goto LABEL_2;
    v6 = SearchCount_4;
  }
  v14 = v5->Flink;
  v3->TimerListEntry.Blink = v5;
  v3->TimerListEntry.Flink = v14;
  v14->Blink = &v3->TimerListEntry;
  v5->Flink = &v3->TimerListEntry;
  return 1;
}