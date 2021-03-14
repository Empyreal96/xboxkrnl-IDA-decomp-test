void __thiscall CAc97Channel::SetMode(CAc97Channel *this, unsigned int dwMode)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( thisa->m_nChannelType == 1 )
  {
    thisa->m_dwMode = dwMode;
    CAc97Channel::PokeAciRegister32(thisa, 0xCu, thisa->m_dwMode);
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}