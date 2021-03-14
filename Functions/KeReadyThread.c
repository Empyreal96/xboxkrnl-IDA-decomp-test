void __fastcall KeReadyThread(int a1, int a2, _KTHREAD *Thread)
{
  KIRQL v3; // bl

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)&Thread->Header.Type,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x2D7u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)&Thread->Header.Type,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x2D8u,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  KiReadyThread(Thread);
  KiUnlockDispatcherDatabase(v3);
}