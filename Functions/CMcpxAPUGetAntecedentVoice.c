void __thiscall CMcpxAPU::GetAntecedentVoice(CMcpxAPU *this, CMcpxVoiceClient *pVoice, unsigned int *pdwVoiceList, CMcpxVoiceClient **ppAntecedentVoice)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-10h]
  _LIST_ENTRY *pleAntecedentVoice; // [esp+8h] [ebp-8h]
  CMcpxBuffer *pSubMixDestination; // [esp+Ch] [ebp-4h]

  thisa = this;
  pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(pVoice);
  if ( pSubMixDestination )
  {
    *pdwVoiceList = 2;
    pleAntecedentVoice = pSubMixDestination->m_leActiveVoice.Blink;
    if ( &thisa->m_alstActiveVoices[2] == pleAntecedentVoice )
      *ppAntecedentVoice = 0;
    else
      *ppAntecedentVoice = (CMcpxVoiceClient *)&pleAntecedentVoice[-24].Blink;
  }
  else if ( pVoice->m_pSettings->m_dwFlags & 0x82000 )
  {
    *pdwVoiceList = 2;
    *ppAntecedentVoice = 0;
  }
  else
  {
    if ( pVoice->m_pSettings->m_dwFlags & 0x10 )
      *pdwVoiceList = 1;
    else
      *pdwVoiceList = 0;
    *ppAntecedentVoice = 0;
  }
}