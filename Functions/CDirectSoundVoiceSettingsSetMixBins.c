void __thiscall CDirectSoundVoiceSettings::SetMixBins(CDirectSoundVoiceSettings *this, unsigned int dwMixBinMask)
{
  if ( this->m_dwFlags & 0x10 )
  {
    this->m_dwMixBinMask = 1984;
  }
  else if ( dwMixBinMask )
  {
    this->m_dwMixBinMask = dwMixBinMask;
  }
  else
  {
    this->m_dwMixBinMask = *(_DWORD *)(4 * this->m_pwfxFormat->nChannels - 2146507928);
  }
}