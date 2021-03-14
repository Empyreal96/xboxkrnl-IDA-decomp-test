unsigned int __stdcall MmDbgTranslatePhysicalAddress64(_LARGE_INTEGER PhysicalAddress)
{
  MEMORY[0xC0300C08] = PhysicalAddress.LowPart & 0xFFC000FB | 0xFB;
  __invlpg((void *)0xC0800000);
  return (PhysicalAddress.LowPart & 0x3FFFFF) - 1065353216;
}