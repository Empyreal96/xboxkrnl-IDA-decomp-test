int __fastcall KeSuspendThread(int a1, int a2, _KTHREAD *Thread)
{
  KIRQL v3; // al
  int v4; // edi
  KIRQL v5; // bl

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x4AFu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x4B0u,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = Thread->SuspendCount;
  v5 = v3;
  if ( v4 == 127 )
  {
    KiUnlockDispatcherDatabase(v3);
    ExRaiseStatus(-1073741750);
  }
  if ( Thread->ApcState.ApcQueueable == 1 )
  {
    ++Thread->SuspendCount;
    if ( !v4 && !KiInsertQueueApc(&Thread->SuspendApc, 0) )
      --Thread->SuspendSemaphore.Header.SignalState;
  }
  KiUnlockDispatcherDatabase(v5);
  return v4;
}