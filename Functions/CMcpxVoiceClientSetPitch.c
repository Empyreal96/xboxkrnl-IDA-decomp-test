int __thiscall CMcpxVoiceClient::SetPitch(CMcpxVoiceClient *this)
{
  unsigned int v1; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-20h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-18h]
  CMcpxVoiceClient *pSourceVoice; // [esp+10h] [ebp-10h]
  unsigned int dwPitch; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  _LIST_ENTRY *pleSourceVoice; // [esp+1Ch] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_pSettings->m_dwFlags & 0x82000 )
  {
    for ( pleSourceVoice = thisa->m_lstSourceVoices.Flink;
          pleSourceVoice != &thisa->m_lstSourceVoices;
          pleSourceVoice = pleSourceVoice->Flink )
    {
      pSourceVoice = CONTAINING_RECORD(pleSourceVoice, CMcpxVoiceClient, m_leSourceVoice);
      CMcpxVoiceClient::SetPitch((CMcpxVoiceClient *)&pleSourceVoice[-27].Blink);
    }
  }
  else if ( thisa->m_dwStatus & 1 )
  {
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
      MEMORY[0xFE82037C] = dwPitch;
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}