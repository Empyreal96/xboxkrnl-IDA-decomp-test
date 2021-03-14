void __stdcall ExpTimerDpcRoutine(_KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  int v4; // edx
  int v5; // ecx
  KIRQL v6; // bl

  v6 = KeRaiseIrqlToDpcLevel();
  if ( *((_BYTE *)DeferredContext + 120) )
    KeInsertQueueApc(v5, v4, (_KAPC *)DeferredContext + 1, SystemArgument1, SystemArgument2, 0);
  KfLowerIrql(v6);
}