int __thiscall CMcpxVoiceClient::Initialize(CMcpxVoiceClient *this, CDirectSoundVoiceSettings *pSettings, int fStream)
{
  int v4; // [esp+4h] [ebp-8h]
  CMcpxVoiceClient *thisa; // [esp+8h] [ebp-4h]

  thisa = this;
  this->m_pSettings = (CDirectSoundVoiceSettings *)__AddRef((CMcpxAPU *)pSettings);
  v4 = thisa->m_pSettings->m_pwfxFormat->wFormatTag;
  if ( v4 == 1 )
  {
    switch ( thisa->m_pSettings->m_pwfxFormat->wBitsPerSample )
    {
      case 8u:
        thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT;
        thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT;
        break;
      case 0x10u:
        thisa->m_RegCache.CfgFMT |= 0x40000000u;
        thisa->m_RegCache.CfgFMT |= 0x10000000u;
        break;
      case 0x18u:
        thisa->m_RegCache.CfgFMT |= 0xC0000000;
        thisa->m_RegCache.CfgFMT |= 0x20000000u;
        break;
      case 0x20u:
        thisa->m_RegCache.CfgFMT |= 0xC0000000;
        thisa->m_RegCache.CfgFMT |= 0x30000000u;
        break;
      default:
        break;
    }
  }
  else if ( v4 == 105 )
  {
    thisa->m_RegCache.CfgFMT |= 0x80000000;
  }
  if ( thisa->m_pSettings->m_pwfxFormat->nChannels == 1 )
    thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT;
  else
    thisa->m_RegCache.CfgFMT |= 0x8000000u;
  if ( thisa->m_pSettings->m_dwFlags & 0x2000 )
    thisa->m_RegCache.CfgFMT |= 0x1F0000u;
  else
    thisa->m_RegCache.CfgFMT |= (((unsigned __int8)thisa->m_pSettings->m_pwfxFormat->nChannels - 1) & 0x1F) << 16;
  if ( fStream )
    thisa->m_RegCache.CfgFMT |= 0x1000000u;
  else
    thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT;
  if ( thisa->m_pSettings->m_dwFlags & 0x2000 )
  {
    thisa->m_RegCache.CfgFMT |= 0x200000u;
    thisa->m_RegCache.CfgFMT |= 0x4000000u;
  }
  thisa->m_RegCache.CfgMISC |= 0x800000u;
  if ( thisa->m_pSettings->m_dwFlags & 0x82000 )
    thisa->m_RegCache.CfgFMT = thisa->m_RegCache.CfgFMT;
  else
    thisa->m_RegCache.CfgFMT |= 0xE000u;
  if ( thisa->m_pSettings->m_dwFlags & 0x10 )
    InsertTailList(&thisa->m_pMcpxApu->m_lst3dVoices, &thisa->m_le3dVoice);
  return 0;
}