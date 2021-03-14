CDirectSoundVoice *__thiscall CDirectSoundVoice::`scalar deleting destructor'(CDirectSoundVoice *this, unsigned int a2)
{
  CDirectSoundVoice *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSoundVoice::~CDirectSoundVoice(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}