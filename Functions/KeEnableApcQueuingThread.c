char __fastcall KeEnableApcQueuingThread(int a1, int a2, _KTHREAD *Thread)
{
  KIRQL v3; // al
  char v4; // bl

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x216u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x217u,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = Thread->ApcState.ApcQueueable;
  Thread->ApcState.ApcQueueable = 1;
  KiUnlockDispatcherDatabase(v3);
  return v4;
}