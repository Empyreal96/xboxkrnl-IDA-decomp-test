void __userpurge PsTerminateSystemThread(unsigned int a1@<edi>, int a2@<esi>, int ExitStatus)
{
  int v3; // edx
  int v4; // ST10_4
  _ETHREAD *v5; // esi
  int v6; // edx
  int v7; // ecx
  void (__stdcall *v8)(_ETHREAD *, void *, char); // eax
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  _KTHREAD *v16; // eax
  _KAPC_STATE *v17; // ecx
  int v18; // edx
  int v19; // ecx
  _LIST_ENTRY *v20; // edi
  _LIST_ENTRY *v21; // eax
  _LIST_ENTRY *v22; // ecx
  int *v23; // edi
  _LIST_ENTRY *v24; // eax
  int v25; // edx
  int v26; // ecx
  int *v27; // [esp-4h] [ebp-Ch]
  _LIST_ENTRY *FirstEntry; // [esp+10h] [ebp+8h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint((int *)a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v3, v4, (int *)a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c", 0x8Bu, 0);
  }
  v5 = (_ETHREAD *)thread;
  v27 = (int *)a1;
  thread->HasTerminated = 1;
  KfLowerIrql(0);
  if ( v5->UniqueThread && PspCreateThreadNotifyRoutineCount )
  {
    a1 = 0;
    do
    {
      v8 = PspCreateThreadNotifyRoutine[a1 / 4];
      if ( v8 )
        v8(v5, v5->UniqueThread, 0);
      a1 += 4;
    }
    while ( a1 < 0x20 );
  }
  if ( v5->Tcb.Priority < 16 )
    KeSetPriorityThread(v7, v6, &v5->Tcb, 16);
  IoCancelThreadIo((int *)a1, (int)v5, v5);
  ExTimerRundown();
  KeRundownThread(v9, v10, (int *)a1, (int)v5);
  v5->ExitStatus = ExitStatus;
  KeQuerySystemTime(&v5->ExitTime);
  if ( v5->UniqueThread )
  {
    NtClose((int *)a1, v5->UniqueThread);
    v5->UniqueThread = 0;
  }
  --thread->KernelApcDisable;
  KeDisableApcQueuingThread(v12, v11, &v5->Tcb);
  KeForceResumeThread(v14, v13, &v5->Tcb);
  v16 = thread;
  v17 = (_KAPC_STATE *)(thread->KernelApcDisable + 1);
  thread->KernelApcDisable = (unsigned int)v17;
  if ( !v17 )
  {
    v17 = &v16->ApcState;
    if ( (_KAPC_STATE *)v17->ApcListHead[0].Flink != v17 )
    {
      v16->ApcState.KernelApcPending = 1;
      HalRequestSoftwareInterrupt(1);
    }
  }
  v20 = KeFlushQueueApc(v15, (int)v17, (int)v5, &v5->Tcb, 1);
  FirstEntry = v20;
  if ( v20 )
  {
    do
    {
      v21 = v20 - 1;
      v22 = v20[1].Blink;
      v20 = v20->Flink;
      if ( v22 )
        ((void (__stdcall *)(_LIST_ENTRY *))v22)(v21);
      else
        ExFreePool(v21);
    }
    while ( v20 != FirstEntry );
  }
  v23 = v27;
  if ( v5->Tcb.KernelApcDisable )
    RtlAssert(
      v18,
      v19,
      v27,
      (int)v5,
      "Thread->Tcb.KernelApcDisable == 0",
      "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c",
      0xF9u,
      0);
  v24 = KeFlushQueueApc(v18, v19, (int)v5, &v5->Tcb, 0);
  if ( v24 )
    KeBugCheckEx(0x20u, (unsigned int)v24, v5->Tcb.KernelApcDisable, (unsigned __int8)dword_8004C5D0, 0);
  KeTerminateThread(v25, v26, v23, (int)v5);
}