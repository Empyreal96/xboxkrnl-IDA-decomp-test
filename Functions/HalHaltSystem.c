void __stdcall __noreturn HalHaltSystem()
{
  _disable();
  __halt();
  JUMPOUT(loc_8001D562);
}