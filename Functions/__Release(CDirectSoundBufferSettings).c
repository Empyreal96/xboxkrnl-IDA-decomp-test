void __stdcall __Release(CDirectSoundBufferSettings **pp)
{
  CDirectSoundBufferSettings *p; // [esp+0h] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    p->vfptr->Release((CRefCount *)&p->vfptr);
}