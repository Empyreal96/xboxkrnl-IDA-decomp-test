void __userpurge CDirectSoundBuffer::OnStop(int a1@<ecx>, int *a2@<edi>, int a3@<esi>, CDirectSoundBuffer *this)
{
  CAutoLock __AutoLock; // [esp+0h] [ebp-4h]

  __AutoLock.m_fLocked = a1;
  CAutoLock::CAutoLock(&__AutoLock);
  CDirectSoundBuffer::NotifyStop(a2, a3, this);
  CAutoLock::~CAutoLock(&__AutoLock);
}