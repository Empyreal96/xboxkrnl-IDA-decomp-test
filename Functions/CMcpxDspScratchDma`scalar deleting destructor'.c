CMcpxDspScratchDma *__userpurge CMcpxDspScratchDma::`scalar deleting destructor'@<eax>(CMcpxDspScratchDma *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int a4)
{
  CMcpxDspScratchDma *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxDspScratchDma::~CMcpxDspScratchDma(this, a2, a3);
  if ( a4 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}