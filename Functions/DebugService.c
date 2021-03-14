unsigned int __stdcall DebugService(unsigned int ServiceClass, void *Arg1, void *Arg2)
{
  unsigned int result; // eax

  result = ServiceClass;
  __asm { int     2Dh; Windows NT - debugging services: eax = type }
  __debugbreak();
  return result;
}