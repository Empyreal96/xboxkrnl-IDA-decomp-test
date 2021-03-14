void __thiscall CIrql::Lower(CIrql *this)
{
  if ( this->m_fRaised )
    KfLowerIrql(this->m_irql);
}