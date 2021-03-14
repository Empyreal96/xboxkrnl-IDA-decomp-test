void __userpurge D3DK::InitializeSurface(int *a1@<edi>, D3DSurface *pSurface, unsigned int Format, unsigned int Size, void *pvData)
{
  pSurface->Common = 17104897;
  pSurface->Data = D3DK::GetGPUAddress(a1, pvData);
  pSurface->Format = Format;
  pSurface->Size = Size;
  pSurface->Parent = 0;
  pSurface->Lock = 0;
}