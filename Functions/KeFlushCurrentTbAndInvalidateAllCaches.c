BOOLEAN __stdcall KeFlushCurrentTbAndInvalidateAllCaches()
{
  unsigned __int32 v0; // eax

  v0 = __readcr3();
  __writecr3(v0);
  return KeInvalidateAllCaches();
}