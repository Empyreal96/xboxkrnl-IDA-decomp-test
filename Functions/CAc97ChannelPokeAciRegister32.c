void __thiscall CAc97Channel::PokeAciRegister32(CAc97Channel *this, unsigned int dwRegister, unsigned int dwValue)
{
  CAc97Device::PokeAciRegister32(*(_DWORD *)(4 * this->m_nChannelType - 2146508060) + dwRegister, dwValue);
}