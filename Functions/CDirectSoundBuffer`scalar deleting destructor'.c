CDirectSoundBuffer *__thiscall CDirectSoundBuffer::`scalar deleting destructor'(CDirectSoundBuffer *this, unsigned int a2)
{
  CDirectSoundBuffer *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSoundBuffer::~CDirectSoundBuffer(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}