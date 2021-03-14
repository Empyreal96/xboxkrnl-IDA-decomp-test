char __userpurge HalpTrayOpenWriteSMCResumeComplete@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, int SMBusStatus)
{
  if ( SMBusStatus < 0 )
  {
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpTrayOpenWriteSMCResumeComplete;
    HalpKickoffWriteSMBus(32, 13, 1, 4u);
    return 1;
  }
  if ( !(XboxBootFlags & 8) )
  {
    if ( HalpTrayEjectRequiresReboot )
      RtlAssert(
        a1,
        a2,
        a3,
        a4,
        "!HalpTrayEjectRequiresReboot",
        "d:\\xbox-apr03\\private\\ntos\\halx\\i386\\smbussci.c",
        0x4C6u,
        0);
    XboxBootFlags |= 8u;
    HalpTrayEjectDuringBootOccurred = 1;
    HalpKickoffWriteSMBus(32, 25, 1, 1u);
    HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpHandleNextSMCInterruptReason;
    return 1;
  }
  return HalpHandleNextSMCInterruptReason(a3, a4, 0);
}