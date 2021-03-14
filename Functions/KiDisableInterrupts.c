unsigned int __stdcall KiDisableInterrupts()
{
  unsigned int v0; // et0
  unsigned int result; // eax

  v0 = __getcallerseflags();
  result = (v0 & 0x200) >> 9;
  _disable();
  return result;
}