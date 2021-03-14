void __usercall CMcpxVoiceClient::ActivateVoice(CMcpxVoiceClient *this@<ecx>, int *a2@<edi>, int a3@<esi>)
{
  unsigned int v3; // eax
  int v4; // eax
  volatile unsigned int v5; // edx
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-2Ch]
  CMcpxVoiceClient *pAntecedentVoice; // [esp+4h] [ebp-28h]
  unsigned int dwVoiceList; // [esp+8h] [ebp-24h]
  unsigned int dwAntecedentVoice; // [esp+Ch] [ebp-20h]
  CMcpxBuffer *pSubMixDestination; // [esp+10h] [ebp-1Ch]
  void *hAntecedentVoice; // [esp+14h] [ebp-18h]
  unsigned int dwVoicePause; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  unsigned int dwVoiceOn; // [esp+20h] [ebp-Ch]
  CIrql irql; // [esp+24h] [ebp-8h]

  thisa = this;
  if ( !(this->m_dwStatus & 2) )
  {
    CMcpxVoiceClient::WaitForVoiceOff(this);
    thisa->m_dwStatus |= 2u;
    CIrql::Raise(&irql);
    pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(thisa);
    if ( pSubMixDestination )
      CMcpxBuffer::Play(pSubMixDestination, a2, a3, 1);
    while ( MEMORY[0xFE820010] < 0x80u )
      ;
    CMcpxAPU::BlockIdleHandler(thisa->m_pMcpxApu);
    for ( i = 0; i < 4; ++i )
      CMcpxVoiceClient::SetNotifierStatus(thisa, i, 0);
    if ( thisa->m_dwStatus & 0x80 )
      v3 = thisa->m_RegCache.CfgFMT & 0xFF7FFFFF | 0x800000;
    else
      v3 = thisa->m_RegCache.CfgFMT & 0xFF7FFFFF;
    thisa->m_RegCache.CfgFMT = v3;
    CMcpxAPU::GetAntecedentVoice(thisa->m_pMcpxApu, thisa, &dwVoiceList, &pAntecedentVoice);
    if ( pAntecedentVoice )
    {
      v4 = CMcpxVoiceClient::GetHwVoiceCount(pAntecedentVoice);
      hAntecedentVoice = (void *)*((_DWORD *)&pAntecedentVoice->m_pMcpxApu + v4);
      dwAntecedentVoice = (unsigned __int16)hAntecedentVoice;
    }
    else
    {
      dwAntecedentVoice = ((((_BYTE)dwVoiceList + 1) & 3) << 16) | 0xFFFF;
    }
    for ( i = CMcpxVoiceClient::GetHwVoiceCount(thisa) - 1; i >= 0; --i )
    {
      dwVoiceOn = (_DWORD)thisa->m_ahVoices[i] & 0xFFFF | thisa->m_RegCache.VoiceOn & 0xFFFF0000;
      if ( thisa->m_dwStatus & 4 )
        dwVoicePause = 0x40000;
      else
        dwVoicePause = 0;
      dwVoicePause |= (_DWORD)thisa->m_ahVoices[i] & 0xFFFF;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 1;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT(thisa, i);
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820120] = dwAntecedentVoice;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820124] = dwVoiceOn;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820140] = dwVoicePause;
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202FC] = 0;
    }
    CMcpxAPU::ActivateVoice(thisa->m_pMcpxApu, thisa, pAntecedentVoice, dwVoiceList);
    while ( MEMORY[0xFE820010] < 0x80u )
      ;
    CMcpxAPU::UnblockIdleHandler(thisa->m_pMcpxApu);
    CIrql::Lower(&irql);
    v5 = thisa->m_dwStatus;
  }
}