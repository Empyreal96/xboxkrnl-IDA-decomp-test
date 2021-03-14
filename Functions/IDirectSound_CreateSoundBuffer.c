int __userpurge IDirectSound_CreateSoundBuffer@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSound *pDirectSound, _DSBUFFERDESC *pdsbd, IDirectSoundBuffer **ppBuffer, IUnknown *pUnkOuter)
{
  int result; // eax

  if ( pDirectSound )
    result = CDirectSound::CreateSoundBuffer(a1, a2, (CDirectSound *)&pDirectSound[-8], pdsbd, ppBuffer, pUnkOuter);
  else
    result = CDirectSound::CreateSoundBuffer(a1, a2, 0, pdsbd, ppBuffer, pUnkOuter);
  return result;
}