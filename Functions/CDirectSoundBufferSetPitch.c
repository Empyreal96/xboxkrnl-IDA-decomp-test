int __stdcall CDirectSoundBuffer::SetPitch(CDirectSoundBuffer *this, int lPitch)
{
  return CDirectSoundVoice::SetPitch((CDirectSoundVoice *)&this->vfptr, lPitch);
}