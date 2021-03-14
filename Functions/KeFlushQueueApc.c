_LIST_ENTRY *__userpurge KeFlushQueueApc@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _KTHREAD *Thread, char ApcMode)
{
  int v5; // edx
  int v6; // ecx
  int *v7; // ecx
  int v8; // esi
  _LIST_ENTRY *v9; // eax
  _DWORD *v10; // eax
  char OldIrql; // [esp+Fh] [ebp-1h]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      a3,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0x9Cu,
      0);
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v5,
      v6,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0xA4u,
      0);
  v7 = (int *)&Thread->ApcState.ApcListHead[ApcMode];
  v8 = *v7;
  if ( (int *)*v7 == v7 )
  {
    v8 = 0;
  }
  else
  {
    v9 = Thread->ApcState.ApcListHead[ApcMode].Blink;
    v9->Flink = (_LIST_ENTRY *)v8;
    *(_DWORD *)(v8 + 4) = v9;
    v10 = (_DWORD *)v8;
    do
    {
      *((_BYTE *)v10 - 5) = 0;
      v10 = (_DWORD *)*v10;
    }
    while ( v10 != (_DWORD *)v8 );
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)Thread,
      (int)v7,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      v8,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcobj.c",
      0xC1u,
      0);
  KiUnlockDispatcherDatabase(OldIrql);
  return (_LIST_ENTRY *)v8;
}