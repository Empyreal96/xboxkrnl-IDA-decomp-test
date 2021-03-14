void __stdcall __noreturn IdexBugCheckWorker(unsigned int FileAndLineCode, unsigned int BugCheckParameter1)
{
  KeBugCheckEx(0x2Cu, FileAndLineCode, BugCheckParameter1, 0, 0);
}