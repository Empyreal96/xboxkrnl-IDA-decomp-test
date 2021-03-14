char __userpurge HalpDisableVideoDACsComplete@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int SMBusStatus)
{
  HalpSMBusCompletionRoutine = 0;
  if ( !IoPendingMustCompletePackets )
    HalMustCompletePacketsFinished(a1, a2, a3);
  return 1;
}