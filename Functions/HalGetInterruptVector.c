unsigned int __stdcall HalGetInterruptVector(unsigned int BusInterruptLevel, char *Irql)
{
  unsigned int result; // eax

  result = BusInterruptLevel + 48;
  if ( BusInterruptLevel >= 0xFFFFFFD0 || result > 0x4A )
    return 0;
  *Irql = 74 - result;
  return result;
}