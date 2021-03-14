int __userpurge NtSetTimerEx@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *TimerHandle, _LARGE_INTEGER *DueTime, void (__stdcall *TimerApcRoutine)(void *, unsigned int, int), char ApcMode, void *TimerContext, char WakeTimer, int Period, char *PreviousState)
{
  int v12; // esi
  KIRQL v13; // al
  int v14; // edx
  _ETIMER *v15; // ecx
  _LIST_ENTRY *v16; // eax
  _LIST_ENTRY *v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  _KTHREAD *v23; // esi
  int v24; // edx
  int v25; // ecx
  _LIST_ENTRY *v26; // ecx
  _LIST_ENTRY *v27; // edx
  int v28; // edx
  _LARGE_INTEGER ExpirationTime; // [esp+4h] [ebp-10h]
  signed int Status; // [esp+Ch] [ebp-8h]
  _ETIMER *ExTimer; // [esp+10h] [ebp-4h]
  char State_3; // [esp+1Fh] [ebp+Bh]
  KIRQL OldIrql_3; // [esp+23h] [ebp+Fh]
  char Dereference; // [esp+33h] [ebp+1Fh]
  char AssociatedApc_3; // [esp+37h] [ebp+23h]

  if ( Period < 0 )
    return -1073741811;
  ExpirationTime.HighPart = (unsigned __int64)DueTime->QuadPart >> 32;
  v12 = (int)*DueTime;
  ExpirationTime.LowPart = DueTime->LowPart;
  Status = ObReferenceObjectByHandle(a1, a2, a3, DueTime->LowPart, TimerHandle, &ExTimerObjectType, (void **)&ExTimer);
  if ( Status >= 0 )
  {
    if ( WakeTimer )
      Status = 1073741861;
    if ( Status >= 0 )
    {
      v13 = KeRaiseIrqlToDpcLevel();
      v15 = ExTimer;
      OldIrql_3 = v13;
      if ( ExTimer->ApcAssociated )
      {
        if ( (_BYTE)dword_8004C5D0 != 2 )
        {
          RtlAssert(
            v14,
            (int)ExTimer,
            (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
            v12,
            "KeGetCurrentIrql() == DISPATCH_LEVEL",
            "d:\\xbox-apr03\\private\\ntos\\ex\\timer.c",
            0x2BFu,
            0);
          v15 = ExTimer;
        }
        v16 = v15->ActiveTimerListEntry.Flink;
        v17 = v15->ActiveTimerListEntry.Blink;
        v17->Flink = v16;
        v16->Blink = v17;
        ExTimer->ApcAssociated = 0;
        KeCancelTimer((int)v17, v14, &ExTimer->KeTimer);
        KeRemoveQueueDpc(v18, v19, (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL", &ExTimer->TimerDpc);
        KeRemoveQueueApc(v20, v21, (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL", &ExTimer->TimerApc);
        Dereference = 1;
      }
      else
      {
        KeCancelTimer((int)ExTimer, v14, &ExTimer->KeTimer);
        Dereference = 0;
      }
      State_3 = ExTimer->KeTimer.Header.SignalState;
      ExTimer->Period = Period;
      if ( TimerApcRoutine )
      {
        v23 = thread;
        KeInitializeApc(
          &ExTimer->TimerApc,
          thread,
          ExpTimerApcRoutine,
          0,
          (void (__stdcall *)(void *, void *, void *))TimerApcRoutine,
          ApcMode,
          TimerContext);
        if ( (_BYTE)dword_8004C5D0 != 2 )
          RtlAssert(
            v24,
            v25,
            (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
            (int)v23,
            "KeGetCurrentIrql() == DISPATCH_LEVEL",
            "d:\\xbox-apr03\\private\\ntos\\ex\\timer.c",
            0x2E6u,
            0);
        v26 = (_LIST_ENTRY *)v23[1].KernelTime;
        ExTimer->ActiveTimerListEntry.Flink = (_LIST_ENTRY *)((char *)&v23[1].MutantListHead + 4);
        ExTimer->ActiveTimerListEntry.Blink = v26;
        v27 = &ExTimer->ActiveTimerListEntry;
        v26->Flink = &ExTimer->ActiveTimerListEntry;
        v23[1].KernelTime = (unsigned int)&ExTimer->ActiveTimerListEntry;
        ExTimer->ApcAssociated = 1;
        KeSetTimerEx((int)&ExTimer->TimerDpc, (int)v27, &ExTimer->KeTimer, ExpirationTime, Period, &ExTimer->TimerDpc);
        AssociatedApc_3 = 1;
      }
      else
      {
        KeSetTimerEx(Period, v22, &ExTimer->KeTimer, (_LARGE_INTEGER)__PAIR__(ExpirationTime.HighPart, v12), Period, 0);
        AssociatedApc_3 = 0;
      }
      KfLowerIrql(OldIrql_3);
      if ( Dereference )
        ObfDereferenceObject(ExTimer, v28);
      if ( !AssociatedApc_3 )
        ObfDereferenceObject(ExTimer, v28);
      if ( PreviousState )
        *PreviousState = State_3;
    }
  }
  return Status;
}