void __thiscall CMcpxVoiceClient::SetENVA(CMcpxVoiceClient *this, _DSENVELOPEDESC *pEnv)
{
  CMcpxVoiceClient *v2; // ST00_4

  v2 = this;
  this->m_RegCache.VoiceOn = (pEnv->dwMode << 28) | this->m_RegCache.VoiceOn & 0xFFFFFFF;
  v2->m_RegCache.LFOENV = pEnv->dwRelease & 0xFFF | v2->m_RegCache.LFOENV & 0xFFFFF000;
  v2->m_RegCache.CfgENV0 = pEnv->dwAttack & 0xFFF | v2->m_RegCache.CfgENV0 & 0xFFFFF000;
  v2->m_RegCache.CfgENV0 = ((pEnv->dwDelay & 0xFFF) << 12) | v2->m_RegCache.CfgENV0 & 0xFF000FFF;
  v2->m_RegCache.CfgENVA = pEnv->dwDecay & 0xFFF | v2->m_RegCache.CfgENVA & 0xFFFFF000;
  v2->m_RegCache.CfgENVA = ((pEnv->dwHold & 0xFFF) << 12) | v2->m_RegCache.CfgENVA & 0xFF000FFF;
  v2->m_RegCache.CfgENVA = (pEnv->dwSustain << 24) | v2->m_RegCache.CfgENVA & 0xFFFFFF;
}