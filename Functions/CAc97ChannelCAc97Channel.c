void __thiscall CAc97Channel::CAc97Channel(CAc97Channel *this, CAc97Device *pDevice, AC97CHANNELTYPE nChannelType)
{
  this->m_nChannelType = nChannelType;
  this->m_dwMode = 0x2000000;
  this->m_pDevice = pDevice;
}