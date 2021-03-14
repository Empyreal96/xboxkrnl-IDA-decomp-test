char __thiscall CAc97Channel::PeekAciRegister8(CAc97Channel *this, unsigned int dwRegister)
{
  return CAc97Device::PeekAciRegister8(*(_DWORD *)(4 * this->m_nChannelType - 2146508060) + dwRegister);
}