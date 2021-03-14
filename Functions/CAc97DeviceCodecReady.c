int CAc97Device::CodecReady()
{
  unsigned int v0; // eax
  int fReady; // [esp+4h] [ebp-Ch]
  unsigned int dwValue; // [esp+8h] [ebp-8h]
  unsigned int dwAttempts; // [esp+Ch] [ebp-4h]

  fReady = 1;
  dwAttempts = 1000;
  dwValue = CAc97Device::PeekAciRegister32(0x2Cu);
  if ( !(dwValue & 2) )
  {
    dwValue |= 2u;
    CAc97Device::PokeAciRegister32(0x2Cu, dwValue);
  }
  if ( dwValue & 8 )
    CAc97Device::PokeAciRegister32(0x2Cu, dwValue & 0xFFFFFFF3);
  while ( !(CAc97Device::PeekAciRegister32(0x30u) & 0x100) )
  {
    v0 = dwAttempts--;
    if ( !v0 )
      return 0;
    CAc97Device::WaitRegisterRetry();
  }
  return fReady;
}