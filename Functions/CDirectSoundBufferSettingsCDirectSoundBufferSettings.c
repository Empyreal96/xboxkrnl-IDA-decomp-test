void __thiscall CDirectSoundBufferSettings::CDirectSoundBufferSettings(CDirectSoundBufferSettings *this)
{
  CDirectSoundBufferSettings *v1; // ST00_4

  v1 = this;
  CDirectSoundVoiceSettings::CDirectSoundVoiceSettings((CDirectSoundVoiceSettings *)&this->vfptr);
  v1->vfptr = (CRefCountVtbl *)&CDirectSoundBufferSettings::`vftable';
}