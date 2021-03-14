void __thiscall CMcpxBufferSgeHeap::CMcpxBufferSgeHeap(CMcpxBufferSgeHeap *this)
{
  CMcpxBufferSgeHeap *v1; // ST00_4

  v1 = this;
  CHeap<_SGEHEAPRUNMARKER>::CHeap<_SGEHEAPRUNMARKER>((CHeap<_SGEHEAPRUNMARKER> *)&this->vfptr);
  v1->vfptr = (CHeap<_SGEHEAPRUNMARKER>Vtbl *)&CMcpxBufferSgeHeap::`vftable';
}