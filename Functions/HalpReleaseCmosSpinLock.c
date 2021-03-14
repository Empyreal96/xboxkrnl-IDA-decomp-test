void __stdcall HalpReleaseCmosSpinLock()
{
  __writeeflags(HalpHardwareLockFlags);
}