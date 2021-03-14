int __userpurge IDirectSoundBuffer_StopEx@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSoundBuffer *pBuffer, __int64 rtTimeStamp, unsigned int dwFlags)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::StopEx(a1, a2, (CDirectSoundBuffer *)&pBuffer[-28], rtTimeStamp, dwFlags);
  else
    result = CDirectSoundBuffer::StopEx(a1, a2, 0, rtTimeStamp, dwFlags);
  return result;
}