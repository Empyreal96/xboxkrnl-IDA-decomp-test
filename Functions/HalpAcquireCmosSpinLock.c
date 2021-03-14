void __stdcall HalpAcquireCmosSpinLock()
{
  unsigned int v0; // et0

  v0 = __getcallerseflags();
  _disable();
  HalpHardwareLockFlags = v0;
}