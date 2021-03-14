void __stdcall __noreturn KeBugCheckEx(unsigned int BugCheckCode, unsigned int BugCheckParameter1, unsigned int BugCheckParameter2, unsigned int BugCheckParameter3, unsigned int BugCheckParameter4)
{
  KiSetHardwareTrigger();
  KiBugCheckData[0] = BugCheckCode;
  dword_80051124 = BugCheckParameter1;
  dword_80051128 = BugCheckParameter2;
  dword_8005112C = BugCheckParameter3;
  dword_80051130 = BugCheckParameter4;
  if ( unk_8004C824 )
    *(_DWORD *)(unk_8004C824 + 8) |= 4u;
  if ( BugCheckCode != 226 )
  {
    if ( KdDebuggerEnabled )
    {
      DbgPrint(
        (int *)BugCheckParameter3,
        "\n*** Fatal System Error: 0x%08lx\n                       (0x%p,0x%p,0x%p,0x%p)\n\n",
        BugCheckCode,
        BugCheckParameter1,
        BugCheckParameter2,
        BugCheckParameter3,
        BugCheckParameter4);
      if ( !KdDebuggerNotPresent )
        KiBugCheckDebugBreak(3u);
    }
  }
  KiDisableInterrupts();
  KfRaiseIrql(31);
  _EAX = -1;
  _ECX = &KeBugCheckCount;
  __asm { xadd    [ecx], eax }
  if ( _EAX == 1 && !KdDebuggerEnabled )
    KdInitSystem(0);
  KiBugCheckDebugBreak(4u);
}