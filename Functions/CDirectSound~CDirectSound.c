// write access to const memory has been detected, the output may be wrong!
void __thiscall CDirectSound::~CDirectSound(CDirectSound *this)
{
  CDirectSound *v1; // ST04_4

  v1 = this;
  this->vfptr = (CRefCountVtbl *)&CDirectSound::`vftable';
  __Release((CDirectSoundBufferSettings **)&this->m_pDevice);
  __Release((CDirectSoundBufferSettings **)&v1->m_pSettings);
  CDirectSound::m_pDirectSound = 0;
  CRefCount::~CRefCount((CRefCount *)&v1->vfptr);
}