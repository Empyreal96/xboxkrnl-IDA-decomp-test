int __userpurge D3DK::CreateSurfaceWithContiguousHeader@<eax>(int *a1@<edi>, int a2@<esi>, unsigned int Width, unsigned int Height, _D3DFORMAT D3DFormat, D3DSurface **ppSurface)
{
  unsigned int v6; // eax
  int v7; // edx
  int v8; // ecx
  D3DSurface *v9; // eax
  D3DSurface *v10; // esi
  unsigned int v12; // eax
  D3DSurface **v13; // edx

  v6 = D3DK::PixelJar::EncodeFormat(
         a1,
         Width,
         Height,
         1u,
         1u,
         D3DFormat,
         0,
         1,
         0,
         0,
         (unsigned int *)&D3DFormat,
         &Height);
  v9 = (D3DSurface *)MmAllocateContiguousMemoryEx(v7, v8, a2, v6 + 64, 0, 0x3FFB000u, 0x40u, 0x404u);
  v10 = v9;
  if ( !v9 )
    return -2147024882;
  v9->Common = -2130378751;
  v12 = D3DK::GetGPUAddress(a1, &v9[2].Size);
  v13 = ppSurface;
  v10->Data = v12;
  v10->Format = D3DFormat;
  v10->Size = Height;
  v10->Parent = 0;
  v10->Lock = 0;
  *v13 = v10;
  return 0;
}