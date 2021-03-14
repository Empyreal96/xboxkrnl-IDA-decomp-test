void *__stdcall MiCopyShadowROMDataSection()
{
  unsigned int v0; // edx
  unsigned int v1; // eax
  int v2; // eax
  void *result; // eax

  v0 = ((unsigned int)(*(_DWORD *)&word_80010028[2] + *(_DWORD *)&word_80010028[8]) >> 12)
     + (((*(_DWORD *)&word_80010028[2] + *(_DWORD *)&word_80010028[8]) & 0xFFF) != 0);
  v1 = ((4 * MmHighestPhysicalPage + 4) >> 12) + (((4 * MmHighestPhysicalPage + 4) & 0xFFF) != 0);
  if ( v1 + v0 + 16368 < MmHighestPhysicalPage )
    v2 = v1 - 507920;
  else
    v2 = -507936 - v0;
  result = (void *)(v2 << 12);
  qmemcpy(result, *(const void **)&word_80010028[4], *(_DWORD *)&word_80010028[2] + *(_DWORD *)&word_80010028[8]);
  *(_DWORD *)&word_80010028[4] = result;
  return result;
}