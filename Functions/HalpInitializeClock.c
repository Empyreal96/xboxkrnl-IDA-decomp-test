char __stdcall HalpInitializeClock()
{
  unsigned int v0; // et0
  char result; // al

  v0 = __readeflags();
  _disable();
  __outbyte(0x43u, 0x34u);
  __outbyte(0x40u, 0x65u);
  result = 4;
  __outbyte(0x40u, 4u);
  __writeeflags(v0);
  return result;
}