void __stdcall HalpReadSMCInterruptReason()
{
  HalpSMBusCompletionRoutine = (char (__stdcall *)(int))HalpReadSMCInterruptReasonComplete;
  HalpKickoffReadSMBus(32, 17, 1);
}