int __stdcall CAc97Device::AcquireCodecSemaphore()
{
  unsigned int v0; // ecx
  int fAcquired; // [esp+0h] [ebp-8h]
  unsigned int dwAttempts; // [esp+4h] [ebp-4h]

  dwAttempts = 1000;
  fAcquired = 1;
  while ( CAc97Device::PeekAciRegister8(0x34u) & 1 )
  {
    v0 = dwAttempts--;
    if ( !v0 )
      return 0;
    CAc97Device::WaitRegisterRetry();
  }
  return fAcquired;
}