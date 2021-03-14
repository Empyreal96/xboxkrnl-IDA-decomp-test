void __stdcall KeEnterKernelDebugger()
{
  KiHardwareTrigger = 1;
  KiDisableInterrupts();
  _EAX = -1;
  _ECX = &KeBugCheckCount;
  __asm { xadd    [ecx], eax }
  if ( _EAX == 1 && !KdDebuggerEnabled )
    KdInitSystem(0);
  KiBugCheckDebugBreak(5u);
}