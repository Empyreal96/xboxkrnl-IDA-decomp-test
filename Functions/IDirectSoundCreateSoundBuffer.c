int __userpurge IDirectSound::CreateSoundBuffer@<eax>(int *a1@<edi>, int a2@<esi>, IDirectSound *this, _DSBUFFERDESC *pdsbd, IDirectSoundBuffer **ppBuffer, IUnknown *pUnkOuter)
{
  return IDirectSound_CreateSoundBuffer(a1, a2, this, pdsbd, ppBuffer, pUnkOuter);
}