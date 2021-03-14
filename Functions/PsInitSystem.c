char __usercall PsInitSystem@<al>(void *a1@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  void *ThreadHandle; // [esp+0h] [ebp-4h]

  ThreadHandle = a1;
  KeInitializeDpc(&PsReaperDpc, (void (__stdcall *)(_KDPC *, void *, void *, void *))PspReaper, 0);
  if ( PsCreateSystemThread(a2, a3, &ThreadHandle, 0, (void (__stdcall *)(void *))Phase1Initialization, 0, 0) < 0 )
    return 0;
  NtClose(a2, ThreadHandle);
  return 1;
}