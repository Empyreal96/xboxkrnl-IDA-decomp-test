int __stdcall CDirectSoundVoice::SetPitch(CDirectSoundVoice *this, int lPitch)
{
  int v2; // eax
  int v3; // ST00_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  this->m_pSettings->m_lPitch = lPitch;
  v2 = CMcpxVoiceClient::SetPitch(this->m_pVoice);
  hr = v2;
  v3 = v2;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v3;
}