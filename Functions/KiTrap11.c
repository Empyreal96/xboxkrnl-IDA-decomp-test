void __noreturn KiTrap11()
{
  __int16 retaddr_2; // [esp+12h] [ebp+2h]

  retaddr_2 = 0;
  _enable();
  KiSystemFatalException(0x11u);
}