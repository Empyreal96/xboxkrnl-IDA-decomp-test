void __stdcall CAc97Device::PokeRegister8(unsigned int dwRegister, char bValue)
{
  *(_BYTE *)dwRegister = bValue;
}