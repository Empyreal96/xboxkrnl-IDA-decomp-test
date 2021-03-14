int __userpurge PsCreateSystemThreadEx@<eax>(int *a1@<edi>, int a2@<esi>, void **ThreadHandle, unsigned int ThreadExtensionSize, unsigned int KernelStackSize, unsigned int TlsDataSize, void **ThreadId, void (__stdcall *StartRoutine)(void *), void *StartContext, char CreateSuspended, char DebuggerThread, void (__stdcall *SystemRoutine)(void (__stdcall *)(void *), void *))
{
  int v12; // edx
  int v13; // ST20_4
  int result; // eax
  int v15; // edx
  _LIST_ENTRY *v16; // ecx
  unsigned int v17; // esi
  int *v18; // eax
  int v19; // edx
  int v20; // esi
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  unsigned int v27; // esi
  void (__stdcall *v28)(_ETHREAD *, void *, char); // eax
  int v29; // edx
  int v30; // ecx
  _ETHREAD *Thread; // [esp+8h] [ebp-4h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v12, v13, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\create.c", 0xBEu, 0);
  }
  Thread = 0;
  result = ObCreateObject(&PsThreadObjectType, 0, ThreadExtensionSize + 320, (void **)&Thread);
  if ( result >= 0 )
  {
    v15 = ThreadExtensionSize + 320;
    memset(Thread, 0, ThreadExtensionSize + 320);
    InitializeListHead(&Thread->IrpList);
    Thread->ReaperListEntry.Blink = &Thread->ReaperListEntry;
    v16 = Thread->ReaperListEntry.Blink;
    Thread->ReaperListEntry.Flink = v16;
    v17 = (KernelStackSize + 4095) & 0xFFFFF000;
    if ( v17 < 0x3000 )
      v17 = 12288;
    if ( v17 <= TlsDataSize )
      RtlAssert(
        v15,
        (int)v16,
        0,
        v17,
        "KernelStackSize > TlsDataSize",
        "d:\\xbox-apr03\\private\\ntos\\ps\\create.c",
        0xEAu,
        0);
    if ( v17 - TlsDataSize <= 0x2BF0 )
      RtlAssert(
        v15,
        (int)v16,
        0,
        v17,
        "(KernelStackSize - TlsDataSize) > KERNEL_USABLE_STACK_SIZE",
        "d:\\xbox-apr03\\private\\ntos\\ps\\create.c",
        0xEBu,
        0);
    v18 = MmCreateKernelStack((int)v16, v15, v17, DebuggerThread);
    if ( v18 )
    {
      Thread->StartAddress = StartRoutine;
      KeInitializeThread(
        &Thread->Tcb,
        v18,
        v17,
        TlsDataSize,
        SystemRoutine,
        StartRoutine,
        StartContext,
        &KiSystemProcess);
      KeEnableApcQueuingThread(v22, v21, &Thread->Tcb);
      if ( CreateSuspended )
        KeSuspendThread(v24, v23, &Thread->Tcb);
      ObfReferenceObject(Thread);
      ObfReferenceObject(Thread);
      v20 = ObInsertObject(Thread, 0, 0, &Thread->UniqueThread);
      if ( v20 < 0 )
        goto LABEL_29;
      if ( PspCreateThreadNotifyRoutineCount )
      {
        v27 = 0;
        do
        {
          v28 = PspCreateThreadNotifyRoutine[v27];
          if ( v28 )
            v28(Thread, Thread->UniqueThread, 1);
          ++v27;
        }
        while ( v27 < 8 );
      }
      v20 = ObOpenObjectByPointer(Thread, &PsThreadObjectType, ThreadHandle);
      if ( v20 >= 0 )
      {
        if ( ThreadId )
          *ThreadId = Thread->UniqueThread;
      }
      else
      {
LABEL_29:
        Thread->Tcb.HasTerminated = 1;
        if ( CreateSuspended )
          KeResumeThread(v26, v25, &Thread->Tcb);
      }
      KeQuerySystemTime(&Thread->CreateTime);
      KeReadyThread(v30, v29, &Thread->Tcb);
    }
    else
    {
      v20 = -1073741670;
    }
    ObfDereferenceObject(Thread, v19);
    result = v20;
  }
  return result;
}