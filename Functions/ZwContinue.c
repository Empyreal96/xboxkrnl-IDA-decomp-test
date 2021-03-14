int __stdcall ZwContinue(int a1, int a2)
{
  int result; // eax

  result = a1;
  __asm { int     28h; DOS 2+ internal - KEYBOARD BUSY LOOP }
  return result;
}