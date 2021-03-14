void __stdcall KeInitializeDpc(_KDPC *Dpc, void (__stdcall *DeferredRoutine)(_KDPC *, void *, void *, void *), void *DeferredContext)
{
  Dpc->DeferredRoutine = DeferredRoutine;
  Dpc->Type = 19;
  Dpc->DeferredContext = DeferredContext;
  Dpc->Inserted = 0;
}