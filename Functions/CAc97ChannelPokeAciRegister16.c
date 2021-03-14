void __thiscall CAc97Channel::PokeAciRegister16(CAc97Channel *this, unsigned int dwRegister, unsigned __int16 wValue)
{
  CAc97Device::PokeAciRegister16(*(_DWORD *)(4 * this->m_nChannelType - 2146508060) + dwRegister, wValue);
}