int __thiscall CMcpxVoiceClient::SetFilter(CMcpxVoiceClient *this, _DSFILTERDESC *pFilter)
{
  unsigned int v2; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-2Ch]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-24h]
  unsigned int i; // [esp+10h] [ebp-1Ch]
  _DSFILTERDESC Filter; // [esp+14h] [ebp-18h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( pFilter )
  {
    memcpy((char *)&Filter, (char *)pFilter, 0x18u);
  }
  else
  {
    Filter.dwMode = (thisa->m_RegCache.CfgMISC >> 16) & 3;
    Filter.dwQCoefficient = (thisa->m_RegCache.CfgMISC >> 18) & 7;
    Filter.adwCoefficients[0] = thisa->m_RegCache.TarFCA & 0xFFFF;
    Filter.adwCoefficients[1] = (unsigned __int16)(thisa->m_RegCache.TarFCA >> 16) >> 8;
    Filter.adwCoefficients[2] = thisa->m_RegCache.TarFCB & 0xFFFF;
    Filter.adwCoefficients[3] = (unsigned __int16)(thisa->m_RegCache.TarFCB >> 16) >> 8;
  }
  if ( thisa->m_pSettings->m_dwFlags & 0x10 && !Filter.dwMode )
    Filter.dwMode = 3;
  thisa->m_RegCache.CfgMISC = ((Filter.dwMode & 3) << 16) | thisa->m_RegCache.CfgMISC & 0xFFFCFFFF;
  thisa->m_RegCache.CfgMISC = ((Filter.dwQCoefficient & 7) << 18) | thisa->m_RegCache.CfgMISC & 0xFFE3FFFF;
  thisa->m_RegCache.TarFCA = LOWORD(Filter.adwCoefficients[0]);
  thisa->m_RegCache.TarFCA |= LOWORD(Filter.adwCoefficients[1]) << 16;
  if ( thisa->m_pSettings->m_dwFlags & 0x10 )
  {
    if ( thisa->m_3dBuffer.dwMode == 2 )
    {
      thisa->m_RegCache.TarFCB = 0;
    }
    else
    {
      thisa->m_RegCache.TarFCB = thisa->m_I3dl2Data.nDirectIir & 0xFFFF;
      thisa->m_RegCache.TarFCB |= thisa->m_I3dl2Data.nReverbIir << 16;
    }
  }
  else
  {
    thisa->m_RegCache.TarFCB = LOWORD(Filter.adwCoefficients[2]);
    thisa->m_RegCache.TarFCB |= LOWORD(Filter.adwCoefficients[3]) << 16;
  }
  if ( thisa->m_dwStatus & 1 )
  {
    for ( i = 0; ; ++i )
    {
      v2 = CMcpxVoiceClient::GetHwVoiceCount(thisa);
      if ( i >= v2 )
        break;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202F8] = thisa->m_ahVoices[0];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 1;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820318] = thisa->m_RegCache.CfgMISC;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820374] = thisa->m_RegCache.TarFCA;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820378] = thisa->m_RegCache.TarFCB;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}