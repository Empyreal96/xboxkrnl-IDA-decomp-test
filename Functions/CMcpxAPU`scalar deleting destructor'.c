CMcpxAPU *__userpurge CMcpxAPU::`scalar deleting destructor'@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int a4)
{
  CMcpxAPU *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxAPU::~CMcpxAPU(this, a2, a3);
  if ( a4 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}