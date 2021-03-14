CDirectSoundSettings *__thiscall CDirectSoundSettings::`scalar deleting destructor'(CDirectSoundSettings *this, unsigned int a2)
{
  CDirectSoundSettings *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSoundSettings::~CDirectSoundSettings(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}