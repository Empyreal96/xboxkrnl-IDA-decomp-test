void __stdcall __noreturn KeBugCheck(unsigned int BugCheckCode)
{
  KeBugCheckEx(BugCheckCode, 0, 0, 0, 0);
}