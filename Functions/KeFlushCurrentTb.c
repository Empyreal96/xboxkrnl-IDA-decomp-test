unsigned __int32 __stdcall KeFlushCurrentTb()
{
  unsigned __int32 result; // eax

  result = __readcr3();
  __writecr3(result);
  return result;
}