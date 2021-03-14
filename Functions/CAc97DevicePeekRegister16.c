unsigned __int16 __stdcall CAc97Device::PeekRegister16(unsigned int dwRegister)
{
  return *(_WORD *)dwRegister;
}