int __fastcall KeAlertResumeThread(int a1, int a2, _KTHREAD *Thread)
{
  _KTHREAD *v3; // esi
  int v4; // edx
  int v5; // ecx
  char v6; // al
  int v7; // ebx
  char v8; // al
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v3 = Thread;
  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x149u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x14Au,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v4,
      v5,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x152u,
      0);
  if ( !v3->Alerted[0] )
  {
    if ( v3->State != 5 || v3->Alertable != 1 )
      v3->Alerted[0] = 1;
    else
      KiUnwaitThread(v3, 257, 2);
  }
  v6 = v3->SuspendCount;
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 - 1;
    v3->SuspendCount = v8;
    if ( !v8 )
    {
      ++v3->SuspendSemaphore.Header.SignalState;
      KiWaitTest(&v3->SuspendSemaphore, 0);
    }
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v4,
      v5,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x186u,
      0);
  KiUnlockDispatcherDatabase(OldIrql_3);
  return v7;
}