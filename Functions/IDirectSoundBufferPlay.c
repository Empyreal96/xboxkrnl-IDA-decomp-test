int __userpurge IDirectSoundBuffer::Play@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *this, unsigned int dwReserved1, unsigned int dwReserved2, unsigned int dwFlags)
{
  return IDirectSoundBuffer_Play(a1, a2, this, dwReserved1, dwReserved2, dwFlags);
}