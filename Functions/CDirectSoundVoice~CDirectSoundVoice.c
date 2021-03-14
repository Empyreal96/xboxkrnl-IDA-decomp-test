void __thiscall CDirectSoundVoice::~CDirectSoundVoice(CDirectSoundVoice *this)
{
  CDirectSoundVoice *v1; // ST04_4

  v1 = this;
  this->vfptr = (CRefCountVtbl *)&CDirectSoundVoice::`vftable';
  CList<CDirectSoundVoice>::RemoveNode(&this->m_pDirectSound->m_lstVoices, this);
  __Release((CDirectSoundBufferSettings **)&v1->m_pDirectSound);
  __Release((CDirectSoundBufferSettings **)&v1->m_pVoice);
  __Release((CDirectSoundBufferSettings **)&v1->m_pSettings);
  CRefCount::~CRefCount((CRefCount *)&v1->vfptr);
}