unsigned int __stdcall DebugPrompt(_STRING *Output, _STRING *Input)
{
  unsigned int result; // eax

  result = 2;
  __asm { int     2Dh; Windows NT - debugging services: eax = type }
  __debugbreak();
  return result;
}