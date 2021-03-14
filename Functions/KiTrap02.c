void __noreturn KiTrap02()
{
  unsigned int v0; // et0

  _disable();
  v0 = __readeflags();
  __writeeflags(v0 & 0xFFFFBFFF);
  byte_8005FBDD = -119;
  HalHandleNMI();
}