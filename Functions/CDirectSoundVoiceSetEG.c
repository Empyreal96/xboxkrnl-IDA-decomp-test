int __stdcall CDirectSoundVoice::SetEG(CDirectSoundVoice *this, _DSENVELOPEDESC *pEnv)
{
  int v2; // eax
  int v3; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v2 = CMcpxVoiceClient::SetEG(this->m_pVoice, pEnv);
  hr = v2;
  v3 = v2;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v3;
}