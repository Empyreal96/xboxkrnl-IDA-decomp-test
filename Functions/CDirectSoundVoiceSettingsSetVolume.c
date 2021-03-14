void __thiscall CDirectSoundVoiceSettings::SetVolume(CDirectSoundVoiceSettings *this, int lVolume)
{
  this->m_lVolume = lVolume - this->m_dwHeadroom;
}