int __userpurge CHeap<_SGEHEAPRUNMARKER>::Initialize@<eax>(CHeap<_SGEHEAPRUNMARKER> *this@<ecx>, int a2@<esi>, unsigned __int16 wElementCount)
{
  CHeap<_SGEHEAPRUNMARKER> *thisa; // [esp+0h] [ebp-Ch]
  int hr; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  thisa = this;
  this->m_wFreeElementCount = wElementCount;
  this->m_paMarkers = (_SGEHEAPRUNMARKER *)PhysicalAlloc(a2, 20 * (wElementCount + 1), 0x1000u, 4u, 0);
  hr = thisa->m_paMarkers != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
  {
    thisa->m_paMarkers->wElement = 0;
    thisa->m_paMarkers->wLength = wElementCount;
    CList<_SGEHEAPRUNMARKER>::AddNode(&thisa->m_lstFree, thisa->m_paMarkers);
  }
  if ( hr >= 0 )
  {
    for ( i = 1; i < (unsigned int)wElementCount + 1; ++i )
      CList<_SGEHEAPRUNMARKER>::AddNode(&thisa->m_lstMarkers, &thisa->m_paMarkers[i]);
  }
  return hr;
}