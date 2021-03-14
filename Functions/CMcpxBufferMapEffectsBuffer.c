void __usercall CMcpxBuffer::MapEffectsBuffer(CMcpxBuffer *this@<ecx>, int a2@<esi>)
{
  unsigned int dwBufferSize; // ST14_4
  char *pvBufferData; // ST10_4
  CMcpxBuffer *thisa; // [esp+0h] [ebp-10h]
  unsigned int dwVoiceIndex; // [esp+Ch] [ebp-4h]

  thisa = this;
  if ( !(this->m_dwStatus & 0x40) )
  {
    this->m_dwStatus |= 0x40u;
    for ( dwVoiceIndex = 11;
          dwVoiceIndex <= 0x1E && !((1 << dwVoiceIndex) & this->m_pSettings->m_dwInputMixBinMask);
          ++dwVoiceIndex )
    {
      ;
    }
    dwBufferSize = CMcpxVoiceClient::SamplesToBytes((CMcpxVoiceClient *)&this->vfptr, 0x20u);
    pvBufferData = (char *)thisa->m_pMcpxApu->m_ctxMemory[11].VirtualAddress + dwBufferSize * (dwVoiceIndex - 11);
    CDirectSoundBufferSettings::SetBufferData(thisa->m_pSettings, a2, pvBufferData, dwBufferSize);
    CMcpxBuffer::MapBuffer(thisa, 0x7FFu, pvBufferData, dwBufferSize);
  }
}