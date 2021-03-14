unsigned int __thiscall D3DK::CMiniport::ReserveInstMem(D3DK::CMiniport *this, unsigned int blocks)
{
  D3DK::CMiniport *v2; // esi
  unsigned int result; // eax

  v2 = this;
  if ( blocks > 1280 - this->m_FreeInstAddr )
    D3DK::DXGRIP((int *)blocks, "Assertion failure: %s", "blocks <= (INSTANCE_MEM_MAXSIZE >> 4) - m_FreeInstAddr");
  result = v2->m_FreeInstAddr;
  v2->m_FreeInstAddr = result + blocks;
  return result;
}