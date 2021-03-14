unsigned int __stdcall CAc97Device::PeekRegister32(unsigned int dwRegister)
{
  return *(_DWORD *)dwRegister;
}