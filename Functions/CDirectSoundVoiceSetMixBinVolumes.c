int __stdcall CDirectSoundVoice::SetMixBinVolumes(CDirectSoundVoice *this, unsigned int dwMixBinMask, const int *alVolumes)
{
  int v3; // eax
  int v4; // ST04_4
  int v6; // [esp+0h] [ebp-1Ch]
  CAutoLock __AutoLock; // [esp+8h] [ebp-14h]
  int hr; // [esp+Ch] [ebp-10h]
  unsigned int dwDestVolumeIndex; // [esp+10h] [ebp-Ch]
  unsigned int dwSourceVolumeIndex; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]

  dwSourceVolumeIndex = 0;
  dwDestVolumeIndex = 0;
  CAutoLock::CAutoLock(&__AutoLock);
  for ( i = 0; i < 0x20; ++i )
  {
    if ( (1 << i) & dwMixBinMask )
    {
      if ( alVolumes )
        v6 = alVolumes[dwSourceVolumeIndex];
      else
        v6 = 0;
      this->m_pSettings->m_alMixBinVolumes[dwDestVolumeIndex] = v6;
      ++dwSourceVolumeIndex;
    }
    if ( (1 << i) & this->m_pSettings->m_dwMixBinMask )
      ++dwDestVolumeIndex;
  }
  v3 = CMcpxVoiceClient::SetMixBinVolumes(this->m_pVoice);
  hr = v3;
  v4 = v3;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v4;
}