void __stdcall __Release(IDirectSoundBuffer **pp)
{
  IDirectSoundBuffer *p; // [esp+0h] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    IDirectSoundBuffer::Release(p);
}