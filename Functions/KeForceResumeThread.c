int __fastcall KeForceResumeThread(int a1, int a2, _KTHREAD *Thread)
{
  _KTHREAD *v3; // esi
  KIRQL v4; // al
  int v5; // edi
  KIRQL OldIrql_3; // [esp+13h] [ebp+Bh]

  v3 = Thread;
  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x251u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x252u,
      0);
  v4 = KeRaiseIrqlToDpcLevel();
  v5 = Thread->SuspendCount;
  OldIrql_3 = v4;
  if ( v3->SuspendCount )
  {
    ++v3->SuspendSemaphore.Header.SignalState;
    v3->SuspendCount = 0;
    KiWaitTest(&v3->SuspendSemaphore, 0);
  }
  KiUnlockDispatcherDatabase(OldIrql_3);
  return v5;
}