char __userpurge HalpReadSMCInterruptReasonComplete@<al>(int *a1@<edi>, int a2@<esi>, int SMBusStatus)
{
  unsigned __int8 v4; // al

  if ( SMBusStatus < 0 )
    return 0;
  v4 = __inbyte(0xC006u);
  HalpSMCInterruptReason = v4;
  return HalpHandleNextSMCInterruptReason(a1, a2, SMBusStatus);
}