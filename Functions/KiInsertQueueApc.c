char __fastcall KiInsertQueueApc(_KAPC *Apc, int Increment)
{
  _KAPC *v2; // esi
  _KTHREAD *v3; // edi
  char v4; // bl
  char v5; // bl
  int v6; // eax
  _LIST_ENTRY *v7; // ecx
  _LIST_ENTRY *i; // eax
  int *v9; // eax
  char v10; // al
  int v11; // edx
  int v13; // [esp+Ch] [ebp-4h]

  v2 = Apc;
  v3 = Apc->Thread;
  v13 = Increment;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      Increment,
      (int)Apc,
      (int *)&v3->Header.Type,
      (int)Apc,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcsup.c",
      0x133u,
      0);
  if ( v2->Inserted )
  {
    v4 = 0;
    goto LABEL_27;
  }
  v5 = v2->ApcMode;
  if ( v2->NormalRoutine )
  {
    v6 = (int)&v3->ApcState.ApcListHead[v5];
    Increment = (int)v3->ApcState.ApcListHead[v5].Blink;
    Apc = (_KAPC *)((char *)v2 + 8);
    v2->ApcListEntry.Flink = (_LIST_ENTRY *)v6;
    v2->ApcListEntry.Blink = (_LIST_ENTRY *)Increment;
    *(_DWORD *)Increment = (char *)v2 + 8;
    *(_DWORD *)(v6 + 4) = (char *)v2 + 8;
  }
  else
  {
    v7 = &v3->ApcState.ApcListHead[v5];
    for ( i = v7->Flink; i != v7 && !i[2].Flink; i = i->Flink )
      ;
    v9 = (int *)i->Blink;
    Increment = *v9;
    Apc = (_KAPC *)((char *)v2 + 8);
    v2->ApcListEntry.Flink = (_LIST_ENTRY *)*v9;
    v2->ApcListEntry.Blink = (_LIST_ENTRY *)v9;
    *(_DWORD *)(Increment + 4) = (char *)v2 + 8;
    *v9 = (int)&v2->ApcListEntry;
  }
  v2->Inserted = 1;
  if ( v5 )
  {
    if ( v3->State != 5 || v3->WaitMode != 1 || !v3->Alertable )
      goto LABEL_26;
    v3->ApcState.UserApcPending = 1;
    v11 = 192;
LABEL_25:
    KiUnwaitThread(v3, v11, v13);
    goto LABEL_26;
  }
  v10 = v3->State;
  v3->ApcState.KernelApcPending = 1;
  if ( v10 != 2 )
  {
    if ( v10 != 5 || v3->WaitIrql || v2->NormalRoutine && (v3->KernelApcDisable || v3->ApcState.KernelApcInProgress) )
      goto LABEL_26;
    v11 = 256;
    goto LABEL_25;
  }
  HalRequestSoftwareInterrupt(1);
LABEL_26:
  v4 = 1;
LABEL_27:
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      Increment,
      (int)Apc,
      (int *)&v3->Header.Type,
      (int)v2,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\apcsup.c",
      0x17Au,
      0);
  return v4;
}