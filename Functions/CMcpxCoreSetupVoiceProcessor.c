void __thiscall CMcpxCore::SetupVoiceProcessor(CMcpxCore *this)
{
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 0x100; ++i )
    *((_DWORD *)this->m_ctxMemory[3].VirtualAddress + 32 * i + 31) = (unsigned __int16)i;
  MEMORY[0xFE80202C] = this->m_ctxMemory[3].PhysicalAddress;
  MEMORY[0xFE802038] = this->m_ctxMemory[7].PhysicalAddress;
  MEMORY[0xFE80203C] = this->m_ctxMemory[8].PhysicalAddress;
  MEMORY[0xFE802030] = this->m_ctxMemory[5].PhysicalAddress;
  MEMORY[0xFE802034] = this->m_ctxMemory[6].PhysicalAddress;
  MEMORY[0xFE80115C] = this->m_ctxMemory[4].PhysicalAddress;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202A4] = 4095;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202B0] = 4095;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202A0] = 4095;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202A8] = 4095;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202AC] = 4095;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE820804] = 2047;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE820808] = this->m_ctxMemory[11].PhysicalAddress;
  while ( MEMORY[0xFE820010] < 4u )
    ;
  MEMORY[0xFE8202C0] = 151455750;
}