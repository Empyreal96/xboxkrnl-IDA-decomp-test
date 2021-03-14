int __stdcall IDirectSoundBuffer_SetEG(IDirectSoundBuffer *pBuffer, _DSENVELOPEDESC *pEnvelopeDesc)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetEG((CDirectSoundBuffer *)&pBuffer[-28], pEnvelopeDesc);
  else
    result = CDirectSoundBuffer::SetEG(0, pEnvelopeDesc);
  return result;
}