int CAc97Device::PowerUp()
{
  int hr; // [esp+4h] [ebp-4h]

  hr = 0;
  if ( !CAc97Device::PokeAc97Register(AC97REG_POWERDOWN, 0) )
    hr = -2147467259;
  return hr;
}