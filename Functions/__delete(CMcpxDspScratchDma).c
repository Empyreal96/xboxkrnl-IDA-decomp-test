void __userpurge __delete(int *a1@<edi>, int a2@<esi>, CMcpxDspScratchDma **pp)
{
  CMcpxDspScratchDma *p; // [esp+Ch] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    CMcpxDspScratchDma::`scalar deleting destructor'(p, a1, a2, 1u);
}