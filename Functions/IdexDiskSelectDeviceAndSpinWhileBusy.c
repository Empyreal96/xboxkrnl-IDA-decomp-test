char __usercall IdexDiskSelectDeviceAndSpinWhileBusy@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  signed int v4; // esi
  unsigned __int8 v5; // al

  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x121u,
      0);
  __outbyte(0x1F6u, 0xA0u);
  v4 = 1000;
  while ( 1 )
  {
    v5 = __inbyte(0x1F7u);
    if ( (v5 & 0x80u) == 0 )
    {
      if ( v5 & 0x40 )
        break;
    }
    KeStallExecutionProcessor(0x64u);
    if ( !--v4 )
    {
      KfLowerIrql(2);
      Irp->IoStatus.Status = -1073741643;
      return 0;
    }
  }
  return 1;
}