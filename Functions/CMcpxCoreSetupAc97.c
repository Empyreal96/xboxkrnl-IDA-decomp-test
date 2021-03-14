int __usercall CMcpxCore::SetupAc97@<eax>(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-14h]
  int hr; // [esp+4h] [ebp-10h]
  unsigned int dwBufferAddress; // [esp+8h] [ebp-Ch]

  thisa = this;
  dwBufferAddress = this->m_ctxMemory[0].PhysicalAddress;
  hr = CAc97Device::Initialize(&this->m_Ac97, a2, 1u);
  if ( hr >= 0 )
    hr = CAc97Device::CreateChannel(&thisa->m_Ac97, a3, 0, 0);
  if ( hr >= 0 )
    hr = CAc97Channel::Initialize(thisa->m_Ac97.m_apChannels[0], a2, a3, 0, 0, 0);
  if ( hr >= 0 )
    CAc97Channel::AttachPacket(thisa->m_Ac97.m_apChannels[0], dwBufferAddress, CMcpxCore::m_adwGPOutputBufferSizes[0]);
  if ( hr >= 0 )
    hr = CAc97Device::CreateChannel(&thisa->m_Ac97, a3, AC97_CHANNELTYPE_DIGITAL, 0);
  if ( hr >= 0 )
    hr = CAc97Channel::Initialize(thisa->m_Ac97.m_apChannels[1], a2, a3, 0, 0, 0);
  if ( hr >= 0 )
  {
    CAc97Channel::AttachPacket(thisa->m_Ac97.m_apChannels[1], dwBufferAddress, CMcpxCore::m_adwGPOutputBufferSizes[0]);
    CAc97Channel::SetMode(thisa->m_Ac97.m_apChannels[1], 0x2000000u);
  }
  return hr;
}