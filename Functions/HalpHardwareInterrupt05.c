int HalpHardwareInterrupt05()
{
  return ((int (*)(void))HalpHardwareInterrupt06)();
}