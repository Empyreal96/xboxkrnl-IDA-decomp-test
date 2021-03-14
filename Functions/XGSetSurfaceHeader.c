void __stdcall XGSetSurfaceHeader(unsigned int Width, unsigned int Height, _D3DFORMAT Format, D3DSurface *pSurface, unsigned int Data, unsigned int Pitch)
{
  XGRAPHICS::EncodeFormat(Width, Height, 1u, 1u, Format, Pitch, 1, 0, 0, &pSurface->Format, &pSurface->Size);
  pSurface->Lock = 0;
  pSurface->Parent = 0;
  pSurface->Common = 327681;
  pSurface->Data = Data;
}