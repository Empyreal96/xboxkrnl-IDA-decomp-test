int __usercall HalpHardwareInterrupt07@<eax>(char a1@<cf>)
{
  JUMPOUT(a1, HalpHardwareInterrupt08);
  return ((int (*)(void))HalpHardwareInterrupt08)();
}