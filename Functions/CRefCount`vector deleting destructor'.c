CRefCount *__thiscall CRefCount::`vector deleting destructor'(CRefCount *this, unsigned int a2)
{
  CRefCount *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CRefCount::~CRefCount(this);
  if ( a2 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}