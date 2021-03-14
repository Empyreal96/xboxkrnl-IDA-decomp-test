bool __stdcall XGRAPHICS::IsCompressedD3DFORMAT(unsigned int Format)
{
  return Format == 12 || Format > 0xD && Format <= 0xF;
}