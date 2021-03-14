_SGEHEAPRUNMARKER *__thiscall CMcpxBufferSgeHeap::Alloc(CMcpxBufferSgeHeap *this, void *pvBufferBase, unsigned int dwBufferSize)
{
  _SGEHEAPRUNMARKER *v3; // ST08_4
  CMcpxBufferSgeHeap *thisa; // [esp+0h] [ebp-1Ch]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-14h]
  _SGEHEAPRUNMARKER *pRunMarker; // [esp+10h] [ebp-Ch]
  unsigned int dwElementCount; // [esp+14h] [ebp-8h]
  unsigned __int16 wElementCount; // [esp+18h] [ebp-4h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  dwElementCount = (((unsigned __int16)pvBufferBase & 0xFFF) + dwBufferSize + 4095) >> 12;
  wElementCount = dwElementCount;
  for ( pRunMarker = CList<_SGEHEAPRUNMARKER>::GetListHead(&thisa->m_lstAllocated);
        pRunMarker && (pvBufferBase != pRunMarker->pvBufferBase || wElementCount > (signed int)pRunMarker->wLength);
        pRunMarker = pRunMarker->pNext )
  {
    ;
  }
  if ( pRunMarker )
  {
    ++pRunMarker->bRefCount;
  }
  else
  {
    pRunMarker = CHeap<_SGEHEAPRUNMARKER>::Alloc((CHeap<_SGEHEAPRUNMARKER> *)&thisa->vfptr, wElementCount);
    if ( pRunMarker )
    {
      pRunMarker->bRefCount = 0;
      pRunMarker->pvBufferBase = pvBufferBase;
    }
  }
  v3 = pRunMarker;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return v3;
}