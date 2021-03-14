void __thiscall CHeap<_SGEHEAPRUNMARKER>::Free(CHeap<_SGEHEAPRUNMARKER> *this, _SGEHEAPRUNMARKER *pRunMarker)
{
  CHeap<_SGEHEAPRUNMARKER> *thisa; // [esp+0h] [ebp-8h]
  _SGEHEAPRUNMARKER *pMarkerNode; // [esp+4h] [ebp-4h]

  thisa = this;
  CList<_SGEHEAPRUNMARKER>::RemoveNode(&this->m_lstAllocated, pRunMarker);
  CList<_SGEHEAPRUNMARKER>::AddNode(&thisa->m_lstFree, pRunMarker);
  thisa->m_wFreeElementCount += pRunMarker->wLength;
  pMarkerNode = CList<_SGEHEAPRUNMARKER>::GetListHead(&thisa->m_lstFree);
  while ( pMarkerNode )
  {
    if ( pMarkerNode->wLength + pMarkerNode->wElement == pRunMarker->wElement )
    {
      pRunMarker = thisa->vfptr->CoalesceRuns(thisa, pMarkerNode, pRunMarker);
      pMarkerNode = CList<_SGEHEAPRUNMARKER>::GetListHead(&thisa->m_lstFree);
    }
    else if ( pRunMarker->wLength + pRunMarker->wElement == pMarkerNode->wElement )
    {
      pRunMarker = thisa->vfptr->CoalesceRuns(thisa, pRunMarker, pMarkerNode);
      pMarkerNode = CList<_SGEHEAPRUNMARKER>::GetListHead(&thisa->m_lstFree);
    }
    else
    {
      pMarkerNode = pMarkerNode->pNext;
    }
  }
}