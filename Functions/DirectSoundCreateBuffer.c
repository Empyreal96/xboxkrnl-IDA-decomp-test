int __userpurge DirectSoundCreateBuffer@<eax>(int *a1@<edi>, int a2@<esi>, _DSBUFFERDESC *pdsbd, IDirectSoundBuffer **ppBuffer)
{
  int hr; // [esp+0h] [ebp-8h]
  IDirectSound *pDirectSound; // [esp+4h] [ebp-4h]

  pDirectSound = 0;
  hr = DirectSoundCreate(a1, a2, 0, &pDirectSound, 0);
  if ( hr >= 0 )
    hr = IDirectSound::CreateSoundBuffer(a1, a2, pDirectSound, pdsbd, ppBuffer, 0);
  __Release(&pDirectSound);
  return hr;
}