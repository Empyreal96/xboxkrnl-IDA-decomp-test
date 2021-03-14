void __stdcall KeInitializeThread(_KTHREAD *Thread, void *KernelStack, unsigned int KernelStackSize, unsigned int TlsDataSize, void (__stdcall *SystemRoutine)(void (__stdcall *)(void *), void *), void (__stdcall *StartRoutine)(void *), void *StartContext, _KPROCESS *Process)
{
  _KTHREAD *v8; // esi
  _KWAIT_BLOCK *v9; // eax
  char v10; // al
  KIRQL v11; // al
  _LIST_ENTRY *v12; // ecx

  v8 = Thread;
  InitializeListHead(&Thread->Header.WaitListHead);
  v8->MutantListHead.Blink = &v8->MutantListHead;
  v8->MutantListHead.Flink = &v8->MutantListHead;
  v8->ApcState.ApcListHead[0].Blink = v8->ApcState.ApcListHead;
  v8->ApcState.ApcListHead[0].Flink = v8->ApcState.ApcListHead;
  v8->ApcState.ApcListHead[1].Blink = &v8->ApcState.ApcListHead[1];
  v8->ApcState.ApcListHead[1].Flink = &v8->ApcState.ApcListHead[1];
  Thread->Header.Type = 6;
  Thread->Header.Size = 68;
  Thread->ApcState.Process = Process;
  Thread->ApcState.ApcQueueable = 1;
  KeInitializeApc(
    &Thread->SuspendApc,
    Thread,
    KiSuspendNop,
    0,
    (void (__stdcall *)(void *, void *, void *))KiSuspendThread,
    0,
    0);
  KeInitializeSemaphore(&Thread->SuspendSemaphore, 0, 2);
  KeInitializeTimerEx(&Thread->Timer, 0);
  v9 = &Thread->TimerWaitBlock;
  v9->Object = &Thread->Timer;
  v9->WaitKey = 258;
  v9->WaitType = 1;
  v9->Thread = Thread;
  v9->WaitListEntry.Flink = &Thread->Timer.Header.WaitListHead;
  v9->WaitListEntry.Blink = &Thread->Timer.Header.WaitListHead;
  Thread->StackBase = KernelStack;
  Thread->StackLimit = (char *)KernelStack - KernelStackSize;
  KiInitializeContextThread(Thread, TlsDataSize, SystemRoutine, StartRoutine, StartContext);
  v10 = Process->BasePriority;
  Thread->BasePriority = v10;
  Thread->Priority = v10;
  Thread->Quantum = Process->ThreadQuantum;
  Thread->State = 0;
  Thread->DisableBoost = Process->DisableBoost;
  v11 = KeRaiseIrqlToDpcLevel();
  v12 = Process->ThreadListHead.Blink;
  Thread->ThreadListEntry.Blink = v12;
  Thread->ThreadListEntry.Flink = &Process->ThreadListHead;
  v12->Flink = &Thread->ThreadListEntry;
  Process->ThreadListHead.Blink = &Thread->ThreadListEntry;
  ++Process->StackCount;
  KiUnlockDispatcherDatabase(v11);
}