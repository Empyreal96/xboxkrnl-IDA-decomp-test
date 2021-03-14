int *__userpurge KeWaitForMultipleObjects@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int Count, void **Object, _WAIT_TYPE WaitType, _KWAIT_REASON WaitReason, char WaitMode, char Alertable, _LARGE_INTEGER *Timeout, _KWAIT_BLOCK *WaitBlockArray)
{
  _KWAIT_BLOCK *v11; // edi
  _KTHREAD *v12; // esi
  _LARGE_INTEGER *v13; // ebx
  bool v14; // zf
  KIRQL v15; // cl
  unsigned int v16; // eax
  unsigned __int16 *v17; // ebx
  int *v18; // edi
  int v19; // eax
  _LIST_ENTRY *v20; // eax
  _LIST_ENTRY *v21; // edx
  int *v22; // edi
  _KTHREAD *v23; // eax
  unsigned int v24; // eax
  _KWAIT_BLOCK *v25; // ecx
  _KWAIT_BLOCK *i; // eax
  _LIST_ENTRY *v27; // ecx
  _KWAIT_BLOCK **v28; // edx
  _KQUEUE *v29; // ecx
  _LIST_ENTRY *v30; // ecx
  _LARGE_INTEGER NewTime; // [esp+Ch] [ebp-20h]
  _LARGE_INTEGER DueTime; // [esp+14h] [ebp-18h]
  _LARGE_INTEGER *OriginalTime; // [esp+1Ch] [ebp-10h]
  unsigned int Index; // [esp+20h] [ebp-Ch]
  _KWAIT_BLOCK *WaitBlock; // [esp+24h] [ebp-8h]
  char WaitSatisfied; // [esp+2Bh] [ebp-1h]

  v11 = WaitBlockArray;
  if ( !WaitBlockArray )
    RtlAssert(
      a1,
      a2,
      (int *)WaitBlockArray,
      a3,
      "WaitBlockArray != NULL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
      0x1E3u,
      (char *)WaitBlockArray);
  v12 = thread;
  if ( thread->WaitNext )
    thread->WaitNext = 0;
  else
    v12->WaitIrql = KeRaiseIrqlToDpcLevel();
  v13 = Timeout;
  OriginalTime = Timeout;
  while ( 1 )
  {
    v14 = v12->ApcState.KernelApcPending == 0;
    v12->WaitBlockList = v11;
    if ( !v14 )
    {
      v15 = v12->WaitIrql;
      if ( (unsigned __int8)v15 < 1u )
      {
        KiUnlockDispatcherDatabase(v15);
        goto LABEL_67;
      }
    }
    v16 = 0;
    v12->WaitStatus = 0;
    WaitSatisfied = 1;
    Index = 0;
    if ( Count )
      break;
    v25 = WaitBlock;
LABEL_39:
    if ( WaitType == WaitAll && WaitSatisfied )
    {
      v25->NextWaitBlock = WaitBlockArray;
      KiWaitSatisfyAll(v25);
      v22 = (int *)v12->WaitStatus;
      goto NoWait;
    }
    if ( Alertable )
    {
      if ( v12->Alerted[WaitMode] )
      {
        v12->Alerted[WaitMode] = 0;
        goto LABEL_47;
      }
      if ( WaitMode && v12->ApcState.ApcListHead[1].Flink != &v12->ApcState.ApcListHead[1] )
      {
        v12->ApcState.UserApcPending = 1;
LABEL_74:
        v22 = (int *)192;
        goto LABEL_77;
      }
      if ( v12->Alerted[0] )
      {
        v12->Alerted[0] = 0;
LABEL_47:
        v22 = (int *)257;
        goto LABEL_77;
      }
    }
    else if ( WaitMode && v12->ApcState.UserApcPending )
    {
      goto LABEL_74;
    }
    if ( v13 )
    {
      if ( !*(_QWORD *)v13
        || (v25->NextWaitBlock = &v12->TimerWaitBlock,
            WaitBlock = &v12->TimerWaitBlock,
            v12->Timer.Header.WaitListHead.Blink = &v12->Timer.Header.WaitListHead,
            v12->Timer.Header.WaitListHead.Flink = &v12->Timer.Header.WaitListHead,
            !KiInsertTreeTimer(&v12->Timer, a1, *v13)) )
      {
        v22 = (int *)258;
        goto NoWait;
      }
      v25 = WaitBlock;
      DueTime = (_LARGE_INTEGER)v12->Timer.DueTime;
    }
    v25->NextWaitBlock = WaitBlockArray;
    for ( i = WaitBlockArray; ; i = WaitBlock )
    {
      v27 = (_LIST_ENTRY *)i->Object;
      v28 = (_KWAIT_BLOCK **)v27[1].Blink;
      ++v27;
      i->WaitListEntry.Flink = v27;
      i->WaitListEntry.Blink = (_LIST_ENTRY *)v28;
      *v28 = i;
      v27->Blink = &i->WaitListEntry;
      WaitBlock = i->NextWaitBlock;
      if ( WaitBlock == WaitBlockArray )
        break;
    }
    v29 = v12->Queue;
    if ( v29 )
      KiActivateWaiterQueue(v29);
    v12->Alertable = Alertable;
    v12->WaitMode = WaitMode;
    v12->WaitReason = WaitReason;
    v12->WaitTime = KeTickCount;
    v12->State = 5;
    v30 = KiWaitInListHead.Blink;
    v12->WaitListEntry.Flink = &KiWaitInListHead;
    v12->WaitListEntry.Blink = v30;
    v30->Flink = &v12->WaitListEntry;
    KiWaitInListHead.Blink = &v12->WaitListEntry;
    if ( v12->WaitIrql > 2u )
      RtlAssert(
        (int)v28,
        (int)v30,
        (int *)WaitBlockArray,
        (int)v12,
        "Thread->WaitIrql <= DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
        0x2E5u,
        0);
    v22 = (int *)KiSwapThread();
    if ( v22 == (int *)192 )
      KiDeliverUserApc();
    if ( v22 != (int *)256 )
      return v22;
    if ( v13 )
    {
      Timeout = KiComputeWaitInterval(OriginalTime, &DueTime, &NewTime);
      v13 = Timeout;
    }
LABEL_67:
    v11 = WaitBlockArray;
    v12->WaitIrql = KeRaiseIrqlToDpcLevel();
  }
  v17 = &v11->WaitKey;
  while ( 1 )
  {
    v18 = (int *)Object[v16];
    if ( *(_BYTE *)v18 == 4 )
      RtlAssert(
        a1,
        (int)Object,
        v18,
        (int)v12,
        "Objectx->Header.Type != QueueObject",
        "d:\\xbox-apr03\\private\\ntos\\ke\\wait.c",
        0x22Cu,
        0);
    if ( WaitType == 1 )
      break;
    if ( *(_BYTE *)v18 == 2 )
    {
      v23 = (_KTHREAD *)v18[6];
      if ( v12 == v23 && v18[1] == 0x80000000 )
        goto LABEL_30;
      if ( v18[1] > 0 || v12 == v23 )
        goto LABEL_37;
LABEL_36:
      WaitSatisfied = 0;
      goto LABEL_37;
    }
    if ( v18[1] <= 0 )
      goto LABEL_36;
LABEL_37:
    v24 = Index;
    v17[1] = WaitType;
    a1 = (int)(v17 + 2);
    *v17 = v24;
    v16 = v24 + 1;
    v25 = (_KWAIT_BLOCK *)(v17 - 10);
    *((_DWORD *)v17 - 2) = v18;
    *((_DWORD *)v17 - 3) = v12;
    *((_DWORD *)v17 - 1) = v17 + 2;
    v17 += 12;
    Index = v16;
    if ( v16 >= Count )
    {
      v13 = Timeout;
      goto LABEL_39;
    }
  }
  if ( *(_BYTE *)v18 != 2 )
  {
    if ( v18[1] > 0 )
    {
      if ( (*(_BYTE *)v18 & 7) == 1 )
      {
        v18[1] = 0;
      }
      else if ( *(_BYTE *)v18 == 5 )
      {
        --v18[1];
      }
      v22 = (int *)Index;
      goto NoWait;
    }
    goto LABEL_37;
  }
  v19 = v18[1];
  if ( v19 <= 0 && v12 != (_KTHREAD *)v18[6] )
    goto LABEL_37;
  if ( v19 == 0x80000000 )
  {
LABEL_30:
    KiUnlockDispatcherDatabase(v12->WaitIrql);
    ExRaiseStatus(-1073741423);
  }
  v14 = v18[1]-- == 1;
  if ( v14 )
  {
    v14 = *((_BYTE *)v18 + 28) == 1;
    v18[6] = (int)v12;
    if ( v14 )
    {
      *((_BYTE *)v18 + 28) = 0;
      v12->WaitStatus = 128;
    }
    v20 = v12->MutantListHead.Blink;
    v21 = v20->Flink;
    v18[4] = (int)v20->Flink;
    v18[5] = (int)v20;
    v21->Blink = (_LIST_ENTRY *)(v18 + 4);
    v20->Flink = (_LIST_ENTRY *)(v18 + 4);
  }
  v22 = (int *)(Index | v12->WaitStatus);
NoWait:
  KiAdjustQuantumThread(v22, v12);
LABEL_77:
  KiUnlockDispatcherDatabase(v12->WaitIrql);
  if ( v22 == (int *)192 )
    KiDeliverUserApc();
  return v22;
}