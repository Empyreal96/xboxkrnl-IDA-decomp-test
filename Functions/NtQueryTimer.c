int __userpurge NtQueryTimer@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *TimerHandle, _TIMER_BASIC_INFORMATION *TimerInformation)
{
  char v6; // bl
  __int64 v7; // kr00_8
  _TIMER_BASIC_INFORMATION *v8; // eax
  int Status; // [esp+0h] [ebp-4h]

  Status = ObReferenceObjectByHandle(a1, a2, a3, a4, TimerHandle, &ExTimerObjectType, &TimerHandle);
  if ( Status >= 0 )
  {
    v6 = *((_BYTE *)TimerHandle + 4);
    while ( KeInterruptTime.High1Time != KeInterruptTime.High2Time )
      _mm_pause();
    v7 = *((_QWORD *)TimerHandle + 2) - *(_QWORD *)&KeInterruptTime.LowPart;
    ObfDereferenceObject(TimerHandle, KeInterruptTime.LowPart);
    v8 = TimerInformation;
    TimerInformation->RemainingTime.HighPart = HIDWORD(v7);
    v8->RemainingTime.LowPart = v7;
    v8->TimerState = v6;
  }
  return Status;
}