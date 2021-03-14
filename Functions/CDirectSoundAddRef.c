unsigned int __stdcall CDirectSound::AddRef(CDirectSoundBuffer *this)
{
  return CRefCount::AddRef((CRefCount *)&this->vfptr);
}