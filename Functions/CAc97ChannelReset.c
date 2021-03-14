void __thiscall CAc97Channel::Reset(CAc97Channel *this)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-Ch]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CAc97Channel::PokeAciRegister8(thisa, 0xBu, 2);
  while ( CAc97Channel::PeekAciRegister8(thisa, 0xBu) & 2 )
    ;
  CAc97Channel::PokeAciRegister32(thisa, 0, thisa->m_dwPrdlAddress);
  if ( thisa->m_nChannelType == 1 )
    CAc97Channel::PokeAciRegister32(thisa, 0xCu, thisa->m_dwMode);
  CAc97Channel::SetPrdIndeces(thisa, thisa->m_bCurrentPrd, thisa->m_bPrdCount, 1, 1);
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}