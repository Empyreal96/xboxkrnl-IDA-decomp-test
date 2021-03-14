void __noreturn KiTrap0A()
{
  __int16 retaddr_2; // [esp+12h] [ebp+2h]

  retaddr_2 = 0;
  _enable();
  KiSystemFatalException(0xAu);
}