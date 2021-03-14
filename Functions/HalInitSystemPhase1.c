unsigned int __usercall HalInitSystemPhase1@<eax>(int *a1@<edi>)
{
  int v1; // edx
  int v2; // ecx

  HalPulseHardwareMonitorPin();
  word_8004BD8E[0] = (unsigned int)KeClockInterrupt >> 16;
  word_8004BD88[0] = (unsigned int)KeClockInterrupt;
  HalEnableSystemInterrupt(0, 1);
  HalPulseHardwareMonitorPin();
  word_8004BDCE = (unsigned int)HalpProfileInterrupt >> 16;
  word_8004BDC8 = (unsigned int)HalpProfileInterrupt;
  HalEnableSystemInterrupt(8u, 1);
  HalPulseHardwareMonitorPin();
  word_8004BDE6 = (unsigned int)HalpSMBusInterrupt >> 16;
  word_8004BDE0 = (unsigned int)HalpSMBusInterrupt;
  HalEnableSystemInterrupt(0xBu, 0);
  if ( !KeHasQuickBooted )
  {
    HalPulseHardwareMonitorPin();
    HalpProcessSMCInitialState(v1, v2, a1);
  }
  HalPulseHardwareMonitorPin();
  word_8004BDEE = (unsigned int)HalpSystemControlInterrupt >> 16;
  word_8004BDE8 = (unsigned int)HalpSystemControlInterrupt;
  return HalEnableSystemInterrupt(0xCu, 0);
}