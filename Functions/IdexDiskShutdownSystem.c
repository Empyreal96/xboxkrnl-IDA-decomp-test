void __usercall IdexDiskShutdownSystem(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  __int16 v4; // dx
  int v5; // ecx
  int v6; // eax
  __int16 v7; // dx
  int v8; // ecx
  int v9; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x542u,
      0);
  if ( !Interrupt.Connected )
    NewIrql = 2;
  KfRaiseIrql(NewIrql);
  v6 = IdexChannelIssueImmediateCommand(v4, v5, a3, a4, 0, 231);
  if ( v6 >= 0 )
  {
    v9 = IdexChannelIssueImmediateCommand(v7, v8, a3, a4, 0, 224);
    if ( v9 < 0 )
      DbgPrint(a3, "IDEX: shutdown failed to spindown disk (status=%08x).\n", v9);
  }
  else
  {
    DbgPrint(a3, "IDEX: shutdown failed to flush disk (status=%08x).\n", v6);
  }
  KfLowerIrql(2);
}