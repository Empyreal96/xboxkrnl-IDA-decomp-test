void __thiscall CAutoIrql::CAutoIrql(CAutoIrql *this)
{
  CIrql::Raise(&this->m_irql);
}