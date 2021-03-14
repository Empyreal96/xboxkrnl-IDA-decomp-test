void __fastcall KiUnwaitThread(_KTHREAD *Thread, int WaitStatus, int Increment)
{
  _KWAIT_BLOCK *v3; // eax
  _LIST_ENTRY *v4; // edx
  _LIST_ENTRY *v5; // esi
  _LIST_ENTRY *v6; // edx
  _LIST_ENTRY *v7; // esi
  _KQUEUE *v8; // eax
  char v9; // dl
  _KPROCESS *v10; // esi
  int v11; // eax
  char v12; // al
  char v13; // [esp+Bh] [ebp-1h]

  Thread->WaitStatus |= WaitStatus;
  v3 = Thread->WaitBlockList;
  do
  {
    v4 = v3->WaitListEntry.Flink;
    v5 = v3->WaitListEntry.Blink;
    v5->Flink = v3->WaitListEntry.Flink;
    v4->Blink = v5;
    v3 = v3->NextWaitBlock;
  }
  while ( v3 != Thread->WaitBlockList );
  RemoveEntryList(&Thread->WaitListEntry);
  if ( Thread->Timer.Header.Inserted )
  {
    v6 = Thread->Timer.TimerListEntry.Flink;
    v7 = Thread->Timer.TimerListEntry.Blink;
    Thread->Timer.Header.Inserted = 0;
    v7->Flink = v6;
    v6->Blink = v7;
    Thread->Timer.TimerListEntry.Flink = 0;
    Thread->Timer.TimerListEntry.Blink = 0;
  }
  v8 = Thread->Queue;
  if ( v8 )
    ++v8->CurrentCount;
  v9 = Thread->Priority;
  v10 = Thread->ApcState.Process;
  if ( v9 >= 16 )
    goto LABEL_23;
  v13 = Thread->PriorityDecrement;
  if ( !Thread->PriorityDecrement && !Thread->DisableBoost )
  {
    v11 = Increment + Thread->BasePriority;
    if ( v11 > v9 )
    {
      if ( v11 < 16 )
        Thread->Priority = v11;
      else
        Thread->Priority = 15;
    }
  }
  v12 = Thread->BasePriority;
  if ( v12 >= 14 )
  {
LABEL_23:
    Thread->Quantum = v10->ThreadQuantum;
  }
  else
  {
    Thread->Quantum -= 10;
    if ( Thread->Quantum <= 0 )
    {
      Thread->Quantum = v10->ThreadQuantum;
      Thread->Priority += -1 - v13;
      if ( Thread->Priority < v12 )
        Thread->Priority = v12;
      Thread->PriorityDecrement = 0;
    }
  }
  KiReadyThread(Thread);
}