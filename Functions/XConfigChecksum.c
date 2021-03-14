int __stdcall XConfigChecksum(const void *data, unsigned int count)
{
  _DWORD *v2; // ecx
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int i; // edx

  v2 = data;
  v3 = 0;
  v4 = 0;
  for ( i = count >> 2; i; --i )
  {
    v4 = ((unsigned int)*v2 + __PAIR__(v4, v3)) >> 32;
    v3 += *v2;
    ++v2;
  }
  return __CFADD__(v4, v3) + v4 + v3;
}