int __fastcall KiInsertQueue(_KQUEUE *Queue, _LIST_ENTRY *Entry, char Head)
{
  _KQUEUE *v3; // esi
  _LIST_ENTRY *v4; // edi
  _LIST_ENTRY *v5; // eax
  _LIST_ENTRY *v6; // ecx
  _LIST_ENTRY *v7; // edx
  _KTHREAD *v8; // ecx
  _LIST_ENTRY *v9; // eax
  _LIST_ENTRY *v10; // edx
  _LIST_ENTRY *v11; // edx
  _LIST_ENTRY *v12; // esi
  _LIST_ENTRY *v13; // eax
  _LIST_ENTRY *v14; // ecx
  _LIST_ENTRY *v15; // ecx
  int v17; // [esp+Ch] [ebp-4h]

  v3 = Queue;
  v4 = Entry;
  if ( Queue->Header.Type != 4 )
    RtlAssert(
      (int)Entry,
      (int)Queue,
      (int *)Entry,
      (int)Queue,
      "(Queue)->Header.Type == QueueObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\queueobj.c",
      0x2BFu,
      0);
  v17 = v3->Header.SignalState;
  v5 = v3->Header.WaitListHead.Blink;
  if ( v5 == &v3->Header.WaitListHead
    || v3->CurrentCount >= v3->MaximumCount
    || thread->Queue == v3 && thread->WaitReason == 15 )
  {
    v3->Header.SignalState = v17 + 1;
    v13 = &v3->EntryListHead;
    if ( Head )
    {
      v14 = v13->Flink;
      v4->Flink = v13->Flink;
      v4->Blink = v13;
      v14->Blink = v4;
      v13->Flink = v4;
    }
    else
    {
      v15 = v3->EntryListHead.Blink;
      v4->Flink = v13;
      v4->Blink = v15;
      v15->Flink = v4;
      v3->EntryListHead.Blink = v4;
    }
  }
  else
  {
    v6 = v5->Flink;
    v7 = v5->Blink;
    v7->Flink = v5->Flink;
    v6->Blink = v7;
    v8 = (_KTHREAD *)v5[1].Flink;
    v9 = v8->WaitListEntry.Flink;
    v10 = v8->WaitListEntry.Blink;
    v8->WaitStatus = (int)v4;
    v10->Flink = v9;
    v9->Blink = v10;
    ++v3->CurrentCount;
    v8->WaitReason = 0;
    if ( v8->Timer.Header.Inserted == 1 )
    {
      v11 = v8->Timer.TimerListEntry.Flink;
      v12 = v8->Timer.TimerListEntry.Blink;
      v8->Timer.Header.Inserted = 0;
      v12->Flink = v11;
      v11->Blink = v12;
      v8->Timer.TimerListEntry.Flink = 0;
      v8->Timer.TimerListEntry.Blink = 0;
    }
    KiReadyThread(v8);
  }
  return v17;
}