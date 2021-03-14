unsigned int __stdcall CAc97Device::PeekAciRegister32(unsigned int dwRegister)
{
  return CAc97Device::PeekRegister32(dwRegister + CAc97Device::m_dwAciRegisterBase);
}