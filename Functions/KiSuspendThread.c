void __fastcall KiSuspendThread(int a1, int a2, void *NormalContext, void *SystemArgument1, void *SystemArgument2)
{
  KeWaitForSingleObject(a1, a2, &thread->SuspendSemaphore, Suspended, 0, 0, 0);
}