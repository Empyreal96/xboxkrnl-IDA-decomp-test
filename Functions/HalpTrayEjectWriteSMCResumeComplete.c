char __userpurge HalpTrayEjectWriteSMCResumeComplete@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, int SMBusStatus)
{
  if ( SMBusStatus >= 0 )
  {
    if ( XboxBootFlags & 8 )
    {
      HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpHandleNextSMCInterruptReason;
      HalpKickoffWriteSMBus(32, 12, 1, 0);
    }
    else if ( HalpTrayEjectRequiresReboot )
    {
      HalpSMCResetOrShutdownCommandCode = 2;
      HalpSMCResetOrShutdownDataValue = 1;
      HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpCommonResetOrShutdownComplete;
      HalpKickoffWriteSMBus(32, 27, 1, HalpSMCScratchRegister | 1);
    }
    else
    {
      if ( KeHasQuickBooted )
        RtlAssert(
          a1,
          a2,
          a3,
          a4,
          "!KeHasQuickBooted",
          "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
          0x468u,
          0);
      XboxBootFlags |= 0x48u;
      HalpTrayEjectDuringBootOccurred = 1;
      HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpTrayEjectWriteSMCNonSecureComplete;
      HalpKickoffWriteSMBus(32, 25, 1, 1u);
    }
  }
  else
  {
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpTrayEjectWriteSMCResumeComplete;
    HalpKickoffWriteSMBus(32, 13, 1, 4u);
  }
  return 1;
}