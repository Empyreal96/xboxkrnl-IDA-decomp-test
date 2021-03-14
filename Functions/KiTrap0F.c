void __noreturn KiTrap0F()
{
  _enable();
  KiSystemFatalException(0xFu);
}