unsigned int __thiscall CMcpxVoiceClient::SamplesToBytes(CMcpxVoiceClient *this, unsigned int dwSamples)
{
  unsigned int result; // eax

  if ( this->m_pSettings->m_pwfxFormat->wFormatTag == 105 )
    result = this->m_pSettings->m_pwfxFormat->nBlockAlign * (dwSamples >> 6);
  else
    result = dwSamples * this->m_pSettings->m_pwfxFormat->nBlockAlign;
  return result;
}