int __stdcall IDirectSoundBuffer_SetPitch(IDirectSoundBuffer *pBuffer, int lPitch)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetPitch((CDirectSoundBuffer *)&pBuffer[-28], lPitch);
  else
    result = CDirectSoundBuffer::SetPitch(0, lPitch);
  return result;
}