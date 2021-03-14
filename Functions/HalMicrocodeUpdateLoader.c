int *__stdcall HalMicrocodeUpdateLoader()
{
  int v5; // ecx
  bool v6; // zf
  int *result; // eax

  _EAX = 1;
  __asm { cpuid }
  v5 = _EAX;
  v6 = _EAX == 1670;
  result = dword_800FE578;
  if ( v6 || (result = dword_800FED78, v5 == 1674) )
    __writemsr(0x79u, (unsigned int)result);
  return result;
}