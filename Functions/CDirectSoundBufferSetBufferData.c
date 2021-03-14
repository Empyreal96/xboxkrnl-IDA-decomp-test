int __userpurge CDirectSoundBuffer::SetBufferData@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, void *pvDataBuffer, unsigned int dwBufferBytes)
{
  int v5; // ST08_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  hr = 0;
  CAutoLock::CAutoLock(&__AutoLock);
  if ( pvDataBuffer != this->m_pSettings->m_pvBufferData || dwBufferBytes != this->m_pSettings->m_dwBufferSize )
  {
    hr = CMcpxBuffer::ReleaseBufferData(this->m_pBuffer, a1, a2);
    if ( hr >= 0 )
      hr = CDirectSoundBufferSettings::SetBufferData(this->m_pSettings, a2, pvDataBuffer, dwBufferBytes);
    if ( hr >= 0 && pvDataBuffer && dwBufferBytes )
      hr = CMcpxBuffer::SetBufferData(this->m_pBuffer, a1, a2);
  }
  v5 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v5;
}