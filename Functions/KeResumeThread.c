int __fastcall KeResumeThread(int a1, int a2, _KTHREAD *Thread)
{
  KIRQL v3; // bl
  char v4; // al
  int v5; // edi
  char v6; // al

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x30Au,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x30Bu,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = Thread->SuspendCount;
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 - 1;
    Thread->SuspendCount = v6;
    if ( !v6 )
    {
      ++Thread->SuspendSemaphore.Header.SignalState;
      KiWaitTest(&Thread->SuspendSemaphore, 0);
    }
  }
  KiUnlockDispatcherDatabase(v3);
  return v5;
}