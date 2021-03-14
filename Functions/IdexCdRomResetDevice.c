void __usercall IdexCdRomResetDevice(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
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
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0xC8u,
      0);
  if ( HalIsResetOrShutdownPending() )
  {
    KfLowerIrql(2);
    IdexChannelAbortCurrentPacket(v4, v5, a3, a4);
  }
  else
  {
    __outbyte(0x1F6u, 0xB0u);
    __outbyte(0x1F7u, 8u);
    KfLowerIrql(2);
    IdexChannelSetTimerPeriod(v6, 100);
    dword_80051348 = (int (__fastcall *)(_DWORD, _DWORD))IdexCdRomPollResetComplete;
    unk_8005135C = -6;
  }
}