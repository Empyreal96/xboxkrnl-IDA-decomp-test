int __stdcall MmFreePoolPages(void *StartingAddress)
{
  int v1; // edx
  int v2; // ecx

  RtlFillMemoryUlong((int *)StartingAddress, 0x1000u, 1684104516);
  return MiFreeMappedMemory(v2, v1, &MmSystemPteRange, StartingAddress, 0);
}