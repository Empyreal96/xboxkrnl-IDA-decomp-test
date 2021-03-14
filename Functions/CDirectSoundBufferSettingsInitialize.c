int __userpurge CDirectSoundBufferSettings::Initialize@<eax>(CDirectSoundBufferSettings *this@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundSettings *pGlobalSettings, _DSBUFFERDESC *pdsbd)
{
  CDirectSoundBufferSettings *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  hr = CDirectSoundVoiceSettings::Initialize(
         (CDirectSoundVoiceSettings *)&this->vfptr,
         a2,
         a3,
         pGlobalSettings,
         pdsbd->dwFlags,
         pdsbd->lpwfxFormat,
         pdsbd->dwMixBinMask);
  if ( hr >= 0 )
  {
    if ( pdsbd->dwFlags & 0x80000 )
    {
      thisa->m_dwInputMixBinMask = pdsbd->dwInputMixBinMask;
    }
    else if ( pdsbd->dwFlags & 0x2000 )
    {
      thisa->m_dwInputMixBinMask = 2147483648;
    }
  }
  if ( hr >= 0 && pdsbd->dwBufferBytes )
    hr = CDirectSoundBufferSettings::SetBufferData(thisa, a3, 0, pdsbd->dwBufferBytes);
  return hr;
}