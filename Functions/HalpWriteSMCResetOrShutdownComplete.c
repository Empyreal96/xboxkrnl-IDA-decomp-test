char __stdcall HalpWriteSMCResetOrShutdownComplete(int SMBusStatus)
{
  if ( SMBusStatus >= 0 )
    HalHaltSystem();
  HalpSMBusCompletionRoutine = HalpWriteSMCResetOrShutdownComplete;
  HalpKickoffWriteSMBus(32, HalpSMCResetOrShutdownCommandCode, 1, HalpSMCResetOrShutdownDataValue);
  return 1;
}