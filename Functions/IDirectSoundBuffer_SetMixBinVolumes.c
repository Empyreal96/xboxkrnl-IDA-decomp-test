int __stdcall IDirectSoundBuffer_SetMixBinVolumes(IDirectSoundBuffer *pBuffer, unsigned int dwMixBinMask, const int *alVolumes)
{
  int result; // eax

  if ( pBuffer )
    result = CDirectSoundBuffer::SetMixBinVolumes((CDirectSoundBuffer *)&pBuffer[-28], dwMixBinMask, alVolumes);
  else
    result = CDirectSoundBuffer::SetMixBinVolumes(0, dwMixBinMask, alVolumes);
  return result;
}