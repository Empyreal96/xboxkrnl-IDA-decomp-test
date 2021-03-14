void __stdcall CAc97Device::WaitRegisterRetry()
{
  KeStallExecutionProcessor(0x14u);
}