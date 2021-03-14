int __thiscall CMcpxVoiceClient::SetVolume(CMcpxVoiceClient *this)
{
  unsigned int v1; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-38h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-30h]
  MCPX_VOICE_VOLUME Volume; // [esp+10h] [ebp-28h]
  unsigned int i; // [esp+34h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_dwStatus & 1 )
  {
    CMcpxVoiceClient::ConvertVolumeValues(thisa, &Volume);
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
      MEMORY[0xFE820360] = Volume.TarVOLA[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820364] = Volume.TarVOLB[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820368] = Volume.TarVOLC[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}