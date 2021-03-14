unsigned __int16 __stdcall HalInitSystemPhase0Quick()
{
  HalPulseHardwareMonitorPin();
  return HalpInitializePICs();
}