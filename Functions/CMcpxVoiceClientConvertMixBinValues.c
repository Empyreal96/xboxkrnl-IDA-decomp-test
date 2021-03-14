void __thiscall CMcpxVoiceClient::ConvertMixBinValues(CMcpxVoiceClient *this, unsigned int *pdwVoiceBins, unsigned int *pdwVoiceFormat)
{
  CMcpxVoiceClient *thisa; // [esp+0h] [ebp-34h]
  unsigned int adwMixBinMask[8]; // [esp+4h] [ebp-30h]
  unsigned int dwMixBinMask; // [esp+24h] [ebp-10h]
  CMcpxBuffer *pSubMixDestination; // [esp+28h] [ebp-Ch]
  unsigned int dwCount; // [esp+2Ch] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-4h]

  thisa = this;
  pSubMixDestination = CMcpxVoiceClient::GetSubMixDestination(this);
  if ( pSubMixDestination )
    dwMixBinMask = pSubMixDestination->m_pSettings->m_dwInputMixBinMask;
  else
    dwMixBinMask = thisa->m_pSettings->m_dwMixBinMask;
  i = 0;
  dwCount = 0;
  while ( i < 0x20 && dwCount < 8 )
  {
    if ( (1 << i) & dwMixBinMask )
      adwMixBinMask[dwCount++] = i;
    ++i;
  }
  for ( i = 0; i < 0x20 && dwCount < 8; ++i )
  {
    if ( !((1 << i) & dwMixBinMask) )
      adwMixBinMask[dwCount++] = i;
  }
  *pdwVoiceBins = 0;
  for ( i = 0; i < 3; ++i )
    *pdwVoiceBins |= adwMixBinMask[i] << 5 * i;
  while ( i < 6 )
  {
    *pdwVoiceBins |= adwMixBinMask[i] << (5 * i + 1);
    ++i;
  }
  *pdwVoiceFormat &= 0xFFFFFC00;
  while ( i < 8 )
  {
    *pdwVoiceFormat |= adwMixBinMask[i] << 5 * (i - 6);
    ++i;
  }
}