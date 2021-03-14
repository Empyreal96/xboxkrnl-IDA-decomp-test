unsigned int __stdcall CDirectSound::Release(CDirectSound *this)
{
  unsigned int v1; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-Ch]
  unsigned int ulRefCount; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  ulRefCount = CRefCount::Release((CRefCount *)&this->vfptr);
  if ( ulRefCount == 1 )
  {
    for ( i = 0; i < 1; ++i )
      __Release(&this->m_apKeepAliveBuffers[i]);
    ulRefCount = 0;
  }
  v1 = ulRefCount;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v1;
}