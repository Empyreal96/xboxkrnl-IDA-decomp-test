int __stdcall CDirectSoundBuffer::GetStatus(CDirectSoundBuffer *this, unsigned int *pdwStatus)
{
  int v2; // eax
  int v3; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v2 = CMcpxBuffer::GetStatus(this->m_pBuffer, pdwStatus);
  hr = v2;
  v3 = v2;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v3;
}