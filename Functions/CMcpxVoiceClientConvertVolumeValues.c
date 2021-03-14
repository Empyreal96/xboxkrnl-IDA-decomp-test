void __thiscall CMcpxVoiceClient::ConvertVolumeValues(CMcpxVoiceClient *this, MCPX_VOICE_VOLUME *pVolumeRegisters)
{
  int v2; // [esp+0h] [ebp-68h]
  CMcpxVoiceClient *thisa; // [esp+8h] [ebp-60h]
  unsigned int dwVoiceCount; // [esp+Ch] [ebp-5Ch]
  unsigned int dwMixBinCount; // [esp+10h] [ebp-58h]
  unsigned int dwMixBinMask; // [esp+14h] [ebp-54h]
  int dwPerVoiceBins; // [esp+18h] [ebp-50h]
  int alVolumes[8]; // [esp+20h] [ebp-48h]
  unsigned int adwVolumes[8]; // [esp+40h] [ebp-28h]
  unsigned int dwVoiceIndex; // [esp+60h] [ebp-8h]
  unsigned int i; // [esp+64h] [ebp-4h]

  thisa = this;
  if ( CMcpxVoiceClient::GetSubMixDestination(this) )
  {
    dwVoiceCount = 1;
    dwMixBinCount = 1;
  }
  else
  {
    dwVoiceCount = CMcpxVoiceClient::GetHwVoiceCount(thisa);
    dwMixBinMask = thisa->m_pSettings->m_dwMixBinMask;
    i = 0;
    dwMixBinCount = 0;
    while ( i < 0x20 )
    {
      if ( (1 << i) & dwMixBinMask )
        ++dwMixBinCount;
      ++i;
    }
  }
  dwPerVoiceBins = dwMixBinCount / dwVoiceCount;
  for ( dwVoiceIndex = 0; dwVoiceIndex < dwVoiceCount; ++dwVoiceIndex )
  {
    for ( i = 0; i < 8; ++i )
    {
      if ( i >= dwVoiceIndex * dwPerVoiceBins && i < (dwVoiceIndex + 1) * dwPerVoiceBins )
      {
        alVolumes[i] = thisa->m_pSettings->m_lVolume;
        if ( !CMcpxVoiceClient::GetSubMixDestination(thisa) )
        {
          alVolumes[i] += thisa->m_pSettings->m_alMixBinVolumes[i];
          if ( thisa->m_pSettings->m_dwFlags & 0x10 )
          {
            alVolumes[i] += thisa->m_3dData.lDistanceVolume;
            alVolumes[i] += thisa->m_3dData.lConeVolume;
            switch ( i )
            {
              case 0u:
              case 2u:
                alVolumes[i] += thisa->m_3dData.lFrontVolume;
                alVolumes[i] += thisa->m_I3dl2Data.lDirect;
                break;
              case 1u:
              case 3u:
                alVolumes[i] += thisa->m_3dData.lRearVolume;
                alVolumes[i] += thisa->m_I3dl2Data.lDirect;
                break;
              case 4u:
                alVolumes[i] += thisa->m_I3dl2Data.lSource;
                break;
              default:
                continue;
            }
          }
        }
      }
      else
      {
        alVolumes[i] = -10000;
      }
    }
    for ( i = 0; i < 8; ++i )
    {
      if ( -alVolumes[i] < 0 || alVolumes[i] == 0 )
        v2 = 0;
      else
        v2 = -alVolumes[i];
      adwVolumes[i] = v2;
      adwVolumes[i] <<= 6;
      adwVolumes[i] /= 0x64u;
      if ( adwVolumes[i] > 0xFFF )
        adwVolumes[i] = 4095;
    }
    pVolumeRegisters->TarVOLA[dwVoiceIndex] = 16 * (adwVolumes[0] & 0xFFF);
    pVolumeRegisters->TarVOLA[dwVoiceIndex] |= (adwVolumes[1] & 0xFFF) << 20;
    pVolumeRegisters->TarVOLA[dwVoiceIndex] |= adwVolumes[6] & 0xF;
    pVolumeRegisters->TarVOLA[dwVoiceIndex] |= (adwVolumes[7] & 0xF) << 16;
    pVolumeRegisters->TarVOLB[dwVoiceIndex] = 16 * (adwVolumes[2] & 0xFFF);
    pVolumeRegisters->TarVOLB[dwVoiceIndex] |= (adwVolumes[3] & 0xFFF) << 20;
    pVolumeRegisters->TarVOLB[dwVoiceIndex] |= (unsigned __int8)(LOBYTE(adwVolumes[6]) >> 4);
    pVolumeRegisters->TarVOLB[dwVoiceIndex] |= (unsigned __int8)(LOBYTE(adwVolumes[7]) >> 4) << 16;
    pVolumeRegisters->TarVOLC[dwVoiceIndex] = 16 * (adwVolumes[4] & 0xFFF);
    pVolumeRegisters->TarVOLC[dwVoiceIndex] |= (adwVolumes[5] & 0xFFF) << 20;
    pVolumeRegisters->TarVOLC[dwVoiceIndex] |= (adwVolumes[6] >> 8) & 0xF;
    pVolumeRegisters->TarVOLC[dwVoiceIndex] |= ((adwVolumes[7] >> 8) & 0xF) << 16;
  }
}