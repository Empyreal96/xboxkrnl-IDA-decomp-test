unsigned __int32 __stdcall MmPrepareToQuickRebootSystem()
{
  signed int v0; // edx
  int *v1; // ecx
  signed int v2; // edx
  int *v3; // ecx
  signed int v4; // ecx
  signed int *v5; // eax

  v0 = 16352;
  v1 = (int *)-2080374912;
  do
  {
    *v1 = (v0 << 12) | 0x47B;
    ++v1;
    ++v0;
  }
  while ( (signed int)v1 < -2080374848 );
  if ( MmHighestPhysicalPage != 0x3FFF )
  {
    v2 = 32736;
    v3 = (int *)-2080309376;
    do
    {
      *v3 = (v2 << 12) | 0x47B;
      ++v3;
      ++v2;
    }
    while ( (signed int)v3 < -2080309312 );
  }
  memset((void *)0xC0300000, 0, 0x800u);
  memset((void *)0xC0300D00, 0, 0x200u);
  memset((void *)0xC0300B00, 0, 0x100u);
  v4 = 227;
  v5 = (signed int *)-1070594048;
  do
  {
    *v5 = v4;
    ++v5;
    v4 += 0x400000;
  }
  while ( (unsigned int)v5 <= 0xC03008FC );
  MEMORY[0xC0300FFC] = -4194077;
  return KeFlushCurrentTb();
}