int __userpurge D3DK::CreateTexture@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int Width, unsigned int Height, unsigned int Depth, unsigned int Levels, unsigned int Usage, _D3DFORMAT D3DFormat, char isCubeMap, char isVolumeTexture, D3DBaseTexture **ppTexture)
{
  D3DBaseTexture **v11; // ebx
  char v12; // ST20_1
  int v13; // edx
  int v14; // ecx
  int *v15; // edi
  int v16; // edx
  int v17; // ecx
  int *v18; // esi
  void *v19; // edx

  v11 = ppTexture;
  v12 = isVolumeTexture;
  *ppTexture = 0;
  v15 = (int *)D3DK::PixelJar::EncodeFormat(
                 a1,
                 Width,
                 Height,
                 Depth,
                 Levels,
                 D3DFormat,
                 0,
                 1,
                 isCubeMap,
                 v12,
                 (unsigned int *)&ppTexture,
                 (unsigned int *)&isVolumeTexture);
  if ( Usage & 0x10000 )
    ppTexture = (D3DBaseTexture **)((unsigned int)ppTexture & 0xFFFFFFF7);
  v18 = D3DK::MemAlloc(v13, v14, a2, 0x14u);
  if ( v18 )
  {
    v19 = (void *)MmAllocateContiguousMemoryEx(v16, v17, (int)v18, (unsigned int)v15, 0, 0x3FFB000u, 0x80u, 0x404u);
    if ( v19 )
    {
      _EAX = 1;
      _ECX = &D3D__AllocsContiguous;
      __asm { xadd    [ecx], eax }
      *v18 = 17039361;
      v18[1] = D3DK::GetGPUAddress(v15, v19);
      v18[3] = (int)ppTexture;
      v18[4] = isVolumeTexture;
      v18[2] = 0;
      *v11 = (D3DBaseTexture *)v18;
      return 0;
    }
    D3DK::MemFree(v18);
  }
  return -2147024882;
}