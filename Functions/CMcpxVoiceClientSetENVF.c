void __thiscall CMcpxVoiceClient::SetENVF(CMcpxVoiceClient *this, _DSENVELOPEDESC *pEnv)
{
  CMcpxVoiceClient *v2; // ST00_4

  v2 = this;
  this->m_RegCache.VoiceOn = ((pEnv->dwMode & 0xF) << 24) | this->m_RegCache.VoiceOn & 0xF0FFFFFF;
  v2->m_RegCache.CfgMISC = pEnv->dwRelease & 0xFFF | v2->m_RegCache.CfgMISC & 0xFFFFF000;
  v2->m_RegCache.CfgENV0 = (pEnv->lPitchScale << 24) | v2->m_RegCache.CfgENV0 & 0xFFFFFF;
  v2->m_RegCache.CfgENV1 = pEnv->dwAttack & 0xFFF | v2->m_RegCache.CfgENV1 & 0xFFFFF000;
  v2->m_RegCache.CfgENV1 = ((pEnv->dwDelay & 0xFFF) << 12) | v2->m_RegCache.CfgENV1 & 0xFF000FFF;
  v2->m_RegCache.CfgENV1 = (pEnv->lFilterCutOff << 24) | v2->m_RegCache.CfgENV1 & 0xFFFFFF;
  v2->m_RegCache.CfgENVF = pEnv->dwDecay & 0xFFF | v2->m_RegCache.CfgENVF & 0xFFFFF000;
  v2->m_RegCache.CfgENVF = ((pEnv->dwHold & 0xFFF) << 12) | v2->m_RegCache.CfgENVF & 0xFF000FFF;
  v2->m_RegCache.CfgENVF = (pEnv->dwSustain << 24) | v2->m_RegCache.CfgENVF & 0xFFFFFF;
}