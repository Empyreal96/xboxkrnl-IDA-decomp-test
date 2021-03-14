int __stdcall IDirectSoundBuffer_SetVolume(IDirectSoundBuffer *pBuffer, int lVolume)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetVolume((CDirectSoundBuffer *)&pBuffer[-28], lVolume);
  else
    result = CDirectSoundBuffer::SetVolume(0, lVolume);
  return result;
}