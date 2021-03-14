unsigned int __stdcall CRefCount::Release(CRefCount *this)
{
  unsigned int v1; // ST08_4
  CAutoLock __AutoLock; // [esp+10h] [ebp-8h]
  unsigned int ulRefCount; // [esp+14h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  ulRefCount = --this->m_ulRefCount;
  if ( !ulRefCount && this )
    this->vfptr->__vecDelDtor(this, 1u);
  v1 = ulRefCount;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v1;
}