void __usercall HalMustCompletePacketsFinished(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  volatile unsigned int v3; // esi

  if ( IoPendingMustCompletePackets )
    RtlAssert(
      a1,
      a2,
      a3,
      0,
      "IoPendingMustCompletePackets == 0",
      "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
      0x2B4u,
      0);
  if ( !HalpSMBusCompletionRoutine )
  {
    if ( (HalpSMCResetOrShutdownCommandCode != 13 || HalpSMCResetOrShutdownDataValue != 1)
      && (HalpSMCResetOrShutdownCommandCode != 2 || HalpSMCResetOrShutdownDataValue != 128) )
    {
      DbgUnLoadImageSymbols(0, (void *)0xFFFFFFFF, 0);
    }
    else
    {
      dword_8004C604 = 0;
      v3 = KeTickCount;
      IdexDiskShutdownSystem(a1, HalpSMCResetOrShutdownDataValue, a3, KeTickCount);
      while ( KeTickCount - v3 < 0x7D )
        ;
    }
    HalpSMBusCompletionRoutine = HalpWriteSMCResetOrShutdownComplete;
    HalpKickoffWriteSMBus(32, HalpSMCResetOrShutdownCommandCode, 1, HalpSMCResetOrShutdownDataValue);
  }
}