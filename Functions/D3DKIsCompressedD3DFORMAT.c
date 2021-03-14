char __stdcall D3DK::IsCompressedD3DFORMAT(unsigned int Format)
{
  char result; // al

  result = 0;
  if ( Format == 12 || Format > 0xD && Format <= 0xF )
    result = 1;
  return result;
}