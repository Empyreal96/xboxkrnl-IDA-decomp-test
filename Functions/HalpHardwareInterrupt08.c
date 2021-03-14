int HalpHardwareInterrupt08()
{
  return ((int (*)(void))HalpHardwareInterrupt09)();
}