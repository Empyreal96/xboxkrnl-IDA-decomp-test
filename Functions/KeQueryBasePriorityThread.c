int __fastcall KeQueryBasePriorityThread(int a1, int a2, _KTHREAD *Thread)
{
  KIRQL v3; // al
  char v4; // dl
  int v5; // esi

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)&Thread->Header.Type,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x295u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)&Thread->Header.Type,
      (int)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x296u,
      0);
  v3 = KeRaiseIrqlToDpcLevel();
  v4 = Thread->Saturation;
  v5 = Thread->BasePriority - Thread->ApcState.Process->BasePriority;
  if ( v4 )
    v5 = 16 * v4;
  KiUnlockDispatcherDatabase(v3);
  return v5;
}