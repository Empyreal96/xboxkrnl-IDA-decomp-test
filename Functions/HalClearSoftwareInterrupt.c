int __fastcall HalClearSoftwareInterrupt(char a1)
{
  int result; // eax

  result = ~(1 << a1);
  HalpIRR &= result;
  return result;
}