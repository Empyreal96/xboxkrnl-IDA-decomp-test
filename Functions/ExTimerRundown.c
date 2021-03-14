void __stdcall ExTimerRundown()
{
  int *v0; // edi
  KIRQL v1; // bl
  int i; // eax
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  char v12; // bl
  int v13; // edx
  _ETHREAD *ExThread; // [esp+8h] [ebp-8h]
  char OldIrql; // [esp+Fh] [ebp-1h]

  ExThread = (_ETHREAD *)thread;
  v0 = (int *)&thread[1].MutantListHead.Blink;
  v1 = KeRaiseIrqlToDpcLevel();
  for ( i = *v0; (int *)*v0 != v0; i = *v0 )
  {
    v3 = i - 108;
    ObfReferenceObject((void *)(i - 108));
    KfLowerIrql(v1);
    OldIrql = KeRaiseIrqlToDpcLevel();
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        v4,
        v5,
        v0,
        v3,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ex\\timer.c",
        0x145u,
        0);
    if ( *(_BYTE *)(v3 + 120) && ExThread == *(_ETHREAD **)(v3 + 44) )
    {
      v6 = *(_DWORD *)(v3 + 108);
      v7 = *(_DWORD **)(v3 + 112);
      *v7 = v6;
      *(_DWORD *)(v6 + 4) = v7;
      *(_BYTE *)(v3 + 120) = 0;
      KeCancelTimer((int)v7, v4, (_KTIMER *)v3);
      KeRemoveQueueDpc(v8, v9, v0, (_KDPC *)(v3 + 80));
      KeRemoveQueueApc(v10, v11, v0, (_KAPC *)(v3 + 40));
      v12 = 1;
    }
    else
    {
      v12 = 0;
    }
    KfLowerIrql(OldIrql);
    if ( v12 )
      ObfDereferenceObject((void *)v3, v13);
    ObfDereferenceObject((void *)v3, v13);
    v1 = KeRaiseIrqlToDpcLevel();
  }
  KfLowerIrql(v1);
}