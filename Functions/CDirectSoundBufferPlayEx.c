int __userpurge CDirectSoundBuffer::PlayEx@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, __int64 rtTimeStamp, unsigned int dwFlags)
{
  int v5; // eax
  int v6; // ST0C_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v5 = CMcpxBuffer::Play(this->m_pBuffer, a1, a2, rtTimeStamp, (dwFlags & 1) != 0);
  hr = v5;
  v6 = v5;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v6;
}