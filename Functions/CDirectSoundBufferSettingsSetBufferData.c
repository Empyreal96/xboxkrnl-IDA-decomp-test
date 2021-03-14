int __userpurge CDirectSoundBufferSettings::SetBufferData@<eax>(CDirectSoundBufferSettings *this@<ecx>, int a2@<esi>, void *pvDataBuffer, unsigned int dwBufferBytes)
{
  CDirectSoundBufferSettings *thisa; // [esp+0h] [ebp-8h]
  int hr; // [esp+4h] [ebp-4h]

  thisa = this;
  hr = 0;
  if ( this->m_dwFlags & 0x80000000 )
    this->m_pvBufferData = 0;
  else
    PoolFree(&this->m_pvBufferData);
  thisa->m_dwBufferSize = dwBufferBytes;
  if ( dwBufferBytes )
  {
    if ( pvDataBuffer )
    {
      thisa->m_dwFlags |= 0x80000000;
      thisa->m_pvBufferData = pvDataBuffer;
    }
    else
    {
      thisa->m_dwFlags &= 0x7FFFFFFFu;
      thisa->m_pvBufferData = PoolAlloc((int)thisa, (int)thisa, a2, thisa->m_dwBufferSize, 0);
      hr = thisa->m_pvBufferData != 0 ? 0 : 0x8007000E;
    }
  }
  if ( hr >= 0 )
    CDirectSoundBufferSettings::SetLoopRegion(thisa, 0, 0);
  return hr;
}