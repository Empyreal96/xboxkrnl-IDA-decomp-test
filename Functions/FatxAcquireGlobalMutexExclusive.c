int *__stdcall FatxAcquireGlobalMutexExclusive()
{
  --thread->KernelApcDisable;
  return RtlEnterCriticalSection(&FatxGlobalMutex);
}