// write access to const memory has been detected, the output may be wrong!
void __stdcall MemFree(void *pv)
{
  if ( gcMemAllocs <= 0 )
    __debugbreak();
  --gcMemAllocs;
  ExFreePool(pv);
}