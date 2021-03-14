void __noreturn KiTrap09()
{
  _enable();
  KiSystemFatalException(9u);
}