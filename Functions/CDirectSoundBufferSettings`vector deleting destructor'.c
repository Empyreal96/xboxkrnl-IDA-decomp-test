CDirectSoundBufferSettings *__userpurge CDirectSoundBufferSettings::`vector deleting destructor'@<eax>(CDirectSoundBufferSettings *this@<ecx>, int a2@<esi>, unsigned int a3)
{
  CDirectSoundBufferSettings *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSoundBufferSettings::~CDirectSoundBufferSettings(this, a2);
  if ( a3 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}