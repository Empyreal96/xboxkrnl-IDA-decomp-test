void __thiscall CMcpxVoiceClient::WaitForVoiceOff(CMcpxVoiceClient *this)
{
  if ( this->m_dwStatus & 1 )
  {
    while ( this->m_dwStatus & 0x10000000 )
      ;
  }
}