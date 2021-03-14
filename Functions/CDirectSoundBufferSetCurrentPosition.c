int __userpurge CDirectSoundBuffer::SetCurrentPosition@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, unsigned int dwPlayPosition)
{
  int v4; // eax
  int v5; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v4 = CMcpxBuffer::SetCurrentPosition(this->m_pBuffer, a1, a2, dwPlayPosition);
  hr = v4;
  v5 = v4;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v5;
}