void __userpurge __delete(int *a1@<edi>, int a2@<esi>, CMcpxGPDspManager **pp)
{
  CMcpxGPDspManager *p; // [esp+Ch] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    CMcpxGPDspManager::`scalar deleting destructor'(p, a1, a2, 1u);
}