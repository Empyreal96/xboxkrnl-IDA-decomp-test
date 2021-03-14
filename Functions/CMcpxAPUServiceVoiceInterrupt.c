void __thiscall CMcpxAPU::ServiceVoiceInterrupt(CMcpxAPU *this)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-1Ch]
  _LIST_ENTRY *plstActiveVoices; // [esp+4h] [ebp-18h]
  unsigned int dwVoiceList; // [esp+8h] [ebp-14h]
  CMcpxVoiceClient *pClient; // [esp+Ch] [ebp-10h]
  _LIST_ENTRY lstActiveVoices; // [esp+10h] [ebp-Ch]
  _LIST_ENTRY *pEntry; // [esp+18h] [ebp-4h]

  thisa = this;
  lstActiveVoices.Blink = &lstActiveVoices;
  lstActiveVoices.Flink = &lstActiveVoices;
  CMcpxAPU::WaitForMagicWrite(this);
  CMcpxAPU::BlockIdleHandler(thisa);
  for ( dwVoiceList = 0; dwVoiceList < 3; ++dwVoiceList )
  {
    plstActiveVoices = &thisa->m_alstActiveVoices[dwVoiceList];
    pEntry = plstActiveVoices->Flink;
    while ( pEntry != plstActiveVoices )
    {
      ((void (__thiscall *)(_LIST_ENTRY **))pEntry[-24].Blink[2].Blink)(&pEntry[-24].Blink);
      if ( IsListEmpty(pEntry) )
        pEntry = plstActiveVoices->Flink;
      else
        pEntry = pEntry->Flink;
    }
  }
  while ( 1 )
  {
    pEntry = thisa->m_lstPendingInactiveVoices.Flink;
    if ( pEntry == &thisa->m_lstPendingInactiveVoices )
      break;
    pClient = (CMcpxVoiceClient *)&pEntry[-25].Blink;
    ((void (__thiscall *)(_LIST_ENTRY **))pEntry[-25].Blink[2].Blink)(&pEntry[-25].Blink);
    if ( pClient->m_lePendingInactiveVoice.Flink != &pClient->m_lePendingInactiveVoice )
      RemoveEntryList(&pClient->m_lePendingInactiveVoice);
  }
  CMcpxAPU::UnblockIdleHandler(thisa);
}