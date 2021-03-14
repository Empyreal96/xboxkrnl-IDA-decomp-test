char __stdcall CAc97Device::PeekAciRegister8(unsigned int dwRegister)
{
  return CAc97Device::PeekRegister8(dwRegister + CAc97Device::m_dwAciRegisterBase);
}