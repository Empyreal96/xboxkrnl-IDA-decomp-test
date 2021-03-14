void __thiscall CAutoLock::~CAutoLock(CAutoLock *this)
{
  if ( this->m_fLocked )
    DirectSoundLeaveCriticalSection(this);
}