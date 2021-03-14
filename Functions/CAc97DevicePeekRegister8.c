char __stdcall CAc97Device::PeekRegister8(unsigned int dwRegister)
{
  return *(_BYTE *)dwRegister;
}