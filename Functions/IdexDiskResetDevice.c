void __usercall IdexDiskResetDevice(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  char v4; // dl
  int v5; // ecx
  void *v6; // ecx

  if ( (_BYTE)dword_8004C5D0 != NewIrql )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == IdexChannelObject.InterruptIrql",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0xD2u,
      0);
  if ( HalIsResetOrShutdownPending() )
  {
    KfLowerIrql(2);
    IdexChannelAbortCurrentPacket(v4, v5, a3, a4);
  }
  else
  {
    __outbyte(0x3F6u, 0);
    KeStallExecutionProcessor(0x32u);
    __outbyte(0x3F6u, 4u);
    KeStallExecutionProcessor(0x64u);
    __outbyte(0x3F6u, 0);
    KeStallExecutionProcessor(0x32u);
    KfLowerIrql(2);
    IdexChannelSetTimerPeriod(v6, 100);
    dword_80051348 = (int (*)(void))IdexDiskPollResetComplete;
    unk_8005135C = -6;
  }
}