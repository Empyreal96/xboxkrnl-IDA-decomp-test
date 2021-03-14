unsigned int __stdcall AvpCalcWSSCRC(unsigned int Value)
{
  unsigned int v1; // eax
  unsigned int v2; // ecx
  int v3; // edx
  int v4; // esi

  v1 = 63;
  v2 = 0;
  do
  {
    v3 = ((unsigned __int8)v1 ^ (unsigned __int8)(Value >> v2)) & 1;
    v4 = 32 * v3 | (v1 >> 1) & 0xF | 16 * v3 ^ (v1 >> 1) & 0x10;
    ++v2;
    v1 = 32 * v3 | (v1 >> 1) & 0xF | 16 * v3 ^ (v1 >> 1) & 0x10;
  }
  while ( v2 < 0xE );
  return Value | (v4 << 14);
}