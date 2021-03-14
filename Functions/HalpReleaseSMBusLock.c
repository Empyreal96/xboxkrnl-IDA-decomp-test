void __usercall HalpReleaseSMBusLock(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x65Au,
      0);
  if ( HalpSMBusSMCInterruptPending )
  {
    HalpSMBusSMCInterruptPending = 0;
    HalpReadSMCInterruptReason();
  }
  else
  {
    if ( HalpShutdownRequestPending )
    {
      HalpShutdownRequestPending = 0;
      HalpSMCResetOrShutdownCommandCode = 2;
      HalpSMCResetOrShutdownDataValue = 128;
      HalpCommonResetOrShutdown(a1, a2, a3);
    }
    KeSetEvent(a2, a1, &HalpSMBusLock, 0, 0);
  }
}