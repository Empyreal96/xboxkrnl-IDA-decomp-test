void __thiscall CMcpxAPU::RemoveIdleVoice(CMcpxAPU *this, unsigned int dwIdleVoice)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-8h]
  CMcpxVoiceClient *pClient; // [esp+4h] [ebp-4h]

  thisa = this;
  pClient = this->m_apVoiceMap[dwIdleVoice];
  if ( dwIdleVoice == *((_DWORD *)&pClient->m_pMcpxApu
                      + CMcpxVoiceClient::GetHwVoiceCount(this->m_apVoiceMap[dwIdleVoice]))
    && pClient->m_leActiveVoice.Flink != &pClient->m_leActiveVoice )
  {
    CMcpxAPU::RemoveIdleVoice(thisa, pClient);
  }
}