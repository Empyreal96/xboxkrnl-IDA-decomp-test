void __stdcall D3DK::DestroyResource(D3DResource *pResource)
{
  unsigned int v1; // esi
  int v2; // edx
  unsigned int v3; // esi
  void *v4; // esi
  void *v12; // esi
  int v16; // edx
  void *v17; // esi

  if ( !(pResource->Common & 0x1000000) )
    D3DK::DXGRIP((int *)pResource, "DestroyResource - The reference count of a non-d3d created resource went to zero.");
  v1 = pResource->Common & 0x70000;
  if ( v1 != 327680 || (pResource->Common & 0x80000000) != 0 )
    D3DK::BlockOnResource(pResource);
  D3DK::CleanPrivateData(pResource);
  if ( v1 == 327680 )
  {
    if ( (pResource->Common & 0x80000000) != 0 )
    {
      v3 = pResource->Data;
      if ( v3 > 0x4000000 )
      {
        DbgPrint((int *)pResource, "DebugVerifyPhysical - Not a valid physical memory offset.");
        DbgPrint((int *)pResource, "\n");
        __debugbreak();
      }
      v4 = (void *)(v3 | 0x80000000);
      if ( !D3D__AllocsContiguous )
        D3DK::DXGRIP((int *)pResource, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
      _EAX = -1;
      _ECX = &D3D__AllocsContiguous;
      __asm { xadd    [ecx], eax }
      MmFreeContiguousMemory(v2, (int)&D3D__AllocsContiguous, (int *)pResource, v4);
      D3DK::MemFree(pResource);
      return;
    }
    goto LABEL_23;
  }
  if ( v1 != 0x20000 )
  {
    if ( v1 != 0x10000 && v1 != 393216 )
    {
      v17 = (void *)D3DK::GetWriteCombinedAddress((int *)pResource, pResource->Data);
      if ( !D3D__AllocsContiguous )
        D3DK::DXGRIP((int *)pResource, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
      _EAX = -1;
      _ECX = &D3D__AllocsContiguous;
      __asm { xadd    [ecx], eax }
      MmFreeContiguousMemory(v16, (int)&D3D__AllocsContiguous, (int *)pResource, v17);
    }
    goto LABEL_23;
  }
  if ( (pResource->Common & 0x80000000) != 0 )
  {
LABEL_23:
    D3DK::MemFree(pResource);
    return;
  }
  v12 = (void *)pResource->Data;
  if ( !D3D__AllocsContiguous )
    D3DK::DXGRIP((int *)pResource, "Assertion failure: %s", "D3D__AllocsContiguous != 0");
  _EAX = -1;
  _ECX = &D3D__AllocsContiguous;
  __asm { xadd    [ecx], eax }
  MmFreeContiguousMemory(v2, (int)&D3D__AllocsContiguous, (int *)pResource, v12);
  D3DK::MemFree(pResource);
}