unsigned int __usercall HalInitiateShutdown@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  unsigned int result; // eax
  int v5; // edx
  int v6; // [esp-4h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x9B7u,
      0);
  result = DbgPrint(a3, "HalInitiateShutdown called.\n");
  if ( HalpSMBusLock.Header.SignalState )
  {
    HalpSMBusLock.Header.SignalState = 0;
    HalpSMCResetOrShutdownCommandCode = 2;
    HalpSMCResetOrShutdownDataValue = 128;
    HalpCommonResetOrShutdown(v5, v6, a3);
  }
  HalpShutdownRequestPending = 1;
  return result;
}