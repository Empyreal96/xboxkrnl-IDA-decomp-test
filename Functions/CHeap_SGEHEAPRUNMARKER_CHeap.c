void __thiscall CHeap<_SGEHEAPRUNMARKER>::CHeap<_SGEHEAPRUNMARKER>(CHeap<_SGEHEAPRUNMARKER> *this)
{
  CHeap<_SGEHEAPRUNMARKER> *v1; // ST00_4

  v1 = this;
  this->vfptr = (CHeap<_SGEHEAPRUNMARKER>Vtbl *)&CHeap<_SGEHEAPRUNMARKER>::`vftable';
  CMcpxDspImage::CMcpxDspImage(&this->m_lstFree);
  CMcpxDspImage::CMcpxDspImage(&v1->m_lstAllocated);
  CMcpxDspImage::CMcpxDspImage(&v1->m_lstMarkers);
}