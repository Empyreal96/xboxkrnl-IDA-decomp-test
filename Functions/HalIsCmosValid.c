void __stdcall HalIsCmosValid()
{
  char v0; // zf

  HalpAcquireCmosSpinLock();
  HalpIsCmosSubrangeValid(96, 16);
  if ( v0 )
    HalpIsCmosSubrangeValid(128, 128);
  HalpReleaseCmosSpinLock();
}