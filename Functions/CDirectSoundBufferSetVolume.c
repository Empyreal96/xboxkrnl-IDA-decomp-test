int __stdcall CDirectSoundBuffer::SetVolume(CDirectSoundBuffer *this, int lVolume)
{
  return CDirectSoundVoice::SetVolume((CDirectSoundVoice *)&this->vfptr, lVolume);
}