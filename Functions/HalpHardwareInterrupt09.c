int HalpHardwareInterrupt09()
{
  __asm { ffree   st(3); (emulator call) }
  return ((int (*)(void))HalpHardwareInterrupt10)();
}