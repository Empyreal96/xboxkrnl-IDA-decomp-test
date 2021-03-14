int __userpurge CDirectSoundVoiceSettings::Initialize@<eax>(CDirectSoundVoiceSettings *this@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundSettings *pGlobalSettings, unsigned int dwFlags, tWAVEFORMATEX *pwfxFormat, unsigned int dwMixBinMask)
{
  CDirectSoundVoiceSettings *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  hr = 0;
  this->m_pGlobalSettings = (CDirectSoundSettings *)__AddRef((CMcpxAPU *)pGlobalSettings);
  thisa->m_dwFlags = dwFlags;
  if ( thisa->m_dwFlags & 0x82000 )
  {
    thisa->m_dwHeadroom = 0;
  }
  else if ( thisa->m_dwFlags & 0x10 )
  {
    thisa->m_dwHeadroom = 0;
  }
  else
  {
    thisa->m_dwHeadroom = 600;
  }
  if ( thisa->m_dwFlags & 0x82000 )
  {
    thisa->m_pwfxFormat = &CDirectSoundVoiceSettings::m_wfxMixDest;
  }
  else
  {
    thisa->m_pwfxFormat = CopyFormatAlloc(a3, pwfxFormat);
    hr = thisa->m_pwfxFormat != 0 ? 0 : 0x8007000E;
  }
  if ( hr >= 0 )
    CDirectSoundVoiceSettings::SetVolume(thisa, 0);
  if ( hr >= 0 )
    CDirectSoundVoiceSettings::SetMixBins(thisa, dwMixBinMask);
  if ( hr >= 0 )
    thisa->m_lPitch = XAudioCalculatePitch(a2, thisa->m_pwfxFormat->nSamplesPerSec);
  return hr;
}