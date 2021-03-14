CDirectSound *__thiscall CDirectSound::`vector deleting destructor'(CDirectSound *this, unsigned int a2)
{
  CDirectSound *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CDirectSound::~CDirectSound(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}