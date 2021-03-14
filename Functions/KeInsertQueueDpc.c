bool __userpurge KeInsertQueueDpc@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _KDPC *Dpc, void *SystemArgument1, void *SystemArgument2)
{
  _KDPC *v6; // esi
  KIRQL v7; // al
  char v8; // bl
  _LIST_ENTRY *v9; // ecx
  KIRQL OldIrql_3; // [esp+13h] [ebp+Bh]

  v6 = Dpc;
  if ( Dpc->Type != 19 )
    RtlAssert(a1, a2, a3, (int)Dpc, "(Dpc)->Type == DpcObject", "d:\\xbox-apr03\\private\\ntos\\ke\\dpcobj.c", 0x7Bu, 0);
  v7 = KfRaiseIrql(31);
  v8 = Dpc->Inserted;
  OldIrql_3 = v7;
  if ( !v8 )
  {
    v6->SystemArgument1 = SystemArgument1;
    v6->SystemArgument2 = SystemArgument2;
    v6->Inserted = 1;
    v9 = (_LIST_ENTRY *)unk_8004C600;
    v6->DpcListEntry.Flink = (_LIST_ENTRY *)&unk_8004C5FC;
    v6->DpcListEntry.Blink = v9;
    v9->Flink = &v6->DpcListEntry;
    unk_8004C600 = (char *)v6 + 4;
    if ( !dword_8004C604 && !unk_8004C5F8 )
    {
      unk_8004C5F8 = 1;
      HalRequestSoftwareInterrupt(2);
    }
  }
  KfLowerIrql(OldIrql_3);
  return v8 == 0;
}