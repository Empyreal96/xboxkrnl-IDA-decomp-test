_LIST_ENTRY *__userpurge KeRemoveQueue@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _KQUEUE *Queue, char WaitMode, _LARGE_INTEGER *Timeout)
{
  _KQUEUE *v6; // edi
  _KTHREAD *v7; // esi
  _KQUEUE *v8; // ecx
  _LIST_ENTRY *v9; // ebx
  _LIST_ENTRY *v10; // eax
  _LIST_ENTRY *v11; // edx
  _LIST_ENTRY *v12; // ecx
  _LARGE_INTEGER *v13; // ecx
  _LIST_ENTRY *v14; // ebx
  int v15; // ebx
  _LIST_ENTRY *v16; // ecx
  _LIST_ENTRY *v17; // ecx
  _LIST_ENTRY *result; // eax
  KIRQL v19; // al
  _LIST_ENTRY *v20; // eax
  _LIST_ENTRY *v21; // ecx
  _KWAIT_BLOCK StackWaitBlock; // [esp+Ch] [ebp-28h]
  _LARGE_INTEGER NewTime; // [esp+24h] [ebp-10h]
  _LARGE_INTEGER DueTime; // [esp+2Ch] [ebp-8h]
  _LARGE_INTEGER *OriginalTime; // [esp+3Ch] [ebp+8h]

  v6 = Queue;
  if ( Queue->Header.Type != 4 )
    RtlAssert(
      a1,
      a2,
      (int *)&Queue->Header.Type,
      a3,
      "(Queue)->Header.Type == QueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      0x100u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      (int *)&Queue->Header.Type,
      a3,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      0x101u,
      0);
  v7 = thread;
  if ( thread->WaitNext )
    thread->WaitNext = 0;
  else
    v7->WaitIrql = KeRaiseIrqlToDpcLevel();
  v8 = v7->Queue;
  v7->Queue = Queue;
  if ( Queue == v8 )
  {
    --Queue->CurrentCount;
  }
  else
  {
    v9 = &v7->QueueListEntry;
    if ( v8 )
    {
      v10 = v9->Flink;
      v11 = v7->QueueListEntry.Blink;
      v11->Flink = v9->Flink;
      v10->Blink = v11;
      KiActivateWaiterQueue(v8);
    }
    v12 = Queue->ThreadListHead.Blink;
    v9->Flink = &Queue->ThreadListHead;
    v7->QueueListEntry.Blink = v12;
    v12->Flink = v9;
    Queue->ThreadListHead.Blink = v9;
  }
  v13 = Timeout;
  OriginalTime = Timeout;
  while ( 1 )
  {
    v14 = v6->EntryListHead.Flink;
    if ( v14 != &v6->EntryListHead && v6->CurrentCount < v6->MaximumCount )
    {
      --v6->Header.SignalState;
      ++v6->CurrentCount;
      v20 = v14->Flink;
      v21 = v14->Blink;
      v21->Flink = v14->Flink;
      v20->Blink = v21;
      v14->Flink = 0;
      goto LABEL_36;
    }
    if ( v7->ApcState.KernelApcPending && v7->WaitIrql < 1u )
    {
      ++v6->CurrentCount;
      KiUnlockDispatcherDatabase(v7->WaitIrql);
      goto LABEL_31;
    }
    if ( WaitMode && v7->ApcState.UserApcPending )
    {
      v14 = (_LIST_ENTRY *)192;
      goto LABEL_35;
    }
    v7->WaitStatus = 0;
    v7->WaitBlockList = &StackWaitBlock;
    StackWaitBlock.WaitKey = 0;
    StackWaitBlock.Object = v6;
    StackWaitBlock.WaitType = 1;
    StackWaitBlock.Thread = v7;
    if ( !v13 )
    {
      StackWaitBlock.NextWaitBlock = &StackWaitBlock;
      goto LABEL_26;
    }
    if ( !*(_QWORD *)v13 )
      break;
    StackWaitBlock.NextWaitBlock = &v7->TimerWaitBlock;
    v15 = (int)&v7->Timer;
    *(_DWORD *)(v15 + 8) = (char *)v7 + 176;
    *(_DWORD *)(v15 + 12) = (char *)v7 + 176;
    v7->TimerWaitBlock.NextWaitBlock = &StackWaitBlock;
    if ( !KiInsertTreeTimer(&v7->Timer, (int)&StackWaitBlock, *v13) )
      break;
    DueTime = (_LARGE_INTEGER)v7->Timer.DueTime;
LABEL_26:
    v16 = v6->Header.WaitListHead.Blink;
    StackWaitBlock.WaitListEntry.Flink = &v6->Header.WaitListHead;
    StackWaitBlock.WaitListEntry.Blink = v16;
    v16->Flink = (_LIST_ENTRY *)&StackWaitBlock;
    v6->Header.WaitListHead.Blink = (_LIST_ENTRY *)&StackWaitBlock;
    v7->WaitMode = WaitMode;
    v7->Alertable = 0;
    v7->WaitReason = 15;
    v7->WaitTime = KeTickCount;
    v7->State = 5;
    v17 = KiWaitInListHead.Blink;
    v7->WaitListEntry.Flink = &KiWaitInListHead;
    v7->WaitListEntry.Blink = v17;
    v17->Flink = &v7->WaitListEntry;
    KiWaitInListHead.Blink = &v7->WaitListEntry;
    if ( v7->WaitIrql > 2u )
      RtlAssert(
        (int)&StackWaitBlock,
        (int)v17,
        (int *)&v6->Header.Type,
        (int)v7,
        "Thread->WaitIrql <= DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
        0x1DBu,
        0);
    result = (_LIST_ENTRY *)KiSwapThread();
    v7->WaitReason = 0;
    if ( result != (_LIST_ENTRY *)256 )
      return result;
    if ( Timeout )
      Timeout = KiComputeWaitInterval(OriginalTime, &DueTime, &NewTime);
LABEL_31:
    v19 = KeRaiseIrqlToDpcLevel();
    v13 = Timeout;
    v7->WaitIrql = v19;
    --v6->CurrentCount;
  }
  v14 = (_LIST_ENTRY *)258;
LABEL_35:
  ++v6->CurrentCount;
LABEL_36:
  KiUnlockDispatcherDatabase(v7->WaitIrql);
  return v14;
}