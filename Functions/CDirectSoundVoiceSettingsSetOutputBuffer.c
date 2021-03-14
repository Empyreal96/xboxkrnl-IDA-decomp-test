void __thiscall CDirectSoundVoiceSettings::SetOutputBuffer(CDirectSoundVoiceSettings *this, CDirectSoundBuffer *pOutputBuffer)
{
  CDirectSoundVoiceSettings *v2; // ST04_4

  v2 = this;
  __Release((CDirectSoundBufferSettings **)&this->m_pMixinBuffer);
  v2->m_pMixinBuffer = (CDirectSoundBuffer *)__AddRef((CMcpxAPU *)pOutputBuffer);
}