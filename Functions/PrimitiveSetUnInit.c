void __thiscall PrimitiveSet::UnInit(PrimitiveSet *this)
{
  PrimitiveSet *v1; // esi

  v1 = this;
  if ( this->pBaseStream )
  {
    D3DResource_Release(0, (D3DResource *)&this->pBaseStream->Common);
    v1->pBaseStream = 0;
  }
  if ( v1->pExtraStream )
  {
    D3DResource_Release(0, (D3DResource *)&v1->pExtraStream->Common);
    v1->pExtraStream = 0;
  }
  if ( v1->pIB )
  {
    D3DResource_Release(0, (D3DResource *)&v1->pIB->Common);
    v1->pIB = 0;
  }
  if ( v1->aInstRecs )
  {
    MemFree(v1->aInstRecs);
    v1->aInstRecs = 0;
  }
  if ( v1->aVersRecs )
  {
    MemFree(v1->aVersRecs);
    v1->aVersRecs = 0;
  }
  v1->nInstances = 0;
  v1->nVersions = 0;
}