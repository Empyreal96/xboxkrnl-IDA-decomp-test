void __stdcall FscInvalidateDevice(_FSCACHE_EXTENSION *CacheExtension)
{
  FscInvalidateBlocks(CacheExtension, 0, 0xFFFFFFFF);
}