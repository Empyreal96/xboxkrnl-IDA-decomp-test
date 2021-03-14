int __usercall CMcpxAPU::ServiceApuInterrupt@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>)
{
  CMcpxAPU *v2; // edx
  int v3; // ecx
  CMcpxAPU *thisa; // [esp+0h] [ebp-10h]
  unsigned int rInterruptStatus; // [esp+4h] [ebp-Ch]
  int fServiced; // [esp+Ch] [ebp-4h]

  thisa = this;
  rInterruptStatus = MEMORY[0xFE801000];
  fServiced = (MEMORY[0xFE801000] & 1) != 0;
  if ( MEMORY[0xFE801000] & 1 )
  {
    v2 = this;
    this->m_arInterruptStatus[0].uValue |= MEMORY[0xFE801000];
    if ( (rInterruptStatus >> 4) & 1 )
      CMcpxAPU::HandleFETrap(this);
    v3 = (rInterruptStatus >> 3) & 1;
    if ( v3 || (v2 = (CMcpxAPU *)((rInterruptStatus >> 6) & 1)) != 0 )
      KeInsertQueueDpc((int)v2, v3, a2, &thisa->m_dpcInterrupt, 0, 0);
  }
  return fServiced;
}