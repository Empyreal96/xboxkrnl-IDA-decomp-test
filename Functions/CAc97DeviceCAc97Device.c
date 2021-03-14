// write access to const memory has been detected, the output may be wrong!
void __thiscall CAc97Device::CAc97Device(CAc97Device *this)
{
  CAc97Device::m_pDevice = this;
}