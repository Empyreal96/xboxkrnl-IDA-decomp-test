void __usercall CMcpxBufferSgeHeap::~CMcpxBufferSgeHeap(CMcpxBufferSgeHeap *this@<ecx>, int *a2@<edi>)
{
  this->vfptr = (CHeap<_SGEHEAPRUNMARKER>Vtbl *)&CMcpxBufferSgeHeap::`vftable';
  CHeap<_SGEHEAPRUNMARKER>::~CHeap<_SGEHEAPRUNMARKER>((CHeap<_SGEHEAPRUNMARKER> *)&this->vfptr, a2);
}