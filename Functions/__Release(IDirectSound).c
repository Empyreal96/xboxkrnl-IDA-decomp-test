void __stdcall __Release(IDirectSound **pp)
{
  IDirectSound *p; // [esp+0h] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    IDirectSound::Release(p);
}