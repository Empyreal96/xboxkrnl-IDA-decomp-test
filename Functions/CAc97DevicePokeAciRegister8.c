void __stdcall CAc97Device::PokeAciRegister8(unsigned int dwRegister, char bValue)
{
  CAc97Device::PokeRegister8(dwRegister + CAc97Device::m_dwAciRegisterBase, bValue);
}