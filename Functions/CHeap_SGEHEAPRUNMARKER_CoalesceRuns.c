_SGEHEAPRUNMARKER *__thiscall CHeap<_SGEHEAPRUNMARKER>::CoalesceRuns(CHeap<_SGEHEAPRUNMARKER> *this, _SGEHEAPRUNMARKER *pMarker1, _SGEHEAPRUNMARKER *pMarker2)
{
  CHeap<_SGEHEAPRUNMARKER> *v3; // ST04_4

  v3 = this;
  pMarker1->wLength += pMarker2->wLength;
  CList<_SGEHEAPRUNMARKER>::RemoveNode(&this->m_lstFree, pMarker2);
  CList<_SGEHEAPRUNMARKER>::AddNode(&v3->m_lstMarkers, pMarker2);
  return pMarker1;
}