unsigned int __userpurge MmAllocateContiguousMemory@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int NumberOfBytes)
{
  return MmAllocateContiguousMemoryEx(a1, a2, a3, NumberOfBytes, 0, 0xFFFFFFFF, 0, 4u);
}