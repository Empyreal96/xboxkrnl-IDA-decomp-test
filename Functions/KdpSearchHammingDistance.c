unsigned int __stdcall KdpSearchHammingDistance(unsigned int Left, unsigned int Right)
{
  unsigned int v2; // ecx
  unsigned int result; // eax
  signed int v4; // edx

  v2 = Right ^ Left;
  result = 0;
  v4 = 32;
  do
  {
    if ( v2 & 1 )
      ++result;
    v2 >>= 1;
    --v4;
  }
  while ( v4 );
  return result;
}