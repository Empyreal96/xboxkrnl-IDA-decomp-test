void KeEnterCriticalRegion(void)
{
  --thread->KernelApcDisable;
}