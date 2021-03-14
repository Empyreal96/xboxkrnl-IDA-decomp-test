// write access to const memory has been detected, the output may be wrong!
void __userpurge MemFreeContiguous(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, void *pv)
{
  if ( gcMemAllocsContiguous <= 0 )
    __debugbreak();
  --gcMemAllocsContiguous;
  MmFreeContiguousMemory(a1, a2, a3, pv);
}