unsigned int __thiscall CMcpxVoiceClient::GetVoiceCfgFMT(CMcpxVoiceClient *this, unsigned int dwVoiceIndex)
{
  unsigned int dwCfgFMT; // [esp+4h] [ebp-4h]

  dwCfgFMT = this->m_RegCache.CfgFMT;
  if ( dwVoiceIndex )
    dwCfgFMT |= 0x400000u;
  return dwCfgFMT;
}