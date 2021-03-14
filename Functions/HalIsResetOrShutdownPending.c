bool __stdcall HalIsResetOrShutdownPending()
{
  return HalpSMCResetOrShutdownCommandCode != 0;
}