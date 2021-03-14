int *__fastcall KeWaitForSingleObject(int a1, int a2, void *Object, _KWAIT_REASON WaitReason, char WaitMode, char Alertable, _LARGE_INTEGER *Timeout)
{
  _KTHREAD *v7; // esi
  int v8; // eax
  int *v9; // edi
  int v10; // ebx
  _LIST_ENTRY *v11; // ecx
  _KWAIT_BLOCK *v12; // edx
  _KQUEUE *v13; // ecx
  _LIST_ENTRY *v14; // ecx
  int v15; // ebx
  bool v16; // zf
  _LIST_ENTRY *v17; // eax
  _LIST_ENTRY *v18; // edx
  _KWAIT_BLOCK StackWaitBlock; // [esp+Ch] [ebp-2Ch]
  _LARGE_INTEGER NewTime; // [esp+24h] [ebp-14h]
  _LARGE_INTEGER DueTime; // [esp+2Ch] [ebp-Ch]
  _LARGE_INTEGER *OriginalTime; // [esp+34h] [ebp-4h]

  v7 = thread;
  if ( thread->WaitNext )
    thread->WaitNext = 0;
  else
    v7->WaitIrql = KeRaiseIrqlToDpcLevel();
  OriginalTime = Timeout;
  while ( 1 )
  {
    if ( v7->ApcState.KernelApcPending )
    {
      LOBYTE(a1) = v7->WaitIrql;
      if ( (unsigned __int8)a1 < 1u )
      {
        KiUnlockDispatcherDatabase(a1);
        goto LABEL_40;
      }
    }
    v7->WaitStatus = 0;
    if ( *(_BYTE *)Object == 4 )
      RtlAssert(
        a2,
        a1,
        (int *)Object,
        (int)v7,
        "Objectx->Header.Type != QueueObject",
        "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
        0x3B0u,
        0);
    if ( *(_BYTE *)Object == 2 )
    {
      v8 = *((_DWORD *)Object + 1);
      if ( v8 > 0 || v7 == *((_KTHREAD **)Object + 6) )
      {
        if ( v8 == 0x80000000 )
        {
          KiUnlockDispatcherDatabase(v7->WaitIrql);
          ExRaiseStatus(-1073741423);
        }
        v16 = (*((_DWORD *)Object + 1))-- == 1;
        if ( v16 )
        {
          v16 = *((_BYTE *)Object + 28) == 1;
          *((_DWORD *)Object + 6) = v7;
          if ( v16 )
          {
            *((_BYTE *)Object + 28) = 0;
            v7->WaitStatus = 128;
          }
          v17 = v7->MutantListHead.Blink;
          v18 = v17->Flink;
          *((_DWORD *)Object + 4) = v17->Flink;
          *((_DWORD *)Object + 5) = v17;
          v18->Blink = (_LIST_ENTRY *)((char *)Object + 16);
          v17->Flink = (_LIST_ENTRY *)((char *)Object + 16);
        }
        v9 = (int *)v7->WaitStatus;
        goto NoWait_0;
      }
      goto LABEL_17;
    }
    if ( *((_DWORD *)Object + 1) > 0 )
      break;
LABEL_17:
    v7->WaitBlockList = &StackWaitBlock;
    StackWaitBlock.Object = Object;
    StackWaitBlock.WaitKey = 0;
    StackWaitBlock.WaitType = 1;
    StackWaitBlock.Thread = v7;
    if ( Alertable )
    {
      if ( v7->Alerted[WaitMode] )
      {
        v7->Alerted[WaitMode] = 0;
        goto LABEL_23;
      }
      if ( WaitMode && v7->ApcState.ApcListHead[1].Flink != &v7->ApcState.ApcListHead[1] )
      {
        v7->ApcState.UserApcPending = 1;
LABEL_53:
        v9 = (int *)192;
        goto LABEL_56;
      }
      if ( v7->Alerted[0] )
      {
        v7->Alerted[0] = 0;
LABEL_23:
        v9 = (int *)257;
        goto LABEL_56;
      }
    }
    else if ( WaitMode && v7->ApcState.UserApcPending )
    {
      goto LABEL_53;
    }
    if ( Timeout )
    {
      if ( !*(_QWORD *)Timeout
        || (StackWaitBlock.NextWaitBlock = &v7->TimerWaitBlock,
            v10 = (int)&v7->Timer,
            *(_DWORD *)(v10 + 8) = (char *)v7 + 176,
            *(_DWORD *)(v10 + 12) = (char *)v7 + 176,
            v7->TimerWaitBlock.NextWaitBlock = &StackWaitBlock,
            !KiInsertTreeTimer(&v7->Timer, a2, *Timeout)) )
      {
        v9 = (int *)258;
        goto NoWait_0;
      }
      DueTime = (_LARGE_INTEGER)v7->Timer.DueTime;
    }
    else
    {
      StackWaitBlock.NextWaitBlock = &StackWaitBlock;
    }
    v11 = (_LIST_ENTRY *)*((_DWORD *)Object + 3);
    StackWaitBlock.WaitListEntry.Blink = v11;
    v12 = &StackWaitBlock;
    StackWaitBlock.WaitListEntry.Flink = (_LIST_ENTRY *)((char *)Object + 8);
    v11->Flink = (_LIST_ENTRY *)&StackWaitBlock;
    *((_DWORD *)Object + 3) = &StackWaitBlock;
    v13 = v7->Queue;
    if ( v13 )
      KiActivateWaiterQueue(v13);
    v7->Alertable = Alertable;
    v7->WaitMode = WaitMode;
    v7->WaitReason = WaitReason;
    v7->WaitTime = KeTickCount;
    v7->State = 5;
    v14 = KiWaitInListHead.Blink;
    v7->WaitListEntry.Flink = &KiWaitInListHead;
    v7->WaitListEntry.Blink = v14;
    v14->Flink = &v7->WaitListEntry;
    KiWaitInListHead.Blink = &v7->WaitListEntry;
    if ( v7->WaitIrql > 2u )
      RtlAssert(
        (int)v12,
        (int)v14,
        (int *)Object,
        (int)v7,
        "Thread->WaitIrql <= DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
        0x431u,
        0);
    v15 = KiSwapThread();
    if ( v15 == 192 )
      KiDeliverUserApc();
    if ( v15 != 256 )
      return (int *)v15;
    if ( Timeout )
      Timeout = KiComputeWaitInterval(OriginalTime, &DueTime, &NewTime);
LABEL_40:
    v7->WaitIrql = KeRaiseIrqlToDpcLevel();
  }
  if ( (*(_BYTE *)Object & 7) == 1 )
  {
    *((_DWORD *)Object + 1) = 0;
  }
  else if ( *(_BYTE *)Object == 5 )
  {
    --*((_DWORD *)Object + 1);
  }
  v9 = 0;
NoWait_0:
  KiAdjustQuantumThread(v9, v7);
LABEL_56:
  KiUnlockDispatcherDatabase(v7->WaitIrql);
  if ( v9 == (int *)192 )
    KiDeliverUserApc();
  return v9;
}