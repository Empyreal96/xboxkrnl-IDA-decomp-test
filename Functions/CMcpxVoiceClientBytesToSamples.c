unsigned int __thiscall CMcpxVoiceClient::BytesToSamples(CMcpxVoiceClient *this, unsigned int dwBytes)
{
  unsigned int result; // eax

  if ( this->m_pSettings->m_pwfxFormat->wFormatTag == 105 )
    result = dwBytes / this->m_pSettings->m_pwfxFormat->nBlockAlign << 6;
  else
    result = dwBytes / this->m_pSettings->m_pwfxFormat->nBlockAlign;
  return result;
}