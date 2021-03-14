int __usercall KeTerminateThread@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _KTHREAD *v4; // esi
  int v5; // edx
  _KQUEUE *v6; // ecx
  _LIST_ENTRY *v7; // eax
  _LIST_ENTRY *v8; // edx
  bool v9; // zf
  _LIST_ENTRY *v10; // eax
  _LIST_ENTRY *v11; // ecx
  _KPROCESS *v12; // eax
  _LIST_ENTRY *v13; // ecx

  if ( (_BYTE)dword_8004C5D0 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == PASSIVE_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x50Eu,
      0);
  v4 = thread;
  KeRaiseIrqlToDpcLevel();
  v6 = v4->Queue;
  if ( v6 )
  {
    v7 = v4->QueueListEntry.Flink;
    v8 = v4->QueueListEntry.Blink;
    v8->Flink = v7;
    v7->Blink = v8;
    KiActivateWaiterQueue(v6);
  }
  v9 = v4->Header.WaitListHead.Flink == &v4->Header.WaitListHead;
  v4->Header.SignalState = 1;
  if ( !v9 )
    KiWaitTest(v4, 0);
  v10 = v4->ThreadListEntry.Flink;
  v11 = v4->ThreadListEntry.Blink;
  v11->Flink = v10;
  v10->Blink = v11;
  v12 = v4->ApcState.Process;
  v4->State = 4;
  --v12->StackCount;
  if ( (_KTHREAD *)BugCheckParameter2 == v4 )
    BugCheckParameter2 = 0;
  v13 = PsReaperListHead.Blink;
  v4[1].MutantListHead.Blink = &PsReaperListHead;
  v4[1].KernelTime = (unsigned int)v13;
  v13->Flink = (_LIST_ENTRY *)((char *)&v4[1].MutantListHead + 4);
  PsReaperListHead.Blink = (_LIST_ENTRY *)((char *)&v4[1].MutantListHead + 4);
  KeInsertQueueDpc(v5, (int)v13, a3, &PsReaperDpc, 0, 0);
  return KiSwapThread();
}