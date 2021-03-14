// write access to const memory has been detected, the output may be wrong!
char *__userpurge PhysicalAlloc@<eax>(int a1@<esi>, unsigned int cbBuffer, unsigned int dwAlignment, unsigned int dwFlags, const void *pvSource)
{
  char *pvBuffer; // [esp+0h] [ebp-4h]

  pvBuffer = (char *)MmAllocateContiguousMemoryEx(
                       cbBuffer,
                       dwAlignment,
                       a1,
                       cbBuffer,
                       0,
                       0xFFFFFFFF,
                       dwAlignment,
                       dwFlags);
  if ( pvBuffer )
  {
    if ( pvSource )
      memcpy(pvBuffer, (char *)pvSource, cbBuffer);
    else
      memset(pvBuffer, 0, cbBuffer);
    g_dwDirectSoundPhysicalMemoryUsage += MmQueryAllocationSize(pvBuffer);
  }
  return pvBuffer;
}