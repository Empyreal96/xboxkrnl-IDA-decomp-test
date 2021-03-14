void __usercall KeRundownThread(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _KTHREAD *v4; // esi
  _LIST_ENTRY *v5; // esi
  int v6; // ecx
  _LIST_ENTRY *v7; // eax
  _LIST_ENTRY *v8; // edx
  bool v9; // zf
  _LIST_ENTRY *v10; // eax
  char OldIrql; // [esp+1h] [ebp-1h]

  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x359u,
      0);
  v4 = thread;
  OldIrql = KeRaiseIrqlToDpcLevel();
  v5 = &v4->MutantListHead;
  while ( 1 )
  {
    v10 = v5->Flink;
    if ( v5->Flink == v5 )
      break;
    v6 = (int)&v10[-2];
    v7 = v10->Flink;
    v8 = *(_LIST_ENTRY **)(v6 + 20);
    v8->Flink = v7;
    v7->Blink = v8;
    *(_DWORD *)(v6 + 24) = 0;
    v9 = *(_DWORD *)(v6 + 8) == v6 + 8;
    *(_DWORD *)(v6 + 4) = 1;
    *(_BYTE *)(v6 + 28) = 1;
    if ( !v9 )
      KiWaitTest((void *)v6, 1);
  }
  KiUnlockDispatcherDatabase(OldIrql);
}