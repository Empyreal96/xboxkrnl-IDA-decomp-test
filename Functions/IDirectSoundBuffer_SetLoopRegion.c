int __userpurge IDirectSoundBuffer_SetLoopRegion@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *pBuffer, unsigned int dwLoopStart, unsigned int dwLoopLength)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetLoopRegion(a1, a2, (CDirectSoundBuffer *)&pBuffer[-28], dwLoopStart, dwLoopLength);
  else
    result = CDirectSoundBuffer::SetLoopRegion(a1, a2, 0, dwLoopStart, dwLoopLength);
  return result;
}