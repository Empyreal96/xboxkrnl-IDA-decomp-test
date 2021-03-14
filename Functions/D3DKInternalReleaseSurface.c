void __stdcall D3DK::InternalReleaseSurface(D3DResource *pResource)
{
  unsigned int v1; // eax
  D3DResource *v2; // esi
  int v3; // eax

  if ( !(pResource->Common & 0x780000) )
    D3DK::DXGRIP((int *)pResource, "InternalRelease - Internal refcount underflow.");
  v1 = pResource->Common;
  if ( (pResource->Common & 0x780000) != 0x80000 )
    goto LABEL_17;
  if ( (v1 & 0x70000) == 327680 )
  {
    v2 = (D3DResource *)pResource[1].Lock;
    if ( v2 )
    {
      if ( !(v2->Common & 0x780000) )
        D3DK::DXGRIP((int *)pResource, "Assertion failure: %s", "(pResource->Common & D3DCOMMON_INTREFCOUNT_MASK) != 0");
      if ( (v2->Common & 0x70000) == 327680 )
        D3DK::DXGRIP(
          (int *)pResource,
          "Assertion failure: %s",
          "(pResource->Common & D3DCOMMON_TYPE_MASK) != D3DCOMMON_TYPE_SURFACE");
      v3 = v2->Common - 0x80000;
      v2->Common = v3;
      if ( !(v3 & 0x78FFFF) )
        D3DK::DestroyResource(v2);
    }
  }
  v1 = pResource->Common;
  if ( pResource->Common & 0xFFFF )
LABEL_17:
    pResource->Common = v1 - 0x80000;
  else
    D3DK::DestroyResource(pResource);
}