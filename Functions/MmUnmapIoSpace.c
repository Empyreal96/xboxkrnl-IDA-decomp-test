void __userpurge MmUnmapIoSpace(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *BaseAddress, unsigned int NumberOfBytes)
{
  unsigned int v5; // esi
  int v6; // edx
  int v7; // ecx

  if ( !NumberOfBytes )
    RtlAssert(a1, a2, a3, 0, "NumberOfBytes != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\physical.c", 0x322u, 0);
  if ( (unsigned int)BaseAddress + 805306368 <= 0x1FFFFFFF )
  {
    v5 = (((unsigned __int16)BaseAddress & 0xFFF) + NumberOfBytes + 4095) >> 12;
    MiZeroAndFlushPtes((_DWORD *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000), v5);
    MiReleaseSystemPtes(
      v6,
      v7,
      (int *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000),
      &MmSystemPteRange,
      (_MMPTE *)((((unsigned int)BaseAddress >> 10) & 0x3FFFFC) - 0x40000000),
      v5);
  }
}