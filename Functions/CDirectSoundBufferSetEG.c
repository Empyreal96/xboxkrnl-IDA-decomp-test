int __stdcall CDirectSoundBuffer::SetEG(CDirectSoundBuffer *this, _DSENVELOPEDESC *pEnvelopeDesc)
{
  return CDirectSoundVoice::SetEG((CDirectSoundVoice *)&this->vfptr, pEnvelopeDesc);
}