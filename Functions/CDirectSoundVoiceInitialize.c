void __stdcall CDirectSoundVoice::Initialize(CDirectSoundVoice *this, CMcpxVoiceClient *pVoice, CDirectSoundVoiceSettings *pSettings)
{
  this->m_pVoice = (CMcpxVoiceClient *)__AddRef((CMcpxAPU *)pVoice);
  this->m_pSettings = (CDirectSoundVoiceSettings *)__AddRef((CMcpxAPU *)pSettings);
}