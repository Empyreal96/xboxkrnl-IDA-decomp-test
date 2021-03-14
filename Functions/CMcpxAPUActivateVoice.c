void __thiscall CMcpxAPU::ActivateVoice(CMcpxAPU *this, CMcpxVoiceClient *pVoice, CMcpxVoiceClient *pAntecedentVoice, unsigned int dwVoiceList)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  CMcpxAPU::BlockIdleHandler(this);
  if ( pAntecedentVoice )
    InsertHeadList(&pAntecedentVoice->m_leActiveVoice, &pVoice->m_leActiveVoice);
  else
    InsertHeadList(&thisa->m_alstActiveVoices[dwVoiceList], &pVoice->m_leActiveVoice);
  pVoice->m_bVoiceList = dwVoiceList;
  CMcpxAPU::UnblockIdleHandler(thisa);
}