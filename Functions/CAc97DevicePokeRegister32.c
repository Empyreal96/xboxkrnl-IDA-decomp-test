void __stdcall CAc97Device::PokeRegister32(unsigned int dwRegister, unsigned int dwValue)
{
  *(_DWORD *)dwRegister = dwValue;
}