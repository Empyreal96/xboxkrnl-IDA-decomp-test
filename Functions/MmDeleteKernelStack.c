void __fastcall MmDeleteKernelStack(int a1, int a2, void *KernelStackBase, void *KernelStackLimit)
{
  char *v4; // ecx
  _MMPTERANGE *v5; // ebx
  int v6; // esi

  v4 = (char *)KernelStackLimit + 805306368;
  v5 = &MmSystemPteRange;
  if ( (unsigned int)KernelStackLimit + 805306368 > 0x1FFFFFFF )
    v5 = &MmDeveloperKitPteRange;
  v6 = (_BYTE *)KernelStackBase - (_BYTE *)KernelStackLimit + 4096;
  if ( v6 & 0xFFF )
    RtlAssert(
      a2,
      (int)v4,
      (int *)KernelStackBase,
      v6,
      "(ActualNumberOfBytes & (PAGE_SIZE - 1)) == 0",
      "d:\\xbox-apr03\\private\\ntos\\mmx\\mmsup.c",
      0x482u,
      0);
  MiFreeMappedMemory(
    (int)v4,
    a2,
    v5,
    (char *)KernelStackLimit - 4096,
    (_BYTE *)KernelStackBase - (_BYTE *)KernelStackLimit + 4096);
}