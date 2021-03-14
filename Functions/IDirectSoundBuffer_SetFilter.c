int __stdcall IDirectSoundBuffer_SetFilter(IDirectSoundBuffer *pBuffer, _DSFILTERDESC *pFilter)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetFilter((CDirectSoundBuffer *)&pBuffer[-28], pFilter);
  else
    result = CDirectSoundBuffer::SetFilter(0, pFilter);
  return result;
}