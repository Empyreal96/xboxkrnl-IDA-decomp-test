// write access to const memory has been detected, the output may be wrong!
char *__userpurge PoolAlloc@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, unsigned int cbBuffer, const void *pvSource)
{
  int *pvBuffer; // [esp+0h] [ebp-4h]

  pvBuffer = ExAllocatePoolWithTag(a1, a2, a3, cbBuffer, 0x444E5344u);
  if ( pvBuffer )
  {
    if ( pvSource )
      memcpy((char *)pvBuffer, (char *)pvSource, cbBuffer);
    else
      memset(pvBuffer, 0, cbBuffer);
    g_dwDirectSoundPoolMemoryUsage += ExQueryPoolBlockSize(pvBuffer);
  }
  return (char *)pvBuffer;
}