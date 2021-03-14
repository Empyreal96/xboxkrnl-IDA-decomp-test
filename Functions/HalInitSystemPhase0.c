unsigned __int16 __stdcall HalInitSystemPhase0()
{
  unsigned __int64 v0; // rax
  int v1; // edx
  int v2; // ecx

  __outbyte(0x61u, 8u);
  HalPulseHardwareMonitorPin();
  v0 = RDMSR((void *)0x1B);
  WRMSR(0x1Bu, v0 & 0xFFFFFFFFFFFFF7FFui64);
  HalPulseHardwareMonitorPin();
  HalpInitializePICs();
  HalPulseHardwareMonitorPin();
  HalpInitializeRealTimeClock();
  HalPulseHardwareMonitorPin();
  HalpInitializeClock();
  HalPulseHardwareMonitorPin();
  HalStopProfileInterrupt(0);
  HalPulseHardwareMonitorPin();
  HalpSetupPCIDevices(v2, v1);
  HalPulseHardwareMonitorPin();
  return HalpInitializeSystemControlInterrupt();
}