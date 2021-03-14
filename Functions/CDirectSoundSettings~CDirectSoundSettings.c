void __thiscall CDirectSoundSettings::~CDirectSoundSettings(CDirectSoundSettings *this)
{
  this->vfptr = (CRefCountVtbl *)&CDirectSoundSettings::`vftable';
  CRefCount::~CRefCount((CRefCount *)&this->vfptr);
}