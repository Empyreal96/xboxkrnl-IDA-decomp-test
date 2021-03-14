int __userpurge NtCancelTimer@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *TimerHandle, char *CurrentState)
{
  int v6; // esi
  KIRQL v7; // al
  int v8; // edx
  _ETIMER *v9; // ecx
  _LIST_ENTRY *v10; // eax
  _LIST_ENTRY *v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  char v16; // bl
  int v17; // edx
  char v18; // bl
  _ETIMER *ExTimer; // [esp+4h] [ebp-4h]
  KIRQL OldIrql_3; // [esp+13h] [ebp+Bh]

  v6 = ObReferenceObjectByHandle(a1, a2, a3, a4, TimerHandle, &ExTimerObjectType, (void **)&ExTimer);
  if ( v6 >= 0 )
  {
    v7 = KeRaiseIrqlToDpcLevel();
    v9 = ExTimer;
    OldIrql_3 = v7;
    if ( ExTimer->ApcAssociated )
    {
      if ( (_BYTE)dword_8004C5D0 != 2 )
      {
        RtlAssert(
          v8,
          (int)ExTimer,
          a3,
          v6,
          "KeGetCurrentIrql() == DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\ex\\timer.c",
          0x1EBu,
          0);
        v9 = ExTimer;
      }
      v10 = v9->ActiveTimerListEntry.Flink;
      v11 = v9->ActiveTimerListEntry.Blink;
      v11->Flink = v10;
      v10->Blink = v11;
      ExTimer->ApcAssociated = 0;
      KeCancelTimer((int)v11, v8, &ExTimer->KeTimer);
      KeRemoveQueueDpc(v12, v13, a3, &ExTimer->TimerDpc);
      KeRemoveQueueApc(v14, v15, a3, &ExTimer->TimerApc);
      v16 = 1;
    }
    else
    {
      KeCancelTimer((int)ExTimer, v8, &ExTimer->KeTimer);
      v16 = 0;
    }
    KfLowerIrql(OldIrql_3);
    if ( v16 )
      ObfDereferenceObject(ExTimer, v17);
    v18 = ExTimer->KeTimer.Header.SignalState;
    ObfDereferenceObject(ExTimer, v17);
    if ( CurrentState )
      *CurrentState = v18;
  }
  return v6;
}