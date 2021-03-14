void __thiscall CIrql::Raise(CIrql *this)
{
  CIrql *thisa; // [esp+0h] [ebp-4h]

  thisa = this;
  this->m_fRaised = (signed int)(unsigned __int8)KeGetCurrentIrql() < 2;
  if ( thisa->m_fRaised )
    thisa->m_irql = KfRaiseIrql(2);
}