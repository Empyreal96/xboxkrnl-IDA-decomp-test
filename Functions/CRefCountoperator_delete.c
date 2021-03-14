void __cdecl CRefCount::operator delete(void *pvBuffer)
{
  PoolFree(&pvBuffer);
}