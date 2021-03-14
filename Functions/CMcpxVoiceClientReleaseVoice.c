void __thiscall CMcpxVoiceClient::ReleaseVoice(CMcpxVoiceClient *this)
{
  unsigned int v1; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( (thisa->m_dwStatus & 3) == 3 )
  {
    for ( i = 0; ; ++i )
    {
      v1 = CMcpxVoiceClient::GetHwVoiceCount(thisa);
      if ( i >= v1 )
        break;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE82012C] = thisa->m_ahVoices[i];
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}