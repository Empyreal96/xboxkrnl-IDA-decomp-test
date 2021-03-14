char __userpurge KeTestAlertThread@<al>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, char AlertMode)
{
  _KTHREAD *v4; // esi
  int v5; // edx
  int v6; // ecx
  char *v7; // eax
  char Alerted; // [esp+Eh] [ebp-2h]
  char OldIrql; // [esp+Fh] [ebp-1h]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      a3,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x572u,
      0);
  v4 = thread;
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x57Bu,
      0);
  v7 = &v4->Alerted[AlertMode];
  LOBYTE(v6) = *v7;
  Alerted = *v7;
  if ( *v7 == 1 )
  {
    *v7 = 0;
  }
  else if ( AlertMode == 1 && v4->ApcState.ApcListHead[1].Flink != &v4->ApcState.ApcListHead[1] )
  {
    v4->ApcState.UserApcPending = 1;
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)v4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x593u,
      0);
  KiUnlockDispatcherDatabase(OldIrql);
  return Alerted;
}