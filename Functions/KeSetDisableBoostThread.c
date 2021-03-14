int __fastcall KeSetDisableBoostThread(int a1, int a2, _KTHREAD *Thread, unsigned int Disable)
{
  KIRQL v4; // al
  int v5; // edi

  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x42Bu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x42Cu,
      0);
  v4 = KeRaiseIrqlToDpcLevel();
  v5 = (unsigned __int8)Thread->DisableBoost;
  Thread->DisableBoost = Disable;
  KiUnlockDispatcherDatabase(v4);
  return v5;
}