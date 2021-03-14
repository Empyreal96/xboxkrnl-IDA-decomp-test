void __thiscall CMcpxBufferSgeHeap::Free(CMcpxBufferSgeHeap *this, _SGEHEAPRUNMARKER *pRunMarker)
{
  int v2; // ecx
  CMcpxBufferSgeHeap *thisa; // [esp+0h] [ebp-Ch]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  v2 = (unsigned __int8)pRunMarker->bRefCount--;
  if ( !v2 )
    CHeap<_SGEHEAPRUNMARKER>::Free((CHeap<_SGEHEAPRUNMARKER> *)&thisa->vfptr, pRunMarker);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}