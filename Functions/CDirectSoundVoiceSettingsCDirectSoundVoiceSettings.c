void __thiscall CDirectSoundVoiceSettings::CDirectSoundVoiceSettings(CDirectSoundVoiceSettings *this)
{
  CDirectSoundVoiceSettings *v1; // ST04_4

  v1 = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  v1->vfptr = (CRefCountVtbl *)&CDirectSoundVoiceSettings::`vftable';
}