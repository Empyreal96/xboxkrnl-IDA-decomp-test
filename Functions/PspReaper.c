void __userpurge PspReaper(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  int *v7; // eax
  int v8; // ecx
  int *v9; // edx
  void **v10; // esi
  int v11; // edx
  int v12; // [esp-4h] [ebp-Ch]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c",
      0x47u,
      0);
  v7 = (int *)PsReaperListHead.Flink;
  if ( !IsListEmpty(&PsReaperListHead) )
  {
    v12 = a3;
    do
    {
      v8 = *v7;
      v9 = (int *)v7[1];
      *v9 = *v7;
      *(_DWORD *)(v8 + 4) = v9;
      v10 = (void **)(v7 - 73);
      if ( (_BYTE)dword_8004C5D0 != 2 )
        RtlAssert(
          (int)v9,
          v8,
          (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
          (int)v10,
          "KeGetCurrentIrql() == DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c",
          0x54u,
          0);
      MmDeleteKernelStack(v8, (int)v9, v10[7], v10[8]);
      v10[7] = 0;
      ObfDereferenceObject(v10, v11);
      if ( (_BYTE)dword_8004C5D0 != 2 )
        RtlAssert(
          a1,
          a2,
          (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
          (int)v10,
          "KeGetCurrentIrql() == DISPATCH_LEVEL",
          "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c",
          0x63u,
          0);
      v7 = (int *)PsReaperListHead.Flink;
    }
    while ( !IsListEmpty(&PsReaperListHead) );
    a3 = v12;
  }
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ps\\psdelete.c",
      0x6Bu,
      0);
}