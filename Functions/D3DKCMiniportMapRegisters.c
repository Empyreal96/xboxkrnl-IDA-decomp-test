int __thiscall D3DK::CMiniport::MapRegisters(D3DK::CMiniport *this)
{
  this->m_RegisterBase = (void *)-50331648;
  MEMORY[0xFD001804] |= 4u;
  MEMORY[0xFD600140] = 0;
  MEMORY[0xFD009140] = 0;
  return 1;
}