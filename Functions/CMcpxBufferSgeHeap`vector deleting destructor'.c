CMcpxBufferSgeHeap *__userpurge CMcpxBufferSgeHeap::`vector deleting destructor'@<eax>(CMcpxBufferSgeHeap *this@<ecx>, int *a2@<edi>, unsigned int a3)
{
  CMcpxBufferSgeHeap *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxBufferSgeHeap::~CMcpxBufferSgeHeap(this, a2);
  if ( a3 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}