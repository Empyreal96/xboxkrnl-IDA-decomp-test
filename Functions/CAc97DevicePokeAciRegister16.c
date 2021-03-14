void __stdcall CAc97Device::PokeAciRegister16(unsigned int dwRegister, unsigned __int16 wValue)
{
  CAc97Device::PokeRegister16(dwRegister + CAc97Device::m_dwAciRegisterBase, wValue);
}