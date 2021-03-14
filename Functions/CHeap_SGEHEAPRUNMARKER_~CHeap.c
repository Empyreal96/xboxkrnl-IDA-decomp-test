void __usercall CHeap<_SGEHEAPRUNMARKER>::~CHeap<_SGEHEAPRUNMARKER>(CHeap<_SGEHEAPRUNMARKER> *this@<ecx>, int *a2@<edi>)
{
  this->vfptr = (CHeap<_SGEHEAPRUNMARKER>Vtbl *)&CHeap<_SGEHEAPRUNMARKER>::`vftable';
  PhysicalFree(a2, (void **)&this->m_paMarkers);
}