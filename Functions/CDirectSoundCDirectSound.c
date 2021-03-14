// write access to const memory has been detected, the output may be wrong!
void __thiscall CDirectSound::CDirectSound(CDirectSound *this)
{
  CDirectSound *v1; // ST04_4

  v1 = this;
  CRefCount::CRefCount((CRefCount *)&this->vfptr, 1u);
  v1->vfptr = (CRefCountVtbl *)&CDirectSound::`vftable';
  CMcpxDspImage::CMcpxDspImage((CList<_SGEHEAPRUNMARKER> *)&v1->m_lstVoices);
  CDirectSound::m_pDirectSound = v1;
}