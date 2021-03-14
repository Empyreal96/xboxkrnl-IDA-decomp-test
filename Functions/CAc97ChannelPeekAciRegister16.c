unsigned __int16 __thiscall CAc97Channel::PeekAciRegister16(CAc97Channel *this, unsigned int dwRegister)
{
  return CAc97Device::PeekAciRegister16(*(_DWORD *)(4 * this->m_nChannelType - 2146508060) + dwRegister);
}