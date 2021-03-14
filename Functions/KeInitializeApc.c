void __stdcall KeInitializeApc(_KAPC *Apc, _KTHREAD *Thread, void (__stdcall *KernelRoutine)(_KAPC *, void (__stdcall **)(void *, void *, void *), void **, void **, void **), void (__stdcall *RundownRoutine)(_KAPC *), void (__stdcall *NormalRoutine)(void *, void *, void *), char ApcMode, void *NormalContext)
{
  Apc->Thread = Thread;
  Apc->KernelRoutine = KernelRoutine;
  Apc->RundownRoutine = RundownRoutine;
  Apc->Type = 18;
  Apc->NormalRoutine = NormalRoutine;
  if ( NormalRoutine )
  {
    Apc->ApcMode = ApcMode;
    Apc->NormalContext = NormalContext;
  }
  else
  {
    Apc->ApcMode = 0;
    Apc->NormalContext = 0;
  }
  Apc->Inserted = 0;
}