unsigned int __stdcall CRefCount::AddRef(CRefCount *this)
{
  unsigned int v1; // ST00_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  unsigned int ulRefCount; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  ulRefCount = ++this->m_ulRefCount;
  v1 = ulRefCount;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v1;
}