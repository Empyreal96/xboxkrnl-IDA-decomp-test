void __thiscall CDirectSoundVoice::CDirectSoundVoice(CDirectSoundVoice *this, CDirectSound *pDirectSound)
{
  CDirectSoundVoice *v2; // ST04_4

  v2 = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  v2->vfptr = (CRefCountVtbl *)&CDirectSoundVoice::`vftable';
  v2->m_pDirectSound = (CDirectSound *)__AddRef((CMcpxAPU *)pDirectSound);
  CList<CDirectSoundVoice>::AddNode(&v2->m_pDirectSound->m_lstVoices, v2);
}