int __stdcall CDirectSoundBuffer::SetMixBinVolumes(CDirectSoundBuffer *this, unsigned int dwMixBinMask, const int *alVolumes)
{
  return CDirectSoundVoice::SetMixBinVolumes((CDirectSoundVoice *)&this->vfptr, dwMixBinMask, alVolumes);
}