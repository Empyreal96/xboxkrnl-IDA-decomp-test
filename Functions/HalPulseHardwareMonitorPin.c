void __stdcall HalPulseHardwareMonitorPin()
{
  if ( !KeHasQuickBooted && !(XboxBootFlags & 1) )
  {
    __outbyte(0x80CFu, 5u);
    KeStallExecutionProcessor(5u);
    __outbyte(0x80CFu, 4u);
    KeStallExecutionProcessor(5u);
  }
}