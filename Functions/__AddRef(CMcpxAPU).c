CMcpxAPU *__stdcall __AddRef(CMcpxAPU *p)
{
  if ( p )
    p->vfptr->AddRef((CRefCount *)p);
  return p;
}