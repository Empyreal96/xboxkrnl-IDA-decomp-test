CHeap<_SGEHEAPRUNMARKER> *__userpurge CHeap<_SGEHEAPRUNMARKER>::`vector deleting destructor'@<eax>(CHeap<_SGEHEAPRUNMARKER> *this@<ecx>, int *a2@<edi>, unsigned int a3)
{
  CHeap<_SGEHEAPRUNMARKER> *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  CHeap<_SGEHEAPRUNMARKER>::~CHeap<_SGEHEAPRUNMARKER>(this, a2);
  if ( a3 & 1 )
    CRefCount::operator delete(thisa);
  return thisa;
}