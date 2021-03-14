void __userpurge __delete(int *a1@<edi>, CAc97Channel **pp)
{
  CAc97Channel *p; // [esp+Ch] [ebp-4h]

  p = *pp;
  *pp = 0;
  if ( p )
    CAc97Channel::`scalar deleting destructor'(p, a1, 1u);
}