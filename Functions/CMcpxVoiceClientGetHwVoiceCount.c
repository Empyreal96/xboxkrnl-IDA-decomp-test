int __thiscall CMcpxVoiceClient::GetHwVoiceCount(CMcpxVoiceClient *this)
{
  return ((this->m_pSettings->m_pwfxFormat->nChannels - 1) >> 1) + 1;
}