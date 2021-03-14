void __stdcall HalMarkCmosValid()
{
  HalpAcquireCmosSpinLock();
  HalpMarkCmosSubrangeValid(96, 16);
  HalpMarkCmosSubrangeValid(128, 128);
  HalpReleaseCmosSpinLock();
}