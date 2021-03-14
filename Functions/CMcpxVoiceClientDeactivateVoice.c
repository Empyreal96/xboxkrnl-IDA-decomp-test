void __userpurge CMcpxVoiceClient::DeactivateVoice(CMcpxVoiceClient *this@<ecx>, int *a2@<edi>, int a3@<esi>, int fNaturalStop, int fBlock)
{
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-20h]
  CMcpxBuffer *pSubMixDestination; // [esp+4h] [ebp-1Ch]
  _LIST_ENTRY *pleListEntry; // [esp+8h] [ebp-18h]
  int fSourceValid; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+14h] [ebp-Ch]
  CIrql irql; // [esp+18h] [ebp-8h]

  thisa = this;
  if ( this->m_dwStatus & 1 && this->m_dwStatus & 0x10000002 )
  {
    CIrql::Raise(&irql);
    CMcpxAPU::BlockIdleHandler(thisa->m_pMcpxApu);
    thisa->m_RegCache.CfgFMT &= 0xFF7FFFFF;
    for ( i = 0; i < CMcpxVoiceClient::GetHwVoiceCount(thisa); ++i )
    {
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE8202F8] = thisa->m_ahVoices[i];
      while ( MEMORY[0xFE820010] < 4u )
        ;
      MEMORY[0xFE820304] = CMcpxVoiceClient::GetVoiceCfgFMT(thisa, i);
      if ( !fNaturalStop )
      {
        while ( MEMORY[0xFE820010] < 4u )
          ;
        MEMORY[0xFE820128] = thisa->m_ahVoices[i];
      }
    }
    thisa->m_dwStatus &= 0xC1u;
    if ( (unsigned __int8)thisa->m_bVoiceList == 255 )
      RemoveEntryList(&thisa->m_lePendingInactiveVoice);
    else
      thisa->m_dwStatus |= 0x10000000u;
    CMcpxAPU::UnblockIdleHandler(thisa->m_pMcpxApu);
    pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(thisa);
    if ( pSubMixDestination )
    {
      fSourceValid = 0;
      for ( pleListEntry = pSubMixDestination->m_lstSourceVoices.Flink;
            pleListEntry != &pSubMixDestination->m_lstSourceVoices;
            pleListEntry = pleListEntry->Flink )
      {
        if ( ((_DWORD)pleListEntry[-26].Blink & 3) == 3 )
        {
          fSourceValid = 1;
          break;
        }
      }
      if ( !fSourceValid )
        CMcpxBuffer::Stop(pSubMixDestination, a2, a3);
    }
    CIrql::Lower(&irql);
  }
  if ( fBlock )
    CMcpxVoiceClient::WaitForVoiceOff(thisa);
}