CMcpxGPDspManager *__userpurge CMcpxGPDspManager::`scalar deleting destructor'@<eax>(CMcpxGPDspManager *this@<ecx>, int *a2@<edi>, int a3@<esi>, unsigned int a4)
{
  CMcpxGPDspManager *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CMcpxGPDspManager::~CMcpxGPDspManager(this, a2, a3);
  if ( a4 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}