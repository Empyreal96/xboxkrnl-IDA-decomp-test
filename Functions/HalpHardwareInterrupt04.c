int HalpHardwareInterrupt04()
{
  return ((int (*)(void))HalpHardwareInterrupt05)();
}