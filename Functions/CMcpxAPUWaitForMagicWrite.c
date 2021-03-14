// write access to const memory has been detected, the output may be wrong!
void __thiscall CMcpxAPU::WaitForMagicWrite(CMcpxAPU *this)
{
  CMcpxAPU *v1; // ST04_4
  unsigned int v2; // ecx
  unsigned int dwTimeout; // [esp+4h] [ebp-Ch]
  volatile unsigned int *pdwMagicWrite; // [esp+8h] [ebp-8h]

  v1 = this;
  dwTimeout = 100;
  ++dwMagicWriteValue;
  pdwMagicWrite = (volatile unsigned int *)this->m_ctxMemory[2].VirtualAddress;
  *pdwMagicWrite = ~dwMagicWriteValue;
  CMcpxCore::SetPrivLockState(1);
  MEMORY[0xFE801324] = v1->m_ctxMemory[2].PhysicalAddress;
  MEMORY[0xFE801334] = dwMagicWriteValue;
  CMcpxCore::SetPrivLockState(0);
  while ( *pdwMagicWrite != dwMagicWriteValue )
  {
    v2 = dwTimeout--;
    if ( !v2 )
      break;
    KeStallExecutionProcessor(1u);
  }
}