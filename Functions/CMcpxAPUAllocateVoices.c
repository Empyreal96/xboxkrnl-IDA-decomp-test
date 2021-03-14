int __thiscall CMcpxAPU::AllocateVoices(CMcpxAPU *this, CMcpxVoiceClient *pVoice)
{
  int v2; // ecx
  int v3; // edx
  int v4; // ST04_4
  CMcpxAPU *thisa; // [esp+0h] [ebp-28h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-20h]
  int hr; // [esp+10h] [ebp-18h]
  unsigned __int16 w3dVoiceCount; // [esp+14h] [ebp-14h]
  unsigned __int16 w2dVoiceCount; // [esp+18h] [ebp-10h]
  unsigned __int16 wVoiceIndex; // [esp+1Ch] [ebp-Ch]
  unsigned __int16 wVoiceCount; // [esp+20h] [ebp-8h]
  unsigned __int16 i; // [esp+24h] [ebp-4h]

  thisa = this;
  wVoiceIndex = 0;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CMcpxAPU::BlockIdleHandler(thisa);
  wVoiceCount = CMcpxVoiceClient::GetHwVoiceCount(pVoice);
  if ( pVoice->m_pSettings->m_dwFlags & 0x10 )
  {
    w2dVoiceCount = 0;
  }
  else if ( thisa->m_wFree2dVoiceCount < (signed int)wVoiceCount )
  {
    w2dVoiceCount = thisa->m_wFree2dVoiceCount;
  }
  else
  {
    w2dVoiceCount = wVoiceCount;
  }
  w3dVoiceCount = wVoiceCount - w2dVoiceCount;
  if ( thisa->m_wFree3dVoiceCount < (signed int)(unsigned __int16)(wVoiceCount - w2dVoiceCount) )
  {
    hr = -2005401550;
  }
  else
  {
    thisa->m_wFree2dVoiceCount -= w2dVoiceCount;
    thisa->m_wFree3dVoiceCount -= w3dVoiceCount;
LABEL_8:
    while ( 1 )
    {
      v2 = w2dVoiceCount--;
      if ( !v2 )
        break;
      for ( i = 64; (signed int)i < 256; ++i )
      {
        if ( !thisa->m_apVoiceMap[i] )
        {
          pVoice->m_ahVoices[wVoiceIndex++] = (void *)i;
          thisa->m_apVoiceMap[i] = pVoice;
          goto LABEL_8;
        }
      }
    }
LABEL_15:
    while ( 1 )
    {
      v3 = w3dVoiceCount--;
      if ( !v3 )
        break;
      for ( i = 0; (signed int)i < 64; ++i )
      {
        if ( !thisa->m_apVoiceMap[i] )
        {
          pVoice->m_ahVoices[wVoiceIndex++] = (void *)i;
          thisa->m_apVoiceMap[i] = pVoice;
          goto LABEL_15;
        }
      }
    }
    hr = 0;
  }
  CMcpxAPU::UnblockIdleHandler(thisa);
  v4 = hr;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v4;
}