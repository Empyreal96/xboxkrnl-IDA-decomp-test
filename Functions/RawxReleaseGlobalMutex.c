_KTHREAD *__thiscall RawxReleaseGlobalMutex(void *this)
{
  _KTHREAD *result; // eax
  unsigned int v2; // ecx

  RtlLeaveCriticalSection(this, (_KEVENT *)&RawxGlobalMutex);
  result = thread;
  v2 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v2;
  if ( !v2 && (_KAPC_STATE *)result->ApcState.ApcListHead[0].Flink != &result->ApcState )
  {
    result->ApcState.KernelApcPending = 1;
    result = (_KTHREAD *)HalRequestSoftwareInterrupt(1);
  }
  return result;
}