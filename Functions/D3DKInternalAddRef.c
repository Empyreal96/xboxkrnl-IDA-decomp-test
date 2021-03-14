void __userpurge D3DK::InternalAddRef(int *a1@<edi>, D3DResource *pResource)
{
  if ( (pResource->Common & 0x780000) == 7864320 )
    D3DK::DXGRIP(a1, "InternalAddRef - Internal reference count overflow.");
  if ( (pResource->Common & 0x70000) == 327680 && !(pResource->Common & 0x780000) && pResource[1].Lock )
    D3DK::InternalAddRef(a1, (D3DResource *)pResource[1].Lock);
  pResource->Common += 0x80000;
}