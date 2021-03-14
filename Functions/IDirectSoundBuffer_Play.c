int __userpurge IDirectSoundBuffer_Play@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *pBuffer, unsigned int dwReserved1, unsigned int dwReserved2, unsigned int dwFlags)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::Play(a1, a2, (CDirectSoundBuffer *)&pBuffer[-28], dwReserved1, dwReserved2, dwFlags);
  else
    result = CDirectSoundBuffer::Play(a1, a2, 0, dwReserved1, dwReserved2, dwFlags);
  return result;
}