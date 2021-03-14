int __stdcall XGRAPHICS::MinimumTextureSizeOfD3DFORMAT(unsigned int Format)
{
  return XGRAPHICS::IsCompressedD3DFORMAT(Format) != 0 ? 2 : 0;
}