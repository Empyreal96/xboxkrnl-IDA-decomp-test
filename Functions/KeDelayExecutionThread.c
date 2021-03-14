int __fastcall KeDelayExecutionThread(int a1, int a2, char WaitMode, char Alertable, _LARGE_INTEGER *Interval)
{
  _KTHREAD *v5; // esi
  _LARGE_INTEGER *v6; // ebx
  KIRQL v7; // cl
  int v8; // edi
  int *v9; // edi
  int v10; // edx
  int v11; // ecx
  signed int v12; // eax
  bool v13; // cf
  bool v14; // zf
  _KPROCESS *v15; // eax
  _KQUEUE *v16; // ecx
  _LIST_ENTRY *v17; // ecx
  _LARGE_INTEGER NewTime; // [esp+Ch] [ebp-10h]
  _LARGE_INTEGER DueTime; // [esp+14h] [ebp-8h]

  v5 = thread;
  if ( thread->WaitNext )
    thread->WaitNext = 0;
  else
    v5->WaitIrql = KeRaiseIrqlToDpcLevel();
  v6 = Interval;
  while ( 1 )
  {
    if ( v5->ApcState.KernelApcPending )
    {
      v7 = v5->WaitIrql;
      if ( (unsigned __int8)v7 < 1u )
      {
        KiUnlockDispatcherDatabase(v7);
        goto LABEL_34;
      }
    }
    if ( Alertable )
    {
      if ( v5->Alerted[WaitMode] )
      {
        v5->Alerted[WaitMode] = 0;
        goto LABEL_14;
      }
      if ( WaitMode && v5->ApcState.ApcListHead[1].Flink != &v5->ApcState.ApcListHead[1] )
      {
        v5->ApcState.UserApcPending = 1;
LABEL_37:
        v8 = 192;
LABEL_38:
        KiUnlockDispatcherDatabase(v5->WaitIrql);
        if ( v8 == 192 )
          KiDeliverUserApc();
        return v8;
      }
      if ( v5->Alerted[0] )
      {
        v5->Alerted[0] = 0;
LABEL_14:
        v8 = 257;
        goto LABEL_38;
      }
    }
    else if ( WaitMode && v5->ApcState.UserApcPending )
    {
      goto LABEL_37;
    }
    v5->WaitStatus = 0;
    v5->WaitBlockList = &v5->TimerWaitBlock;
    v5->TimerWaitBlock.NextWaitBlock = &v5->TimerWaitBlock;
    v9 = (int *)&v5->Timer.Header.Type;
    v9[2] = (int)&v5->TimerWaitBlock;
    v9[3] = (int)&v5->TimerWaitBlock;
    if ( KiInsertTreeTimer(&v5->Timer, a2, *v6) )
    {
      v16 = v5->Queue;
      DueTime = (_LARGE_INTEGER)v5->Timer.DueTime;
      if ( v16 )
        KiActivateWaiterQueue(v16);
      v5->Alertable = Alertable;
      v5->WaitMode = WaitMode;
      v5->WaitReason = 4;
      v5->WaitTime = KeTickCount;
      v5->State = 5;
      v17 = KiWaitInListHead.Blink;
      v5->WaitListEntry.Flink = &KiWaitInListHead;
      v5->WaitListEntry.Blink = v17;
      v17->Flink = &v5->WaitListEntry;
      KiWaitInListHead.Blink = &v5->WaitListEntry;
      if ( v5->WaitIrql > 2u )
        RtlAssert(
          v10,
          (int)v17,
          v9,
          (int)v5,
          "Thread->WaitIrql <= DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
          0x15Cu,
          0);
    }
    else
    {
      v12 = v5->Priority;
      if ( v12 < 16 )
      {
        v10 = v5->BasePriority;
        if ( v12 != v10 )
        {
          v5->PriorityDecrement = 0;
          KiSetPriorityThread(v5, v10, v9);
        }
      }
      v8 = 0;
      if ( !dword_8004C5D8 )
      {
        dword_8004C5D8 = (int)KiFindReadyThread(v5->Priority);
        if ( !dword_8004C5D8 )
          goto LABEL_38;
      }
      v13 = v5->WaitIrql < 2u;
      v14 = v5->WaitIrql == 2;
      v15 = v5->ApcState.Process;
      v5->Preempted = 0;
      v5->Quantum = v15->ThreadQuantum;
      if ( !v13 && !v14 )
        RtlAssert(
          v10,
          v11,
          0,
          (int)v5,
          "Thread->WaitIrql <= DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
          0x132u,
          0);
      KiReadyThread(v5);
    }
    v8 = KiSwapThread();
    if ( v8 == 192 )
      KiDeliverUserApc();
    if ( v8 != 256 )
      break;
    v6 = KiComputeWaitInterval(Interval, &DueTime, &NewTime);
LABEL_34:
    v5->WaitIrql = KeRaiseIrqlToDpcLevel();
  }
  if ( v8 == 258 )
    v8 = 0;
  return v8;
}