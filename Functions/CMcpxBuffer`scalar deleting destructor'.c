CMcpxBuffer *__userpurge CMcpxBuffer::`scalar deleting destructor'@<eax>(CMcpxBuffer *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int a4)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxBuffer::~CMcpxBuffer(this, a2, a3);
  if ( a4 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}