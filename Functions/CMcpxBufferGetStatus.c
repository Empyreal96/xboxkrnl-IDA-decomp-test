int __thiscall CMcpxBuffer::GetStatus(CMcpxBuffer *this, unsigned int *pdwStatus)
{
  CMcpxBuffer *thisa; // [esp+0h] [ebp-10h]
  CAutoIrql __AutoIrql; // [esp+8h] [ebp-8h]

  thisa = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  *pdwStatus = 0;
  if ( thisa->m_dwStatus & 1 )
  {
    if ( thisa->m_dwStatus & 0x10000002 )
    {
      *pdwStatus |= 1u;
      if ( thisa->m_dwStatus & 0x10 )
        *pdwStatus |= 4u;
    }
  }
  CAutoIrql::~CAutoIrql(&__AutoIrql);
  return 0;
}