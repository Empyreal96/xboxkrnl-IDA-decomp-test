int __usercall HalpHardwareInterrupt06@<eax>(char a1@<cf>)
{
  JUMPOUT(!a1, HalpHardwareInterrupt07);
  return ((int (*)(void))HalpHardwareInterrupt07)();
}