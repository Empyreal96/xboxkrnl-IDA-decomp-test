int *__userpurge MmAllocatePoolPages@<eax>(int *a1@<edi>, unsigned int NumberOfBytes)
{
  int *v2; // eax
  int *v3; // esi

  v2 = (int *)MiAllocateMappedMemory(a1, &MmSystemPteRange, MmPoolUsage, 4u, NumberOfBytes, MiRemoveAnyPage, 0);
  v3 = v2;
  if ( v2 )
    RtlFillMemoryUlong(v2, NumberOfBytes, 1819242320);
  return v3;
}