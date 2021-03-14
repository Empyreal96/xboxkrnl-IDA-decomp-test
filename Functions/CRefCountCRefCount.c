void __thiscall CRefCount::CRefCount(CRefCount *this, unsigned int ulRefCount)
{
  this->vfptr = (CRefCountVtbl *)&CRefCount::`vftable';
  this->m_ulRefCount = ulRefCount;
}