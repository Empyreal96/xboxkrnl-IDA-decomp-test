int __stdcall KiRestoreInterrupts(unsigned __int8 a1)
{
  int result; // eax
  unsigned int v2; // et0

  result = a1 << 9;
  v2 = __readeflags();
  __writeeflags(result | v2);
  return result;
}