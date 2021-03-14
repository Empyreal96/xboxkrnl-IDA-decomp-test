void *__userpurge MmAllocateSystemMemory@<eax>(int *a1@<edi>, unsigned int NumberOfBytes, unsigned int Protect)
{
  return MiAllocateMappedMemory(a1, &MmSystemPteRange, MmSystemMemoryUsage, Protect, NumberOfBytes, MiRemoveAnyPage, 0);
}