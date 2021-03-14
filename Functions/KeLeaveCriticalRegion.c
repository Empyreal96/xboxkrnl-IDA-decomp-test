void KeLeaveCriticalRegion(void)
{
  _KTHREAD *v0; // eax
  unsigned int v1; // ecx

  v0 = thread;
  v1 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v1;
  if ( !v1 && (_KAPC_STATE *)v0->ApcState.ApcListHead[0].Flink != &v0->ApcState )
  {
    v0->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
}