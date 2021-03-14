CMcpxBuffer *__thiscall CMcpxVoiceClient::GetSubMixDestination(CMcpxVoiceClient *this)
{
  CMcpxBuffer *result; // eax

  if ( this->m_pSettings->m_pMixinBuffer )
    result = this->m_pSettings->m_pMixinBuffer->m_pBuffer;
  else
    result = 0;
  return result;
}