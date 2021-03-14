int __stdcall dev_cleanup()
{
  IDirectSoundBuffer **v0; // esi

  v0 = m_pDSBuffer;
  do
  {
    IDirectSoundBuffer_Release(*v0);
    ++v0;
  }
  while ( (signed int)v0 < (signed int)&dsp_data );
  return IDirectSound_Release(m_pDSound);
}