void __userpurge D3DK::PixelJar::LockSurface(unsigned int Level@<esi>, unsigned int Flags@<edx>, int a3@<ebx>, int *a4@<edi>, _D3DCUBEMAP_FACES FaceType, char **ppbData, unsigned int *pRowPitch, unsigned int *pSlicePitch)
{
  if ( (unsigned int)a4 >= (*(_BYTE *)(Level + 14) & 0xFu) )
    D3DK::DXGRIP(a4, "PixelJar::LockSurface - invalid mipmap level.");
  if ( a3 & 0xFFFFFF1F )
    D3DK::DXGRIP(a4, "PixelJar::LockSurface - invalid flag.");
  if ( !(a3 & 0x20) )
    D3DK::BlockOnResource((D3DResource *)Level);
  D3DK::PixelJar::FindSurfaceWithinTexture(
    (D3DPixelContainer *)Level,
    FaceType,
    (unsigned int)a4,
    ppbData,
    pRowPitch,
    pSlicePitch,
    (unsigned int *)&pRowPitch,
    (unsigned int *)&pSlicePitch);
  if ( a3 & 0x40 )
    *ppbData = (char *)((unsigned int)*ppbData | 0xF0000000);
}