int *__stdcall RawxAcquireGlobalMutexExclusive()
{
  --thread->KernelApcDisable;
  return RtlEnterCriticalSection(&RawxGlobalMutex);
}