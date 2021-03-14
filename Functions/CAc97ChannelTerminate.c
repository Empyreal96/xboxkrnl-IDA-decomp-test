void __usercall CAc97Channel::Terminate(CAc97Channel *this@<ecx>, int *a2@<edi>)
{
  CAc97Channel *v2; // ST04_4
  CAutoIrql __AutoIrql; // [esp+4h] [ebp-8h]

  v2 = this;
  CAutoIrql::CAutoIrql(&__AutoIrql);
  CAc97Channel::Flush(v2, 1);
  PhysicalFree(a2, (void **)&v2->m_pPrdl);
  PhysicalFree(a2, &v2->m_pvSilence);
  v2->m_dwPrdlAddress = 0;
  CAutoIrql::~CAutoIrql(&__AutoIrql);
}