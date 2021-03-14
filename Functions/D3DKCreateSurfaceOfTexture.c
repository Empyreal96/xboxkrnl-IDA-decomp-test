int __userpurge D3DK::CreateSurfaceOfTexture@<eax>(int *a1@<edi>, int a2@<edx>, int a3@<ecx>, int a4@<esi>, unsigned int Format, unsigned int Size, D3DBaseTexture *pParent, void *pvData, D3DSurface **ppSurface)
{
  D3DSurface *v9; // esi

  v9 = (D3DSurface *)D3DK::MemAlloc(a2, a3, a4, 0x18u);
  if ( !v9 )
    return -2147024882;
  v9->Common = 17104897;
  v9->Data = D3DK::GetGPUAddress(a1, pvData);
  v9->Format = Format;
  v9->Size = Size;
  v9->Parent = pParent;
  v9->Lock = 0;
  D3DResource_AddRef(a1, (D3DResource *)&pParent->Common);
  *ppSurface = v9;
  return 0;
}