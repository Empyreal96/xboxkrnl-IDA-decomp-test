void __thiscall CMcpxAPU::FreeVoices(CMcpxAPU *this, CMcpxVoiceClient *pVoice)
{
  unsigned int v2; // esi
  CMcpxAPU *thisa; // [esp+4h] [ebp-14h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-10h]
  unsigned int dwVoiceIndex; // [esp+10h] [ebp-8h]
  unsigned __int16 i; // [esp+14h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CMcpxAPU::BlockIdleHandler(thisa);
  for ( i = 0; ; ++i )
  {
    v2 = i;
    if ( v2 >= CMcpxVoiceClient::GetHwVoiceCount(pVoice) || pVoice->m_ahVoices[i] == (void *)-1 )
      break;
    dwVoiceIndex = (unsigned int)pVoice->m_ahVoices[i];
    pVoice->m_ahVoices[i] = (void *)-1;
    thisa->m_apVoiceMap[dwVoiceIndex] = 0;
    if ( dwVoiceIndex >= 0x40 )
      ++thisa->m_wFree2dVoiceCount;
    else
      ++thisa->m_wFree3dVoiceCount;
  }
  CMcpxAPU::UnblockIdleHandler(thisa);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}