void __stdcall CAc97Device::PokeAciRegister32(unsigned int dwRegister, unsigned int dwValue)
{
  CAc97Device::PokeRegister32(dwRegister + CAc97Device::m_dwAciRegisterBase, dwValue);
}