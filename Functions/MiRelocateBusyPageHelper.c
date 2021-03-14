unsigned __int32 __stdcall MiRelocateBusyPageHelper(const void *a1, void *a2, unsigned __int32 *a3, unsigned __int32 a4, char a5)
{
  unsigned __int32 result; // eax

  result = a4;
  _disable();
  qmemcpy(a2, a1, 0x1000u);
  *a3 = a4;
  if ( a5 )
  {
    result = __readcr3();
    __writecr3(result);
  }
  else
  {
    __invlpg((void *)((_DWORD)a3 << 10));
  }
  _enable();
  return result;
}