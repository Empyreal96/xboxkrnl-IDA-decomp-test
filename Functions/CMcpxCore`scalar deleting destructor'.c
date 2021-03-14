CMcpxCore *__userpurge CMcpxCore::`scalar deleting destructor'@<eax>(CMcpxCore *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int a4)
{
  CMcpxCore *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxCore::~CMcpxCore(this, a2, a3);
  if ( a4 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}