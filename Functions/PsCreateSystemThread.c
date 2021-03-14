int __userpurge PsCreateSystemThread@<eax>(int *a1@<edi>, int a2@<esi>, void **ThreadHandle, void **ThreadId, void (__stdcall *StartRoutine)(void *), void *StartContext, char DebuggerThread)
{
  return PsCreateSystemThreadEx(
           a1,
           a2,
           ThreadHandle,
           0,
           0x3000u,
           0,
           ThreadId,
           StartRoutine,
           StartContext,
           0,
           DebuggerThread,
           (void (__stdcall *)(void (__stdcall *)(void *), void *))PspSystemThreadStartup);
}