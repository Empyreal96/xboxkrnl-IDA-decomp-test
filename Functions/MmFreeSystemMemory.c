int __fastcall MmFreeSystemMemory(int a1, int a2, void *BaseAddress, unsigned int NumberOfBytes)
{
  return MiFreeMappedMemory(a1, a2, &MmSystemPteRange, BaseAddress, NumberOfBytes);
}