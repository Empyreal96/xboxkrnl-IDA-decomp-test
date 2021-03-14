int __userpurge IDirectSoundBuffer_SetBufferData@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *pBuffer, void *pvBufferData, unsigned int dwBufferBytes)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetBufferData(a1, a2, (CDirectSoundBuffer *)&pBuffer[-28], pvBufferData, dwBufferBytes);
  else
    result = CDirectSoundBuffer::SetBufferData(a1, a2, 0, pvBufferData, dwBufferBytes);
  return result;
}