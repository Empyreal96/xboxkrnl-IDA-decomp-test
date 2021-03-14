void __thiscall CDirectSoundBuffer::CDirectSoundBuffer(CDirectSoundBuffer *this, CDirectSound *pDirectSound)
{
  CDirectSoundBuffer *v2; // ST04_4

  v2 = this;
  CDirectSoundVoice::CDirectSoundVoice((CDirectSoundVoice *)&this->vfptr, pDirectSound);
  v2->vfptr = (CRefCountVtbl *)&CDirectSoundBuffer::`vftable';
}