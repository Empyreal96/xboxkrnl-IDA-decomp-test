// write access to const memory has been detected, the output may be wrong!
unsigned int __userpurge MemAllocContiguous@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int Size, unsigned int Alignment)
{
  ++gcMemAllocsContiguous;
  return MmAllocateContiguousMemoryEx(a1, a2, a3, Size, 0, 0x3FFB000u, Alignment, 0x404u);
}