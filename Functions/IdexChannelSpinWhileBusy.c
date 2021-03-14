char __usercall IdexChannelSpinWhileBusy@<al>(char *IdeStatus@<ecx>, int a2@<edx>, int *a3@<edi>)
{
  char *v3; // esi
  signed int v4; // edi
  char v5; // al

  v3 = IdeStatus;
  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a2,
      (int)IdeStatus,
      a3,
      (int)IdeStatus,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x68u,
      0);
  v4 = 10000;
  while ( 1 )
  {
    v5 = __inbyte(0x1F7u);
    *v3 = v5;
    if ( v5 >= 0 )
      break;
    KeStallExecutionProcessor(0x64u);
    if ( !--v4 )
      return 0;
  }
  return 1;
}