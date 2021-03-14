void __thiscall CAc97Channel::Flush(CAc97Channel *this, int fResetPosition)
{
  CAc97Channel *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-Ch]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CAc97Channel::Pause(thisa);
  CAc97Channel::Reset(thisa);
  CAc97Channel::SetPrdIndeces(thisa, 0, 0, 1, 1);
  thisa->m_dwFlags &= 0xFFFFFFFD;
  if ( fResetPosition )
  {
    thisa->m_dwPosition = 0;
    thisa->m_dwLastPosition = 0;
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}