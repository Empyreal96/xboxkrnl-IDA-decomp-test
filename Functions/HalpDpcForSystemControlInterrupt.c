void __stdcall HalpDpcForSystemControlInterrupt(_KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  if ( HalpSMBusLock.Header.SignalState )
  {
    HalpSMBusLock.Header.SignalState = 0;
    HalpReadSMCInterruptReason();
  }
  else
  {
    HalpSMBusSMCInterruptPending = 1;
  }
}