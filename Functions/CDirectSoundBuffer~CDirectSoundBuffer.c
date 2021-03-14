void __thiscall CDirectSoundBuffer::~CDirectSoundBuffer(CDirectSoundBuffer *this)
{
  CDirectSoundBuffer *v1; // ST04_4
  CAutoLock __AutoLock; // [esp+4h] [ebp-4h]

  v1 = this;
  this->vfptr = (CRefCountVtbl *)&CDirectSoundBuffer::`vftable';
  CAutoLock::CAutoLock(&__AutoLock);
  __Release((CDirectSoundBufferSettings **)&v1->m_pBuffer);
  PoolFree((void **)&v1->m_paNotifies);
  __Release(&v1->m_pSettings);
  CAutoLock::~CAutoLock(&__AutoLock);
  CDirectSoundVoice::~CDirectSoundVoice((CDirectSoundVoice *)&v1->vfptr);
}