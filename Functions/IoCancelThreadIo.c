void __userpurge IoCancelThreadIo(int *a1@<edi>, int a2@<esi>, _ETHREAD *Thread)
{
  int v3; // edx
  int v4; // ST10_4
  KIRQL v5; // al
  _LIST_ENTRY *v6; // esi
  _LIST_ENTRY *i; // edx
  unsigned int v8; // edi
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // eax
  _LARGE_INTEGER interval; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v3, v4, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x20Fu, 0);
  }
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = &Thread->IrpList;
  for ( i = Thread->IrpList.Flink; v6 != i; i = i->Flink )
    HIBYTE(i[2].Flink) = 1;
  v8 = 0;
  interval.QuadPart = -1000000i64;
  while ( v6->Flink != v6 )
  {
    KfLowerIrql(v5);
    KeDelayExecutionThread(v10, v9, 0, 0, &interval);
    v11 = v8++;
    if ( v11 > 0xBB8 )
      IopDisassociateThreadIrp();
    v5 = KfRaiseIrql(1);
  }
  KfLowerIrql(v5);
}