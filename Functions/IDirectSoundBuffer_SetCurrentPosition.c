int __userpurge IDirectSoundBuffer_SetCurrentPosition@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *pBuffer, unsigned int dwPlayCursor)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetCurrentPosition(a1, a2, (CDirectSoundBuffer *)&pBuffer[-28], dwPlayCursor);
  else
    result = CDirectSoundBuffer::SetCurrentPosition(a1, a2, 0, dwPlayCursor);
  return result;
}