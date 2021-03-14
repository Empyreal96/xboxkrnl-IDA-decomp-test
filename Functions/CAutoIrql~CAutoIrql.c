void __thiscall CAutoIrql::~CAutoIrql(CAutoIrql *this)
{
  CIrql::Lower(&this->m_irql);
}