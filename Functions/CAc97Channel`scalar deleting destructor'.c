CAc97Channel *__userpurge CAc97Channel::`scalar deleting destructor'@<eax>(CAc97Channel *this@<ecx>, int *a2@<edi>, unsigned int a3)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CAc97Channel::~CAc97Channel(this, a2);
  if ( a3 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}