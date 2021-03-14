int __thiscall CMcpxVoiceClient::DisconnectVoice(CMcpxVoiceClient *this)
{
  unsigned int v1; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-48h]
  unsigned int dwVoiceBins; // [esp+8h] [ebp-40h]
  CAutoIrql __AutoIrql; // [esp+Ch] [ebp-3Ch]
  CMcpxBuffer *pSubMixDestination; // [esp+18h] [ebp-30h]
  MCPX_VOICE_VOLUME Volume; // [esp+1Ch] [ebp-2Ch]
  unsigned int dwPitch; // [esp+40h] [ebp-8h]
  unsigned int i; // [esp+44h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(thisa);
  if ( pSubMixDestination )
  {
    RemoveEntryList(&thisa->m_leSourceVoice);
    if ( thisa->m_dwStatus & 1 )
    {
      CMcpxVoiceClient::ConvertMixBinValues(thisa, &dwVoiceBins, &thisa->m_RegCache.CfgFMT);
      CMcpxVoiceClient::ConvertVolumeValues(thisa, &Volume);
      CMcpxVoiceClient::ConvertPitchValue(thisa, &dwPitch);
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
        MEMORY[0xFE8202FC] = 1;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820300] = dwVoiceBins;
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT(thisa, i);
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
        MEMORY[0xFE8202FC] = 0;
      }
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}