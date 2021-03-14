char __userpurge HalpTrayEjectWriteSMCNonSecureComplete@<al>(int *a1@<edi>, int a2@<esi>, int SMBusStatus)
{
  if ( SMBusStatus < 0 )
    return HalpHandleNextSMCInterruptReason(a1, a2, 0);
  HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpHandleNextSMCInterruptReason;
  HalpKickoffWriteSMBus(32, 12, 1, 0);
  return 1;
}