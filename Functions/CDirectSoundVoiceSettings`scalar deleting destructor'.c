CDirectSoundVoiceSettings *__thiscall CDirectSoundVoiceSettings::`scalar deleting destructor'(CDirectSoundVoiceSettings *this, unsigned int a2)
{
  CDirectSoundVoiceSettings *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSoundVoiceSettings::~CDirectSoundVoiceSettings(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}