void __thiscall CAc97Channel::PokeAciRegister8(CAc97Channel *this, unsigned int dwRegister, char bValue)
{
  CAc97Device::PokeAciRegister8(*(_DWORD *)(4 * this->m_nChannelType - 2146508060) + dwRegister, bValue);
}