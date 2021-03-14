int __thiscall CMcpxVoiceClient::SetEG(CMcpxVoiceClient *this, _DSENVELOPEDESC *pEnv)
{
  unsigned int v2; // eax
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( pEnv->dwEG )
  {
    if ( pEnv->dwEG == 1 )
      CMcpxVoiceClient::SetENVA(thisa, pEnv);
  }
  else
  {
    CMcpxVoiceClient::SetENVF(thisa, pEnv);
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
      MEMORY[0xFE82036C] = thisa->m_RegCache.LFOENV;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}