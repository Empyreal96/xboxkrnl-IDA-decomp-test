void __thiscall CAutoLock::CAutoLock(CAutoLock *this)
{
  this->m_fLocked = DirectSoundEnterCriticalSection();
}