void __thiscall CAc97Channel::SetPrdIndeces(CAc97Channel *this, char bCurrentPrd, char bPrdCount, int fApplyCurrent, int fApplyLast)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]
  char bLastPrd; // [esp+Fh] [ebp-1h]
  char bCurrentPrda; // [esp+18h] [ebp+8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  if ( bPrdCount )
  {
    bLastPrd = bCurrentPrd + bPrdCount - 1;
    if ( thisa->m_dwFlags & 1 )
    {
      bCurrentPrda = bCurrentPrd & 0x1F;
      bLastPrd &= 0x1Fu;
    }
    else
    {
      bCurrentPrda = (unsigned __int8)bCurrentPrd % (signed __int16)(unsigned __int8)bPrdCount;
      bLastPrd = (unsigned __int8)bLastPrd % (signed __int16)(unsigned __int8)bPrdCount;
    }
  }
  else
  {
    bCurrentPrda = 0;
    bLastPrd = 0;
  }
  if ( fApplyCurrent )
    CAc97Channel::PokeAciRegister8(thisa, 4u, bCurrentPrda);
  if ( fApplyLast )
    CAc97Channel::PokeAciRegister8(thisa, 5u, bLastPrd);
  thisa->m_bCurrentPrd = bCurrentPrda;
  thisa->m_bPrdCount = bPrdCount;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}