int __thiscall CMcpxVoiceClient::AllocateVoiceResources(CMcpxVoiceClient *this)
{
  unsigned int v1; // eax
  int v2; // ST0C_4
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-44h]
  unsigned int dwVoiceBins; // [esp+8h] [ebp-3Ch]
  CAutoIrql __AutoIrql; // [esp+Ch] [ebp-38h]
  int hr; // [esp+14h] [ebp-30h]
  MCPX_VOICE_VOLUME Volume; // [esp+18h] [ebp-2Ch]
  unsigned int dwPitch; // [esp+3Ch] [ebp-8h]
  unsigned int i; // [esp+40h] [ebp-4h]

  thisa = this;
  hr = 0;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( !(thisa->m_dwStatus & 1) )
  {
    hr = CMcpxAPU::AllocateVoices(thisa->m_pMcpxApu, thisa);
    if ( hr >= 0 )
      thisa->m_dwStatus |= 1u;
    if ( hr >= 0 )
      CMcpxVoiceClient::ConvertMixBinValues(thisa, &dwVoiceBins, &thisa->m_RegCache.CfgFMT);
    if ( hr >= 0 )
      CMcpxVoiceClient::ConvertVolumeValues(thisa, &Volume);
    if ( hr >= 0 )
      CMcpxVoiceClient::ConvertPitchValue(thisa, &dwPitch);
    if ( hr >= 0 )
    {
      for ( i = 0; ; ++i )
      {
        v1 = CMcpxVoiceClient::GetHwVoiceCount(thisa);
        if ( i >= v1 )
          break;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT(thisa, i);
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820318] = thisa->m_RegCache.CfgMISC;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820308] = thisa->m_RegCache.CfgENV0;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE82030C] = thisa->m_RegCache.CfgENVA;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820310] = thisa->m_RegCache.CfgENV1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820314] = thisa->m_RegCache.CfgENVF;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820350] = thisa->m_RegCache.CfgLFODLY;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE82036C] = thisa->m_RegCache.LFOENV;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820370] = thisa->m_RegCache.LFOMOD;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820374] = thisa->m_RegCache.TarFCA;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820378] = thisa->m_RegCache.TarFCB;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820300] = dwVoiceBins;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820360] = Volume.TarVOLA[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820364] = Volume.TarVOLB[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820368] = Volume.TarVOLC[i];
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE82037C] = dwPitch;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE82031C] = 0xFFFF;
      }
    }
  }
  v2 = hr;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v2;
}