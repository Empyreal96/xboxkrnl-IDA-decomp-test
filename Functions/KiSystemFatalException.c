void __usercall __noreturn KiSystemFatalException(unsigned int a1@<eax>)
{
  KeBugCheckEx(0x7Fu, a1, 0, 0, 0);
}