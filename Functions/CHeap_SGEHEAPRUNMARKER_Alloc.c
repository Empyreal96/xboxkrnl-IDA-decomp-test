_SGEHEAPRUNMARKER *__thiscall CHeap<_SGEHEAPRUNMARKER>::Alloc(CHeap<_SGEHEAPRUNMARKER> *this, unsigned __int16 wElementCount)
{
  CHeap<_SGEHEAPRUNMARKER> *thisa; // [esp+0h] [ebp-Ch]
  _SGEHEAPRUNMARKER *pRunMarker; // [esp+4h] [ebp-8h]
  _SGEHEAPRUNMARKER *pMarkerNode; // [esp+8h] [ebp-4h]
  _SGEHEAPRUNMARKER *pMarkerNodea; // [esp+8h] [ebp-4h]

  thisa = this;
  pRunMarker = 0;
  if ( wElementCount <= (signed int)this->m_wFreeElementCount )
  {
    for ( pMarkerNode = CList<_SGEHEAPRUNMARKER>::GetListHead(&this->m_lstFree);
          pMarkerNode;
          pMarkerNode = pMarkerNode->pNext )
    {
      if ( pMarkerNode->wLength >= (signed int)wElementCount
        && (!pRunMarker || pRunMarker->wLength > (signed int)pMarkerNode->wLength) )
      {
        pRunMarker = pMarkerNode;
      }
    }
  }
  if ( pRunMarker )
  {
    pMarkerNodea = pRunMarker;
    pRunMarker = CList<_SGEHEAPRUNMARKER>::GetListHead(&thisa->m_lstMarkers);
    CList<_SGEHEAPRUNMARKER>::RemoveNode(&thisa->m_lstMarkers, pRunMarker);
    pRunMarker->wElement = pMarkerNodea->wElement;
    pRunMarker->wLength = wElementCount;
    CList<_SGEHEAPRUNMARKER>::AddNode(&thisa->m_lstAllocated, pRunMarker);
    if ( pMarkerNodea->wLength <= (signed int)wElementCount )
    {
      CList<_SGEHEAPRUNMARKER>::RemoveNode(&thisa->m_lstFree, pMarkerNodea);
      CList<_SGEHEAPRUNMARKER>::AddNode(&thisa->m_lstMarkers, pMarkerNodea);
    }
    else
    {
      pMarkerNodea->wElement += wElementCount;
      pMarkerNodea->wLength -= wElementCount;
    }
    thisa->m_wFreeElementCount -= wElementCount;
  }
  return pRunMarker;
}