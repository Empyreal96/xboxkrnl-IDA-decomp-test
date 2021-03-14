// write access to const memory has been detected, the output may be wrong!
void __userpurge PhysicalFree(int *a1@<edi>, void **ppvBuffer)
{
  if ( *ppvBuffer )
  {
    g_dwDirectSoundPhysicalMemoryUsage -= MmQueryAllocationSize(*ppvBuffer);
    MmFreeContiguousMemory((int)*ppvBuffer, (int)ppvBuffer, a1, *ppvBuffer);
    *ppvBuffer = 0;
  }
}