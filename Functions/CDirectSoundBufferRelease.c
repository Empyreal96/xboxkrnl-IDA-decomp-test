unsigned int __stdcall CDirectSoundBuffer::Release(CDirectSoundBuffer *this)
{
  return CRefCount::Release((CRefCount *)&this->vfptr);
}