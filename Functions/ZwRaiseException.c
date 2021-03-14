void __stdcall __noreturn ZwRaiseException(int a1, unsigned int a2, int a3)
{
  __fastfail(a2);
}