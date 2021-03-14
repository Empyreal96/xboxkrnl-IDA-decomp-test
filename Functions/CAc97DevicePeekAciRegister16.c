unsigned __int16 __stdcall CAc97Device::PeekAciRegister16(unsigned int dwRegister)
{
  return CAc97Device::PeekRegister16(dwRegister + CAc97Device::m_dwAciRegisterBase);
}