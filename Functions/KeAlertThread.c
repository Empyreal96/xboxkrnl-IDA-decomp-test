char __fastcall KeAlertThread(int a1, int a2, _KTHREAD *Thread, char AlertMode)
{
  _KTHREAD *v4; // esi
  int v5; // edx
  int v6; // ecx
  char *v7; // eax
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]
  char Alerted; // [esp+1Bh] [ebp+Fh]

  v4 = Thread;
  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0xFAu,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0xFBu,
      0);
  OldIrql_3 = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x103u,
      0);
  LOBYTE(v5) = AlertMode;
  v7 = &v4->Alerted[AlertMode];
  LOBYTE(v6) = *v7;
  Alerted = *v7;
  if ( !*v7 )
  {
    if ( v4->State != 5 || v4->Alertable != 1 || AlertMode > v4->WaitMode )
      *v7 = 1;
    else
      KiUnwaitThread(v4, 257, 2);
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x128u,
      0);
  KiUnlockDispatcherDatabase(OldIrql_3);
  return Alerted;
}