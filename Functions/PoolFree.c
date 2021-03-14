// write access to const memory has been detected, the output may be wrong!
void __stdcall PoolFree(void **ppvBuffer)
{
  if ( *ppvBuffer )
  {
    g_dwDirectSoundPoolMemoryUsage -= ExQueryPoolBlockSize(*ppvBuffer);
    ExFreePool(*ppvBuffer);
    *ppvBuffer = 0;
  }
}