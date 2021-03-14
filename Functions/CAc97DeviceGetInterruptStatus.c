unsigned int CAc97Device::GetInterruptStatus()
{
  return CAc97Device::PeekAciRegister32(0x30u) & 0x51;
}