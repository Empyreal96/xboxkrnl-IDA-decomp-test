int __stdcall CDirectSoundBuffer::SetFilter(CDirectSoundBuffer *this, _DSFILTERDESC *pFilterDesc)
{
  return CDirectSoundVoice::SetFilter((CDirectSoundVoice *)&this->vfptr, pFilterDesc);
}