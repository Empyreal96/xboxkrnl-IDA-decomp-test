int __stdcall CDirectSoundVoice::SetVolume(CDirectSoundVoice *this, int lVolume)
{
  int v2; // eax
  int v3; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  CDirectSoundVoiceSettings::SetVolume(this->m_pSettings, lVolume);
  v2 = CMcpxVoiceClient::SetVolume(this->m_pVoice);
  hr = v2;
  v3 = v2;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v3;
}