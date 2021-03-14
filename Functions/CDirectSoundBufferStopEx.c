int __userpurge CDirectSoundBuffer::StopEx@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, __int64 rtTimeStamp, unsigned int dwFlags)
{
  int v5; // ST0C_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  if ( dwFlags & 3 )
    hr = CMcpxBuffer::NoteOff(this->m_pBuffer, a1, a2, rtTimeStamp, (dwFlags & 2) != 0);
  else
    hr = CMcpxBuffer::Stop(this->m_pBuffer, a1, a2, rtTimeStamp);
  v5 = hr;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v5;
}