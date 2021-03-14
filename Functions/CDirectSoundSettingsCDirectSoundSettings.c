void __thiscall CDirectSoundSettings::CDirectSoundSettings(CDirectSoundSettings *this)
{
  CDirectSoundSettings *v1; // ST04_4

  v1 = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  v1->vfptr = (CRefCountVtbl *)&CDirectSoundSettings::`vftable';
  v1->m_dwSpeakerConfig = 0;
  CDirectSoundSettings::SetEffectImageLocations(v1, 0);
}