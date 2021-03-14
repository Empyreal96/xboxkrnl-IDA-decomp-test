int __stdcall CAc97Device::PokeAc97Register(AC97REGISTER reg, unsigned __int16 wValue)
{
  int fSuccess; // [esp+0h] [ebp-4h]

  fSuccess = CAc97Device::AcquireCodecSemaphore();
  if ( fSuccess )
    CAc97Device::PokeRegister16(2 * reg - 20971520, wValue);
  return fSuccess;
}