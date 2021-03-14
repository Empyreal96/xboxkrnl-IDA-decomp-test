void __stdcall CAc97Device::PokeRegister16(unsigned int dwRegister, unsigned __int16 wValue)
{
  *(_WORD *)dwRegister = wValue;
}