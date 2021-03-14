int __userpurge D3DK::CreateStandAloneSurface@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int Width, unsigned int Height, _D3DFORMAT D3DFormat, char isInVideoMemory, D3DSurface **ppSurface)
{
  int *v7; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int *v12; // esi
  void *v13; // edx
  unsigned int v21; // eax
  D3DSurface **v22; // edx

  v7 = (int *)D3DK::PixelJar::EncodeFormat(
                a1,
                Width,
                Height,
                1u,
                1u,
                D3DFormat,
                0,
                isInVideoMemory,
                0,
                0,
                (unsigned int *)&isInVideoMemory,
                (unsigned int *)&D3DFormat);
  v12 = D3DK::MemAlloc(v8, v9, a2, 0x18u);
  if ( v12 )
  {
    v13 = (void *)MmAllocateContiguousMemoryEx(v10, v11, (int)v12, (unsigned int)v7, 0, 0x3FFB000u, 0x40u, 0x404u);
    if ( v13 )
    {
      _EAX = 1;
      _ECX = &D3D__AllocsContiguous;
      __asm { xadd    [ecx], eax }
      *v12 = -2130378751;
      v21 = D3DK::GetGPUAddress(v7, v13);
      v22 = ppSurface;
      v12[1] = v21;
      v12[3] = isInVideoMemory;
      v12[4] = D3DFormat;
      v12[5] = 0;
      v12[2] = 0;
      *v22 = (D3DSurface *)v12;
      return 0;
    }
    D3DK::MemFree(v12);
  }
  return -2147024882;
}