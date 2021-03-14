int __userpurge CDirectSoundBuffer::SetLoopRegion@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, unsigned int dwLoopStart, unsigned int dwLoopLength)
{
  int v5; // ST08_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  hr = 0;
  CAutoLock::CAutoLock(&__AutoLock);
  if ( dwLoopStart != this->m_pSettings->m_dwLoopStart || dwLoopLength != this->m_pSettings->m_dwLoopLength )
  {
    CDirectSoundBufferSettings::SetLoopRegion(this->m_pSettings, dwLoopStart, dwLoopLength);
    hr = CMcpxBuffer::SetLoopRegion(this->m_pBuffer, a1, a2);
  }
  v5 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v5;
}