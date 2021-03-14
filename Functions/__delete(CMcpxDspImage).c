void __stdcall __delete(CMcpxDspImage **pp)
{
  CMcpxDspImage *p; // [esp+4h] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    CRefCount::operator delete(p);
}