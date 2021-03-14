unsigned __int64 __stdcall WRMSR(unsigned int a1, unsigned __int64 a2)
{
  unsigned __int64 result; // rax

  result = a2;
  __writemsr(a1, a2);
  return result;
}