void __thiscall CAc97Channel::SetPosition(CAc97Channel *this, unsigned int dwPosition)
{
  CAc97Channel *v2; // ST08_4

  v2 = this;
  CAc97Channel::PokeAciRegister16(
    this,
    8u,
    *((_WORD *)&this->m_pPrdl[(unsigned __int8)this->m_bCurrentPrd] + 2)
  - dwPosition / ((signed int)CAc97Device::m_wfxFormat.wBitsPerSample >> 3));
  v2->m_dwLastPosition = 0;
}