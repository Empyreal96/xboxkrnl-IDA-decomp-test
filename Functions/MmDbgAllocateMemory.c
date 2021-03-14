void *__userpurge MmDbgAllocateMemory@<eax>(int *a1@<edi>, unsigned int NumberOfBytes, unsigned int Protect)
{
  return MiAllocateMappedMemory(
           a1,
           &MmDeveloperKitPteRange,
           MmDebuggerUsage,
           Protect,
           NumberOfBytes,
           MmDeveloperKitPteRange.RemovePageRoutine,
           0);
}