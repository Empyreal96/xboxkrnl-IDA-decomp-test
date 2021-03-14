int __userpurge CDirectSoundBuffer::Play@<eax>(int *a1@<edi>, int a2@<esi>, CDirectSoundBuffer *this, unsigned int dwReserved1, unsigned int dwReserved2, unsigned int dwFlags)
{
  int v6; // eax
  int v7; // ST10_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-8h]
  int hr; // [esp+8h] [ebp-4h]

  CAutoLock::CAutoLock(&__AutoLock);
  v6 = CDirectSoundBuffer::PlayEx(a1, a2, this, 0i64, dwFlags);
  hr = v6;
  v7 = v6;
  CAutoLock::~CAutoLock(&__AutoLock);
  return v7;
}