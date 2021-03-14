void __stdcall __noreturn HalHandleNMI()
{
  if ( !KdDebuggerNotPresent )
  {
    if ( KdDebuggerEnabled )
      KeEnterKernelDebugger();
  }
  HalHaltSystem();
}